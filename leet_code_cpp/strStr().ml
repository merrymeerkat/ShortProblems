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
   
 (*Given an int n and a list, returns the first n elements of the list *)
 let take n list =
     let rec helper n list acc =
         match list with
         h::t -> if n == 0 then acc
                 else helper (n -1) t (h :: acc)
         |[] -> acc
     in helper n list [];;

(* The "take" function above uses the cons (::) operator, which results in a lower time complexity but a backwards list. Here, we reverse the sublist back to the original order *)
 let take n list = List.rev (take n list);;
   
 (*main function *)  
 (* Given a haystack and a needle, this function will iterate over the haystack, beginning at index 0. At every index, we will take "length" elements of the haystack (where length is the length of the needle) and compare it with the needle. If it is a match, we return the counter that has been keeping track of the haystack's index. Else, we move on to the next element of the haystack and try again. If the end of the haystack is reached, there is no match, so we return -1.*)
 (* We convert both the haystack and the needle into char lists to make use of OCaml's powerful pattern matching feature for lists. They are both converted backc to strings at the end *)
 let  strStr hst ndl =
     let rec helper hst ndl counter length =
         match hst with
             |h::t -> if (ndl = (take length hst)) then counter
              else helper t ndl (counter + 1) length
             |[] -> (-1)
   in helper (string_to_list hst) (string_to_list ndl) 0 (List.length (string_to_list ndl));;
   
   (* tests *)
   strstr "Hello" "ll";;
   strstr "Hello" "lll";;
   strstr "Hellohello" "ll";;
   strstr "Hello" "";;
   strstr "Hello" "lloo";;
   strstr "Hello" "Hello";;
      


