(*
 * This softare is released under the new BSD 2006 license.
 * 
 * Note the new BSD license is equivalent to the MIT License, except for the
 * no-endorsement final clause.
 * 
 * Copyright (c) 2007, Clemson University
 * 
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer. 
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution. 
 *   * Neither the name of the Clemson University nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission. 
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * This sofware has been developed by past and present members of the
 * Reusable Sofware Research Groups (RSRG) at Clemson University and
 * The Ohio State University.
 *)

Realization Circular_Array_Realiz for Queue_Template;
    
    (* Note: Under Construction! *)
	
    Type Queue = Record
            Contents: Array 0..Max_Length - 1 of Entry;
            Front, Length: Integer;
        end;
        convention
            0 <= Q.Front < Max_Length and
                0 <= Q.Length <= Max_Length;
        correspondence
            Conc.Q = (Concatenation i: Z
            where Q.Front <= i <= Q.Front + Q.Length - 1,
            {<Q.Contents(i mod Max_Length)>});
	end;
       
    Procedure Enqueue(alters E: Entry; updates Q: Queue);
        Q.Contents[(Q.Front + Q.Length) mod Max_Length] :=: E;
        Q.Length := Q.Length + 1;
    end Enqueue;

    Procedure Dequeue(replaces R: Entry; updates Q: Queue);
        Q.Contents[Q.Front] :=: R;
        Q.Front := (Q.Front + 1) mod Max_Length;
        Q.Length := Q.Length -1;
    end Dequeue;

    Procedure Swap_First_Entry(updates E: Entry; updates Q: Queue);
      Q.Contents[Q.Front] :=: E;
    end Swap_First_Entry;

    Procedure Length(restores Q: Queue): Integer;
        Length := Q.Length;
    end Length;

    Procedure Rem_Capacity(restores Q: Queue): Integer;
        Rem_Capacity := Max_Length - Q.Length;
    end Rem_Capacity;

    Procedure Clear(clears Q: Queue);
       Q.Front := 0; Q.Length := 0;
    end Clear;

end Circular_Array_Realiz;


