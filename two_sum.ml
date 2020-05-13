(*Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Level: Easy*)

(* transforms int list into tuple list. The first element of each tuple is an index, the second is the original int. e.g. [3;4;5] becomes [(0,2);(1,4);(2,5)]*)
let tuplefy l =
  let rec helper l counter =
    match l with
  |h::t -> (counter, h) :: helper t (counter + 1)
  |[] -> []
  in helper l 0;;

(*Checks whether the first int of a tuple list, when summed with any of the remaining ints in the tuple list, adds up to the target int. Returns Some(index first int, index second int) if they add up, None otherwise*)
let rec helper_sum arr target_int =
  match arr with
  |(i,h)::t ->
    (match t with
    |(i',t')::t''->
      if (h + t' == target_int) then Some(i, i') else helper_sum ((i,h)::t'') target_int
    |[]-> None)
  |[]-> None;;

(*runs helper_sum for each tuple in the tuple list. If the head tuple returns None, we drop the head tuple and execute helper_sum again, and so on. Function stops when Some(index, index) is returned, or when we reach an empty tuple list (meaning that none of the numbers add up to the target int, in which case we return None*)
let rec two_sum arr target_int =
  if (helper_sum arr tagert_int != None) then
    helper_sum arr target_int
  else two_sum (drop_first arr) target_int;;

(*This ensures the user input (an int list) will be passed as a tuple list with indexes *)
let two_sum arr target_int = two_sum (tuplefy arr) target_int;;

two_sum [1;2;3] 5;;
two_sum [2;7;11;15] 9;;
two_sum [0;7;8;20] 27;;
two_sum [1;2;3;4;5;6;7;8;9] 17;;

  
