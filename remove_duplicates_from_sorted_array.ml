(* 26. Remove Duplicates from Sorted Array *)

(* Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory. *)

(* Level: Easy *)

(* Main function: Here we iterate over the array, keeping track of the last element seen. If the element we are currently looking at equals the last seen, we simply move to the next one. If it is a new element, we increase the length counter. Output is the length of the duplicate-free list *)
let remove_dup array =
  let rec helper array last_seen length =
    match array with
      [] -> length
     |h::t -> if h == last_seen
              then helper t h length
              else helper t h (length + 1)
  in helper array (-1) 0;;

(* Tests *)

remove_dup [1;1;2];;

remove_dup [0;0;1;1;1;2;2;3;3;4];;

remove_dup [2;2;2];;

remove_dup [1];;
