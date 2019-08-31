// gcc fmt_str.c -o fmt_str -no-pie
#include <stdio.h>
#include <unistd.h>

void getflag() {
    system("cat flag");
}

int main() {
    char buf[0x20];
    read(0, buf, 0x20);
    printf(buf);
}
