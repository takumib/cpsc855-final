Realization Iterative_Append_Realiz for Append_Capability of Queue_Template;
    Procedure Append(updates P: Queue; clears Q: Queue);
        Var E: Entry;
        While ( Is_Not_Zero(Length(Q)) )
          maintaining (P o Q = #P o #Q);
          decreasing |Q|;
        do
          Dequeue(E,Q);
          Enqueue(E,P);
        end;
    end Append;
end Iterative_Append_Realiz;