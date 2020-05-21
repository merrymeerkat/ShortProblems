(*11. Container With Most Water *)

(*Level: Medium *)

(*Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
Note: You may not slant the container and n is at least 2.*)

(* transforms int list into tuple list. The first element of each tuple is an index, the second is the original int*)
let tuplefy l =
  let rec helper l counter =
    match l with
  |h::t -> (counter, h) :: helper t (counter + 1)
  |[] -> []
  in helper l 0;;
  
let max_int l =
  let rec helper l acc =
    match l with
    |(i,h) :: t -> if h > snd(acc) then helper t (i,h) else helper t acc
    |[] -> acc
  in helper l (0,0);;

let rec drop int l =
  match l with
  |(i, h)::t -> if h == snd(int) then t else (h,i) :: drop int t
  |[] -> [];;

drop (1,2) [(0,1);(1,2);(2,3)];;

let largest_container_helper l =
  let distance = abs(fst(max_int l) - fst(max_int (drop (max_int l) l)))
      in distance * snd(max_int (drop (max_int l) l));;

let largest_container l = largest_container_helper (tuplefy l);;

largest_container [1;8;6;2;5;4;8;3;7];;
                                    
