(* 1480. Running Sum of 1d Array *)

(* Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums. *)

(* Level: easy *)

(* this function takes as input the original list, and, with the
   help of an accumulator, inserts sums into a new list accordingly. 
     We do not modify the pre-existing list because OCaml lists are immutable *)
let running_sum lst =
  let rec helper lst acc nlst =
    match lst with 
      [] -> List.rev nlst
    |h::t -> helper t (acc + h) ((acc + h) :: nlst)
  in helper lst 0 [];;

(* tests *)
running_sum [1;2;3;4];;
running_sum [1;1;1;1;1];;
running_sum[3;1;2;10;1];;
