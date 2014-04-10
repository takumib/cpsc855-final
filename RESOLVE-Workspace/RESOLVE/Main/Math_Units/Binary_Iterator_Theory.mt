Precis Binary_Iterator_Theory;
		uses Integer_Theory, String_Theory, Conditional_Function_Theory;

	Definition Iterative_Apply(Start : (R : MType), 
		Value_Function : Z -> (V : MType), 
		Value_Count : Z, Step : (R * V) -> R) : R;

	Definition Concatenate(Value_Function : Z -> (V : MType), Value_Count : Z) : 
		Str(V);

	Theorem Concatenation_Length:
		For all f : Z -> Entity,
		For all i : Z,
			|Concatenate(f, i)| = i;

	Theorem Zero_Length_Concatenate:
		For all f : Z -> Entity,
			Concatenate(f, 0) = Empty_String;

	Theorem End_Changed:
		For all f : Z -> Entity,
		For all e : Entity,
		For all i : Z,
			Concatenate(
				lambda (j : Z).({{
					e if j = i;
					f(j) otherwise;
				}}),
				i)
			= Concatenate(f, i - 1) o <e>;

	Theorem End_Excluded:
		For all f : Z -> Entity,
		For all e : Entity,
		For all i : Z,
			Concatenate(
				lambda (j : Z).({{
					e if j = i;
					f(j) otherwise;
				}}),
				i - 1)
			= Concatenate(f, i - 1);

	Theorem Inductive_Reverse_1:
		For all f : Z -> Entity,
		For all i : Z,
		Reverse(Concatenate(f, i)) = 
			<f(i)> o Reverse(Concatenate(f, i - 1));
end;
