let random_chars chars = String.make 1 chars.[Random.int (String.length chars)]

let generate_passwd chars len =
  let passwd = Buffer.create len in  
  for _ = 1 to len do
    Buffer.add_string passwd (random_chars chars);  
  done;
  Buffer.contents passwd
;;

let () =
  Random.self_init ();
  let len = 12 in
  let chars = "abcdefghijklmnopqrstuvwxyz" in
  let password = generate_passwd chars len in

  Printf.printf "%s\n" password;
;;
