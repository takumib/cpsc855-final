Realization Clean_Array_Realiz for Stack_Template;

    (* Note: Under Construction! *)

    Definition Array_is_Clean(SR: Stack): B =
        For all i: Integer, if SR.Top < i <= Max_Depth
        then Entry.Is_Initial(SR.Contents(i));

    Type Stack is represented by Record
            Contents: Array 1..Max_Depth of Entry;
            Top: Integer;
        end;
        convention
            0 <= S.Top <= Max_Depth and Array_is_Clean(S);
        correspondence
            Conc.S = Reverse(Concatenation i: Z
            where 1 <= i <= S.Top, <S.Contents(i)>);
	end;

    Procedure Push(alters E: Entry; updates S: Stack);
        S.Top := S.Top + 1;
        E :=: S.Contents[S.Top];
    end Push;

    Procedure Pop(replaces R: Entry; updates S: Stack);
        Var Fresh_Val: Entry;

        R :=: S.Contents[S.Top];
        S.Contents[S.Top] :=: Fresh_Val;
        S.Top := S.Top - 1; 
    end Pop;

    Procedure Depth(preserves S: Stack): Integer;
        Depth := S.Top;
    end Depth;

    Procedure Rem_Capacity(preserves S: Stack): Integer;
        Rem_Capacity := Max_Depth - S.Top;
    end Rem_Capacity;
	
    Operation Clear_Entry(clears E: Entry);
    Procedure
		Var Temp: Entry;
		E :=: Temp;
    end Clear_Entry;
	
    Procedure Clear(clears S: Stack);
      While (S.Top > 0)  
		changing S;
      	maintaining Array_is_Clean(S);
      	decreasing S.Top;
      do
        Clear_Entry(S.Contents[S.Top]);
        S.Top := S.Top - 1;
      end;
    end Clear;

end Clean_Array_Realiz;