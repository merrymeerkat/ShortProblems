(*11. Container With Most Water *)

(*Level: Medium *)

(*Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
Note: You may not slant the container and n is at least 2.*)

(* transforms int list into tuple list. The first element of each tuple is an index, the second is the original int*)
let tuplefy l =
  let rec helper l counter =
    match l with
  |h::t -> (counter, h) :: helper t (counter + 1)
  |[] -> []
  in helper l 0;;

(*Helper function. Given an indexed list (e.g. [(0,3);(1,3);(2,7)], it returns the area of the largest possible container formed between the first tuple of the list and any other tuple. *)
let largest_with_first l =
  let rec helper l acc =
    match l with
    |(i, h) :: t ->
      (match t with
      |(i', h') :: t' -> (if ((i' - i) * (min h h')) > acc
                        then (helper ((i, h) :: t') ((i' - i) * (min h h')))
                           else helper ((i, h) :: t') acc)
      |[] -> acc)
    |[] -> acc
  in helper l 0;;

largest_with_first [(0,2);(1,2);(2,3)];;

(* Our final function: given an int list, returns the area of the largest possible container *)
(* This works by transforming the input list into a tuple list (in order to keep track of the order of elements) and iterating through the tuple list with the largest_with_first function. This means that we will compute the area of the largest container formed with the first element of the list, then discard this element and do the same for the new first element, and so on, until we reach an empty list. An accumulator variable stores the highest area seen so far, and the accumulator is returned once the list has been searched through completely. *)
let largest l =
  let rec helper l acc =
    let first_container = (largest_with_first l) in
    (match l with
      (i,h)::t-> if first_container > acc then
                   helper t first_container
                 else helper t acc
    |[] -> acc)   
  in helper (tuplefy l) 0;;

(* tests *)
largest [1;8;6;2;5;4;8;3;7];;
largest [0;0];;
largest [1;2;3];;
largest [44;44];;


                                    
