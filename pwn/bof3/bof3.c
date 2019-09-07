// gcc bof3.c -o bof3 -fno-stack-protector -no-pie
// HINT: set rsi to 0
#include <stdio.h>
#include <unistd.h>

void banner(){
    alarm(60);
    setvbuf(stdin, 0LL, 2, 0LL);
    setvbuf(stdout, 0LL, 2, 0LL);
    setvbuf(stderr, 0LL, 2, 0LL);
    printf("*** WELCOME TO %s ***\n", __FILE__);
}


int getflag() {
    printf("AHAHA whats the use of coming hereere!\n");
    system("cat flaggg");
}

int main() {
    banner();
    char buf[0x20];

    read(0, buf, 0x100);
    printf("uh so ok, %s, seems like getflag aint workin. have fun bye! try /bin/sh", buf);
}
