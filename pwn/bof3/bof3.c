// gcc bof3.c -o bof3 -fno-stack-protector -no-pie
// HINT: set rsi to 0
#include <stdio.h>
#include <unistd.h>

int getflag() {
    printf("AHAHA whats the use of coming hereere!\n");
    system("cat flaggg");
}

int main() {
    char buf[0x20];

    read(0, buf, 0x100);
    printf("uh so ok, %s, seems like getflag aint workin. have fun bye! try /bin/sh", buf);
}
