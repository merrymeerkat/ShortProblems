(*Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.*)


let rec two_sum4 arr int =
  match arr with
  |h::t ->
    (match t with
     |t'::t''->
      (match t'' with
       |y::y' ->  if (h + t' == int) then Some(h, t')
                  else two_sum4 (h::t'') int
       |[] -> if (h + t' == int) then Some(h, t')
              else (two_sum4 t int))
    |[]-> None)
  |[]-> None;;
