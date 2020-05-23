let list_of_multiples x n =
  let rec helper x n list acc =
    if acc <= n then helper x n (acc :: list) (acc + x) else list
  in helper x n [] x;;
