(*35. Search Insert Position *)

(*Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.*)

(*Level: Easy *)

let sip arr target =
  let rec sip_helper arr target acc =
    match arr with
    |h::t -> if h >= target then acc
             else sip_helper t target (acc + 1)
    |[] -> acc
  in sip_helper arr target 0;;

(* tests *)
sip [1;3;5;6] 5;;
sip [1;3;5;6] 2;;
sip [1;3;5;6] 7;;
sip [1;3;5;6] 0;;
sip [1;3;99;102] 101;;
sip [-1;5;6] 5;;
