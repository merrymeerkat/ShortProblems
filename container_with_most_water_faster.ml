(*11. Container With Most Water *)

(*Level: Medium *)

(*Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
Note: You may not slant the container and n is at least 2.*)

(*This solution is of O(n) complexity (explanation below) *)

(* transforms int list into tuple list. The first element of each tuple is an index, the second is the original int*)
let tuplefy l =
  let rec helper l counter =
    match l with
  |h::t -> (counter, h) :: helper t (counter + 1)
  |[] -> []
  in helper l 0;;

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

(*Now, onto our main function *)
(* Explanation:    *)
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
