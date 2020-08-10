
(* 217. Contains duplicate *)

(* Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct. *)

(* Level: Easy *)

let contains_duplicate list =
  let length = List.length list in
  let rec helper list curr_list curr_element start counter =
    match list with
    |h :: t ->
      if start then
        helper list t h false counter
      else
        (if h == curr_element then true else helper list t curr_element false counter)
    |[] -> if counter == length then false
           else helper (List.tl list) (List.tl list) (-1) true (counter + 1)
  in helper list list (-1) true 0;;
