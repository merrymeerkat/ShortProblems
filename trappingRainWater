(* Our trapping rain water function will basically work like this: we count how many "surrounded" zeroes there are in the list given, then we decrease all of the list element values by 1 and do the same, until the entire list only has numbers below 1 (i.e. until the entire skyline has been "sunk"). By "surrounded" we mean 0s that have buildings around them, which means that the water will actually get trapped *)

(* returns a list where each element is 1 unit smaller*)
let rec decrease_by_1 lst =
  match lst with
    [] -> []
   |h::t -> (h-1) :: decrease_by_1 t;;

(*testing*)
decrease_by_1 [2;1;3;0;4;2;2;-27];; (*works*)

(* Now, on to the main function *)
(* l is the skyline list *)
(* listacc is an accumulator where we put the elements of the list that have already been looked at. This is needed because we want to recall what the original list was, so that we can decrease all elements by 1 after each complete run *)
(* draftacc has the zeroes being counted *)
(*acc has the zeroes that we know for sure will correspond to trapped water (and we only know this after reaching a number higher than 0 in the list) *)
(*flag is a bool that starts as false but will turn true whenever we see a number higher than 0. This ensures that we only pass the values of draftacc to acc when there are buildings around to trap the water *)
(* are_we_done is a bool that starts as true and turns false whenever we see an int greater than 0. This is because, when the list elements are all less than or equal to 0, it means we have decreased the skyline by 1 many times and all the water has been counted. When are_we_done is false, we still have to decrease each element by one and run counting_zeroes again. When are_we_done = true we return acc (i.e. water volume)*)

let rec counting_zeroes l listacc draftacc acc flag are_we_done =
  match l with
    h::t -> if h>0
            then counting_zeroes t (h::listacc) 0 (draftacc + acc) true false
            else if flag = true
            then counting_zeroes t (h::listacc) (draftacc + 1) acc flag are_we_done
            else counting_zeroes t (h::listacc) draftacc acc flag are_we_done
   |[] -> if are_we_done
          then acc
          else counting_zeroes (decrease_by_1 listacc) [] 0 acc false true;;

let rain_water l = counting_zeroes l [] 0 0 false true;;

(* testing *)

rain_water [0;0;0];;
rain_water [0;1;0];;
rain_water [1;0;1];;
rain_water [0;0;1;0;1;0];;
rain_water [2;1;3;0;1;2;4;3;1;2;2;1;0;1];;(* all work *)
