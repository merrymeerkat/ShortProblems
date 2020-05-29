(* Not a LeetCode problem *)
(* This is a simplified version of problem No 11 (the solution of which is also found in this repository). However, instead of finding the area of the container with the most water, in this version we find the area of the highest container. Of course, these two areas are sometimes the same, but not always *)

(* transforms int list into tuple list. The first element of each tuple is an index, the second is the original int*)
let tuplefy l =
  let rec helper l counter =
    match l with
  |h::t -> (counter, h) :: helper t (counter + 1)
  |[] -> []
  in helper l 0;;
  
(* Given a tuple list, returns the tuple whose second element is largest of all *)
let max_int l =
  let rec helper l acc =
    match l with
    |(i,h) :: t -> if h > snd(acc) then helper t (i,h) else helper t acc
    |[] -> acc
  in helper l (0,0);;

(* Given a tuple and a tuple list, drops from list the tuple which equals the input tuple *)
let rec drop tupl l =
  match l with
  |(i, h)::t -> if h == snd(tupl) then t else (h,i) :: drop tupl t
  |[] -> [];;

drop (1,2) [(0,1);(1,2);(2,3)];;

(*  ... name max_int l *)
let largest_container_helper l =
  let distance = abs(fst(max_int l) - fst(max_int (drop (max_int l) l)))
      in distance * snd(max_int (drop (max_int l) l));;

let largest_container l = largest_container_helper (tuplefy l);;

largest_container [1;8;6;2;5;4;8;3;7];;
