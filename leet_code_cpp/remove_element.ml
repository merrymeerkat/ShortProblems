(* 27. Remove Element *)

(*Given an array nums and a value val, remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.*)

(* Level : Easy *)

let remove_element array value =
  let rec helper array value counter =
    match array with
      [] -> counter
     |h::t -> if h == value
              then helper t value counter
              else helper t value (counter + 1)
in helper array value 0;;                
  
remove_element [3;2;2;3] 3;;
remove_element [0;1;2;2;3;0;4;2] 2;;



