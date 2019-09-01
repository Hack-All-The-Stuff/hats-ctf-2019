#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma GCC push_options
#pragma GCC optimize ("O3")
int fun(char* s) {
    char password[64];
    memcpy(password, s, 64);
    char flag[] = "flag{no_m0r3_6pack_after_ctf}";

    if (strlen(password) != 29) {
        return 0;
    }

    for (int i = 0; i < strlen(password); ++i) {
        if (flag[i] != password[i]) {
            return 0;
        }
    }

    return 1;
}
#pragma GCC pop_options

int main() {
    char password[64];
    scanf("%64s", password);
    
    if (fun(password))
        puts("YOU GOT IT!");
    else
        puts("WRONG!");
    return 0;
}