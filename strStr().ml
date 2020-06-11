(* 28. Implement strStr(). *)

(* Level: Easy *)

(* Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack. *)

(*Converts string into char list (to make use of OCaml's list pattern matching) *)
let string_to_list str =
   let length = String.length str in
      let rec helper str counter acc =
         if counter < 0 then acc
          else helper str (counter - 1) (str.[counter] :: acc)
      in helper str (length - 1) [];;
