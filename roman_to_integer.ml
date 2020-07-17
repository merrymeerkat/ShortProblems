(* 13. Roman to Integer *)

(* Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999. *)

(* Level: Easy *)

let one_to_one roman =
  if roman == 'I' then 1
  else if roman == 'V' then 5
  else if roman == 'X' then 10
  else if roman == 'L' then 50
  else if roman == 'C' then 100
  else if roman == 'D' then 500
  else if roman == 'M' then 1000
  else 0;;
               
               
               
               ....
