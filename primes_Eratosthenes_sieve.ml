let find_primes n =
  let l = list_generator n in
 let rec sieve l' primes =
    (match l' with
      [] -> primes
     |h::t ->
       let rest = (filter (fun x -> x mod h > 0) t) in
       sieve rest (primes @ [h]))
 in sieve l [];;
