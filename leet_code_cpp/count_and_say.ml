(* 38. Count and Say *)

(* The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence. You can do so recursively, in other words from the previous member read off the digits, counting the number of digits in groups of the same digit.

Note: Each term of the sequence of integers will be represented as a string. *)

(* Level: Easy *)

(* Helper: Given a list of integers, transforms it into a string *)
let int_list_to_string list =
  let rec helper list acc =
    match list with
      [] -> string_of_int acc
     |h :: t -> helper t ((acc * 10) + h)
  in helper list 0;;

(* Helper: this function "counts and says" the integers of a list of integers *)
let digit_counter list =
  let rec helper list last_seen counter new_list =
    match list with
      [] -> List.rev(last_seen :: counter :: new_list)
     |h::t ->
       if h == last_seen then helper t h (counter + 1) new_list
       else helper t h 1 (last_seen :: counter ::  new_list)
  in helper list (List.hd list) 0 [];;

(* Helper: this function applies digit_counter recursively, as many times as needed,
in order to generate the n_th term (in list form) of the count-and-say sequence *)
let rec count_and_say_helper n =
      if n == 1 then [1]
      else  (digit_counter (count_and_say_helper (n-1)));;

(* Finally, a small tweak so that we get the answer in string form *)
let count_and_say n = int_list_to_string (count_and_say_helper n);;

(* Tests *)

count_and_say 1;;
count_and_say 2;;
count_and_say 3;;
count_and_say 4;;
count_and_say 5;;
count_and_say 6;;
count_and_say 15;;
count_and_say 30;;
