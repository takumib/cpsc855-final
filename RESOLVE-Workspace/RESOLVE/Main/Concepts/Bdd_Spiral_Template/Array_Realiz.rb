Realization Array_Realiz for Bdd_Spiral_Template;
	
	Facility Ceramic_Array_Fac is 
		Static_Array_Template(Label, 1, Max_Length)
		externally realized by Std_Array_Realiz;
		
	Type Spiral_Pos is represented by Record
			Labl : Ceramic_Array_Fac.Static_Array;
			Length, Curr : Integer;
		end;
		convention 0 <= P.Curr <= P.Length and 
				   P.Length <= Max_Length;
		correspondence true;
	end;
	
	Proc Lengthen(upd P : Spiral_Pos; alt New_Lab : Label);
		Ceramic_Array_Fac.Swap_Entry(P.Labl, New_Lab, P.Length);
		P.Length := P.Length + 1;
	end Lengthen;
	
end Array_Realiz;	