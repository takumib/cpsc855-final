Realization Remove_Last_Realiz for Remove_Last_Capability of Queue_Template;
    Procedure Remove_Last(updates Q: Queue; replaces E: Entry);
        Var T: Queue;

	  Dequeue (E, Q);
        While (Length(Q) /= 0)
          changing Q,T,E;
          maintaining #Q = T o <E> o Q;
          decreasing |Q|;
        do
          Enqueue(E,T);
          Dequeue(E,Q);
        end;
	  Q :=: T;
    end Remove_Last;
end Remove_Last_Realiz;