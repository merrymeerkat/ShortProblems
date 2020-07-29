(* 12. Integer to Roman *)

(* Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999. *)

(* Level: Medium *)

(* sketches *)
let check int =
  let rec helper int roman_list =
    if int >= 1000 then helper (int - 1000) ('M' :: roman_list)
    else if int >= 500 then helper (int - 500) ('D' :: roman_list)
    else if int >= 1000 then helper (int - 100) ('C' :: roman_list)
    else if int >= 50 then helper (int - 50) ('L' :: roman_list)
    else if int >= 10 then helper (int - 10) ('X' :: roman_list)
    else if int >= 5 then helper (int - 5) ('V' :: roman_list)
    else if int >= 1 then helper (int - 5) ('I' :: roman_list)
    else List.rev (roman_list)
    in helper int [];;

(* now solve for cases where 4 Is equal IV etc *)
