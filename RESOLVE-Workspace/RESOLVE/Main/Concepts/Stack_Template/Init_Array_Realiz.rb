Realization Init_Array_Realiz for Stack_Template;

    (* Note: Under Construction! *)

    Type Stack is represented by Record
            Contents: Array 1..Max_Depth of Entry;
            Top: Integer;
        end;
        convention
            1 <= S.Top <= Max_Depth+1;
        correspondence
            Conc.S = Reverse(Concatenation i: Integer
            where 1 <= i <= S.Top-1, <S.Contents(i)>);
        initialization
           S.Top := 1;
        end;
	end;
	
    Procedure Push(alters E: Entry; updates S: Stack);
        E :=: S.Contents[S.Top];
        S.Top := S.Top + 1;
    end Push;

    Procedure Pop(replaces R: Entry; updates S: Stack); 
        S.Top := S.Top - 1;
        R :=: S.Contents[S.Top];
    end Pop;

    Procedure Depth(preserves S: Stack): Integer;
        Depth := S.Top-1;
    end Depth;

    Procedure Rem_Capacity(preserves S: Stack): Integer;
        Rem_Capacity := Max_Depth + 1 - S.Top;
    end Rem_Capacity;

    Procedure Clear(clears S: Stack);
        S.Top := 1;
    end Clear;

end Init_Array_Realiz;