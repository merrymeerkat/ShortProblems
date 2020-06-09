(* 28. Implement strStr(). *)

(* Level: Easy *)

(* Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack. *)


(* given a haystack and a needle, checks whether the first element of the needle is present in the haystack. If so, returns the index of this element in the haystack. Else returns -1 *)
let check_first hst ndl =
   let rec helper hst ndl counter =         
  match counter with
  |(-1) -> ~-1
  |_ -> if (String.get hst counter) == (String.get ndl 0)
        then counter
        else helper hst ndl (counter - 1)
    in helper hst ndl (String.length hst - 1);;
