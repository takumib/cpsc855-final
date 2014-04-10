Realization Recursive_Inverting_Realiz for Inverting_Capability of Queue_Template;
    Recursive Procedure Invert(updates Q: Queue);
        decreasing |Q|;

        Var E: Entry;
        If ( Is_Not_Zero(Length(Q)) ) then
            Dequeue(E, Q);
            Invert(Q);
            Enqueue(E, Q);
        end;
    end Invert;
end Recursive_Inverting_Realiz;