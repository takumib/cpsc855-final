Precis Total_Preordering_Theory;
	uses String_Theory;

	Definition Is_Total_Preordering(f : ((D : MType) * D) -> B) : B;

	Definition Is_Conformal_With(f : (Entity * Entity) -> B, S : SStr) : B;

	---------------------------------------------------------------
	-- Conformity Theorems                                       --
	---------------------------------------------------------------
	Theorem Empty_String_Conformal:
		For all f : (Entity * Entity) -> B,
			Is_Conformal_With(f, Empty_String);

	Theorem Conformal_String_Extension:
		For all f : (Entity * Entity) -> B,
		For all S : SStr,
		For all e : Entity,
			Is_Conformal_With(f, S) and
			Is_Universally_Related(S, <e>, f)
				implies Is_Conformal_With(f, S o <e>);

	Theorem Total_Preordering_Symmetric:
		For all f : (Entity * Entity) -> B,
		For all e1, e2 : Entity,
			Is_Total_Preordering(f) and
			f(e1, e2) = not(f(e2, e1));
end;




