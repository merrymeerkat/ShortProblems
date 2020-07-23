(* 13. Roman to Integer *)

(* Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999. *)

(* Level: Easy *)

(* Converts a single roman character into an arabic numeral *)
let one_to_one roman =
  if roman == 'I' then 1
  else if roman == 'V' then 5
  else if roman == 'X' then 10
  else if roman == 'L' then 50
  else if roman == 'C' then 100
  else if roman == 'D' then 500
  else if roman == 'M' then 1000
  else 0;;
  
(*Converts string into char list (to make use of OCaml's list pattern matching) *)
let string_to_list str =
   let length = String.length str in
      let rec helper str counter acc =
         if counter < 0 then acc
          else helper str (counter - 1) (str.[counter] :: acc)
      in helper str (length - 1) [];;
               
 (* Iterates over input roman in order to calculate the arabic equivalent. We start at the right end and move leftwards. A pointer keeps track of the roman character last seen. If the current character is smaller than the one last seen, then we know we must subtract it from the current total (e.g. an I before X leads to X - I, or 9). Otherwise we sum. *)  
 let roman_to_int roman =
  let rec helper roman last_seen acc =
  match roman with
    [] -> acc
   |h::t ->
     let h_val = one_to_one h and last_val = one_to_one last_seen in
     if h_val < last_val then
       helper t h (acc - h_val)
     else
       helper t h (acc + h_val)
  in helper (List.rev(string_to_list roman)) 'a' 0;;
               
(* tests *)
roman_to_int "XIV";;
roman_to_int "III";;
roman_to_int "IV";;
roman_to_int "IX";;
roman_to_int "LVIII";;
roman_to_int "MCMXCIV";;

