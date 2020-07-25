(* 12. Integer to Roman *)

(* Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999. *)

(* Level: Medium *)

(* sketches *)
let roman_option int =
  match int with
    1 -> Some 'I'
   |5 -> Some 'V'
   |10 -> Some 'X'
   |50 -> Some 'L'
   |100 -> Some 'C'
   |500 -> Some 'D'
   |1000 -> Some 'M'
   |_ -> None;;

roman_option 10;;

let rec tri1 int acc =
  match (roman_option int) with
  |None -> tri1 (int - 1) ('I' :: acc)
  |Some rom -> rom :: acc;;

tri1 550 [];;

(* create fun that checks if all els in a list  are the same *)

let grouping roman_list =
  let helper roman_list recent output =
    match roman_list with
    |[] -> output
    |h::t -> if (List.length recent) > 4 then helper t [h] ('V' :: output)
    else 
      
