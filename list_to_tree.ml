(*109. Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.*)

type 'a tree =
  Br of 'a * 'a tree * 'a tree
|Lf;;

let length l =
  let rec length_helper l acc =
    match l with
    |[] -> acc
    |h::t -> length_helper t (acc+1)
  in length_helper l 0;;

length [1;2;4;5;6;7;8;8];;

let rec take n l =
  if n = 0 then []
  else match l with
         h :: t -> h :: take (n-1) t
       | [] -> [];;

let rec drop n l =
  if n = 0 then l else
    match l with
      h :: t -> drop (n-1) t
    | [] -> [];;

exception Oops of string;;
let split l =
  match l with
  |[] -> None
  |[h] -> Some(h, [], [])
  |_ -> let len = length l in
        let firsthalf = take (len/2) l in
        let secondhalf = drop (len/2) l in
        match secondhalf with
        |[] -> raise (Oops "split")
        |h::t-> Some(h, firsthalf, t);;


let rec treeify l =
  match split l with
  |None -> Lf
  |Some(center, l, r) ->
    Br(center, treeify l, treeify r);;
