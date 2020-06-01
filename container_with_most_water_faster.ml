

(* creatig exception for head function *)
exception EmptyList;;

(* returns the first element of a list *)
let head lst =
  match lst with
    h::t -> h
   |[] -> raise EmptyList;;

(*creating exception for drop function (you cannot drop elements from an empty list) *)
exception CantDropThisMuch;;

(* returns input list minus the first element *)
let rec  drop n l =
    match l with
      h::t -> if n = 1 then t else drop (n - 1) t
     |[] -> if n = 0 then [] else raise CantDropThisMuch;;

let drop_one l = drop 1 l;;

(* reverses the order of a list *)
let reverse l =
  let rec helper l new_l =
    match l with
      h::t -> helper t (h::new_l)
     |[] -> new_l
  in helper l [];;

(*Now, our final function *)
let container_fast l =
let rec helper l rl area =
  let a = ref (head l) in
  let b = ref (head rl) in
  let current_area = (min (snd(!a)) (snd(!b))) * (fst(!b) - fst(!a)) in
  if current_area == 0 then area
  else(
  if snd(!a) > snd(!b) then
    helper l (drop_one rl) (max area current_area)
  else if snd(!a) == snd(!b) then
    helper (drop_one l) (drop_one rl) (max area current_area)
  else helper (drop_one l) rl (max area current_area))
in helper (tuplefy l) (reverse (tuplefy l)) 1;;

container_fast [1;8;6;2;5;4;8;3;7];;
