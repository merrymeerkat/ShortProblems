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
      
      
(* Given a list, returns a subsect starting at index strt and with length len *)
let subset lst strt len =
   let rec helper lst strt len acc =
      match lst with
      h::t -> if len == 0 then List.rev acc
               else if strt == 0 then (helper t strt (len - 1) (h :: acc))
               else helper t (strt - 1) len acc
      |[] -> List.rev acc
   in helper lst strt len [];;
   
   (*main function *)  (*ajeitar. botar helper e explicação)
  let rec onze hst ndl counter length =
     match hst with
     |h::t -> if (ndl = (subset hst 0 length)) then counter
              else onze t ndl (counter + 1) length
     |[] -> (-1);;

   let a =  subset (string_to_list "Abacate") 3 4;;
   let b =  string_to_list "cate";;
      


