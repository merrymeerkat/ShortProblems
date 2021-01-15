(* 12. Integer to Roman *)

(* Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999. *)

(* Level: Medium *)

(* Returns a "brute" roman version of a given int. By brute we mean that some roman numerals might be repeated four times (e.g. "IIII") *)
let check int =
  let rec helper int roman_list =
    if int >= 1000 then helper (int - 1000) ('M' :: roman_list)
    else if int >= 500 then helper (int - 500) ('D' :: roman_list)
    else if int >= 1000 then helper (int - 100) ('C' :: roman_list)
    else if int >= 50 then helper (int - 50) ('L' :: roman_list)
    else if int >= 10 then helper (int - 10) ('X' :: roman_list)
    else if int >= 5 then helper (int - 5) ('V' :: roman_list)
    else if int >= 1 then helper (int - 1) ('I' :: roman_list)
    else List.rev (roman_list)
    in helper int [];;

(* Given a roman, returns the next largest roman *)
let get_next roman =
  let rec helper roman roman_list =
    match roman_list with
    |h::a::t -> if roman == h then Some a else helper roman (a::t)
    |[a] -> None
  in helper roman ['I'; 'V'; 'X'; 'L'; 'C'; 'D'; 'M'];;

(* Pops the first n elements of a list *)
let pop n list =
  let rec helper n list counter =
  match list with
  |[] -> []
  |h::t -> if counter == 0 then t
           else helper n t (counter - 1)
  in helper n list (n - 1);;
  

(* Handles repetition of roman numerals. For example, "IIII" becomes "IV" *)
let change roman =
  let rec helper roman new_roman counter last_seen =
    match roman with
    |[] -> new_roman
    |h::t ->
      if h == last_seen
      then (if counter == 2 then
              (match get_next h with
              |Some next_roman ->
                helper t (h :: next_roman :: (pop 3 new_roman)) 0 'A'
              |None -> helper t (h :: new_roman) 0 'A')
      else helper t (h :: new_roman) (counter + 1) h)
      else helper t (h :: new_roman) 0 h
  in helper (List.rev roman) [] 0 'A';;


let change_alternate roman =
  let rec helper roman new_roman =
    match roman with
    |[] -> new_roman
    |[h1] -> new_roman
    |h1 :: h2 :: [] -> new_roman
    |h1 :: h2 :: h3 ->
      if h1 == h3
      then (match get_next h1 with
            |Some next_roman ->
              helper t (h2 :: next_roman :: new_roman)
            |None ->
              helper t (h1 :: h2 :: h3 :: new_roman))
      else helper (h2 :: h3 :: t) (h1 :: new_roman)
   in helper (List.rev roman) [];;
