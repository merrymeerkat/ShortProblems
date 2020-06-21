(* converts string into a list of unit strings *)
let string_to_list str =
  let length = String.length str in
  let rec helper str counter acc =
     if counter < 0 then acc
     else helper str (counter - 1) ((Char.escaped str.[counter]) :: acc)
  in helper str (length - 1) [];; 


 (*this one works for the simplest case *)
let atoi str =
  let rec helper lst counter acc =
    match lst with
      [] -> acc
     |h::t -> match (int_of_string_opt h) with
                Some a -> helper t (counter * 10) (a*counter + acc)
               |None -> helper t counter acc
    in helper (List.rev (string_to_list str)) 1 0;;
                                                  
atoi "45678";;
atoi "45678dani9";;
atoi "-43";;


let atoi str =
  let rec helper lst counter acc sign =
    match lst with
      [] -> if sign then acc else (-acc) 
     |h::t -> match (int_of_string_opt h) with
                Some a -> helper t (counter * 10) (a*counter + acc) sign
               |None -> if h == "-" then (helper t counter acc false)
               else (helper t counter acc sign)
    in helper (List.rev (string_to_list str)) 1 0 true;;
