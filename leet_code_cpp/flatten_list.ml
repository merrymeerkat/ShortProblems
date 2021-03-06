(* 341. Flatten Nested List Iterator *)

(* Level: Medium *)

(* "Given a nested list of integers, implement an iterator to flatten it.
Each element is either an integer, or a list -- whose elements may also be integers or other lists." *)

(*non tail recursive *)
let rec flatten lst_lst =
  match lst_lst with
    []->[]
   |[] :: t -> flatten t
   |(h::t') :: t -> h :: (flatten (t' :: t));;


(*tail recursive alternative*)
let rec flatten_tr_helper lst_lst acc =
   match lst_lst with
    [] -> acc
   |[] :: t -> flatten_tr_helper t acc
   |(h::t')::t -> flatten_tr_helper (t'::t) (h :: acc) ;;

let rec flatten lst_lst = flatten_tr_helper lst_lst [];;

(*tests*)
flatten [[1;3;5];[2;4;6];[-1;-2;-3];[0]];; (*works*)
flatten [[1;2]];; (*works--returns [1;2]*)
flatten [[]];; (*works--returns []*)
flatten [[];[1;2;3];[]];;(*works--returns [1;2;3]*)
flatten [4,[1;2;3]];; (*gives type error--as expected*)
