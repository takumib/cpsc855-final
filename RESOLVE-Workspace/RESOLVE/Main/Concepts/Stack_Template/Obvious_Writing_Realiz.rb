Realization Obvious_Writing_Realiz (Operation Write_Entry(evaluates E: Entry);)
		for Writing_Capability of Stack_Template;

	Procedure Write(clears S: Stack);
		Var Next_Entry: Entry;

		While (Depth(S) /= 0)
			changing S, Next_Entry;
			maintaining true;
			decreasing |S|;
		do
			Pop(Next_Entry, S);
			Write_Entry(Next_Entry);
		end;
	end Write;
end Obvious_Writing_Realiz;