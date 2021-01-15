(* 9. Palindrome Number *)

(* Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward. *)

(* Level: Easy *)


(* Main: Checks if integer is a palindrome. *)
(* If the integer is negative, then we already know 
that it is not a palindrome. If it is positive, we check
whether the integer equals its reverse *)
let is_palindrome int =
  if int < 0 then false
  else if int == (reverse int) then true
  else false;;


(* Helper: Given an integer, this function reverses it *)
let reverse int =
let rec helper int acc =
  match int with
   |0 -> acc
   |a -> helper (a/10) (acc * 10 + a mod 10)
   in helper int 0;;


(* Tests *)
is_palindrome 121;;

is_palindrome ~-121;;

is_palindrome 10;;
