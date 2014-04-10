Realization Inject_Front_Realiz for Inject_Front_Capability of Queue_Template;

	Procedure Inject_at_Front(alters E: Entry; updates Q: Queue);
		Var T: Queue;
		
		Enqueue (E, T);
		While ( Is_Not_Zero(Length(Q)) )
			changing Q,T,E;
			maintaining T o Q = <#E> o #Q;
			decreasing |Q|;
		do
			Dequeue(E,Q);
			Enqueue(E,T);
		end;
		Q :=: T;
	end Inject_at_Front;
end Inject_Front_Realiz;