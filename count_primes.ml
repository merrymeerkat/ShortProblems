(* 204. Count Primes *)

(* Level: Easy *)

(* Count the number of prime numbers less than a non-negative number, n. *)

(* Answer *)

(* We will implement an algorithm inspired in the sieve of Erathostenes. For an input int n, we will create a list with multiples of all integers smaller than n (and the multiples themselves will also be smaller than n). Then we will use this list of multiples to "filter" the original list of integers smaller than n, so that only integers *not* present in the list of multiples count as primes *) 

(* given n, outputs list [2;3;...;n-1] *)
(* Starting at 2 because 2 is the first prime number *)
let make_list_from_2 n =
   let rec helper n acc counter =
    if counter >= n then acc
    else helper n (acc @ [counter]) (counter + 1)
  in helper n [] 2;;

(* outputs a list with all multiples of x that are less than n *)
let list_of_multiples x n =
  let rec helper x n list acc =
    if acc < n then helper x n (acc :: list) (acc + x) else list
  in helper x n [] (x+x);;

(*outputs list of non primes strictly less than n, excluding 1*)
(* This list will serve as our "filter" *)
let all_multiples_less_than n =
  let rec helper list n acc =
    match list with
    |h::t -> helper t n ((list_of_multiples h n) @ acc) 
    |[] -> acc
  in helper (make_list_from_2 n) n [];;

(* Finally, our main function *)
(*Counts # of primes less than a non-negative int n*)
let primes n =
  let rec helper list_up_to_n list_multiples counter =
    match list_up_to_n with
    |h::t -> if List.mem h list_multiples
             then (helper t list_multiples counter) (*h not prime*)
             else (helper t list_multiples (counter+1)) (*h prime*)
    |[] -> counter
  in helper (make_list_from_2 n) (all_multiples_less_than n) 0;;

(* tests *)
primes 1;;
primes 10;;
primes 7;;
primes 355;;
