(* converts string into a list of unit strings *)
let string_to_list str =
  let length = String.length str in
  let rec helper str counter acc =
     if counter < 0 then acc
     else helper str (counter - 1) ((Char.escaped str.[counter]) :: acc)
  in helper str (length - 1) [];; 


(* checks if letters appear before numbers *)
let check_if_alpha string =
  let rec helper list =
    match list with
      [] -> true
    | h::t -> match (int_of_string_opt h) with
                Some a -> true
              |None -> if (((compare h "-") == 0) || ((compare h " ") == 0))
                                    then helper t
                       else false
in helper (string_to_list string);;

let atoi string =
  if not (check_if_alpha string) then 0 else
    let rec helper lst counter acc sign =
    match lst with
      [] -> if sign then (-acc) else (acc) 
     |h::t -> match (int_of_string_opt h) with
                Some a -> helper t (counter * 10) (a*counter + acc) sign
               |None -> if (compare h "-") == 0
                        then helper t counter acc true
                        else (helper t counter acc sign)
    in helper (List.rev (string_to_list string)) 1 0 false;;

atoi "abc-345ad";;
atoi "3456";;
atoi "-345a";;
