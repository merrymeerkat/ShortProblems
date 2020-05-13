(*Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Level: Easy*)

let tuplefy l =
  let rec helper l counter =
    match l with
  |h::t -> (counter, h) :: helper t (counter + 1)
  |[] -> []
  in helper l 0;;

let rec helper_sum arr int =
  match arr with
  |(i,h)::t ->
    (match t with
    |(i',t')::t''->
      if (h + t' == int) then Some(i, i') else helper_sum ((i,h)::t'') int
    |[]-> None)
  |[]-> None;;

let rec two_sum arr int =
  if (helper_sum arr int != None) then
    helper_sum arr int
  else two_sum (drop_first arr) int;;

let two_sum arr int = another_one (tuplefy arr) int;;

two_sum [1;2;3] 5;;
two_sum [2;7;11;15] 9;;
two_sum [0;7;8;20] 27;;
two_sum [1;2;3;4;5;6;7;8;9] 17;;

  
