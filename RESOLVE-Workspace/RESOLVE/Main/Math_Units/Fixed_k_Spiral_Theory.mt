Precis Fixed_k_Spiral_Theory;
    uses Integer_Theory, Boolean_Theory;
	
	Definition Sp_Loc : SSet;
	
	Definition SS : Sp_Loc -> Sp_Loc;
	Definition RS : Sp_Loc -> Sp_Loc;
				
	--Spiral center distance. That is, how many hops is p from the center?  
	Definition SCD(p : Sp_Loc) : N;
	
	Definition Inward_Location : Sp_Loc -> Powerset(Sp_Loc);

	Definition Spiral_Center : Sp_Loc;
			
	
end Fixed_k_Spiral_Theory;
