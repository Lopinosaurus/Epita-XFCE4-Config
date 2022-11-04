let rec nth n list = match list with
    [] -> failwith "list too short"
  | e::l when n = 0 -> e
  | e::l -> nth (n-1) l;;


                       
