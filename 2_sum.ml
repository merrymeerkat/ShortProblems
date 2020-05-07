(*Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.*)

let rec drop_first l =
  match l with
    h::t-> t
  |[]->[];;

let rec two_sixm arr int =
  match arr with
  |h::t ->
    (match t with
    |t'::t''->
      if (h + t' == int) then Some(h, t') else two_sixm (h::t'') int
    |[]-> None)
  |[]-> None;;

let another_one arr int =
  if (two_sixm arr int != None) then
    two_sixm arr int
 else two_sixm (drop_one arr) int;;


  
