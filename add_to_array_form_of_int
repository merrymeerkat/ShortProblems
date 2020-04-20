(* 989. Add to Array-Form of Integer *)

(* For a non-negative integer X, the array-form of X is an array of its digits in left to right order.  For example, if X = 1231, then the array form is [1,2,3,1].

Given the array-form A of a non-negative integer X, return the array-form of the integer X+K. *)

let array_to_int arr =
  let rec helper arr acc =
  match arr with
  |[h] -> acc*10 + h
  |h::t -> helper t (acc*10 + h)
  in
  helper arr 0;;
         
let rec int_to_array int =
  let rec helper int acc =
  match int with 
    0-> acc
   |a -> helper (a/10) (a mod 10 :: acc)
  in
  helper int [];;

let add_to_array_form_int arrint add =
  int_to_array ((array_to_int arrint) + add);;

(* tests *)
add_to_array_form_int [1;2;0;0] 34;;
add_to_array_form_int [2;7;4] 181;;
add_to_array_form_int [9;9;9;9;9;9;9] 1;;
