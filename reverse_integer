(* "Given a 32-bit signed integer, reverse digits of an integer" *)

let rec helper int acc =
  match int with
   |0 -> acc
   |a -> helper (a/10) (acc * 10 + a mod 10);;

let reverse_int int = helper int 0;;

(*tests*)
reverse_int 123;;
reverse_int 321;;
reverse_int 3;;
reverse_int 987654321;;
reverse_int 42;;
