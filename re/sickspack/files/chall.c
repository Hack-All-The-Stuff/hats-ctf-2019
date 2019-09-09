#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char real[] = "\x55\x0f\xb6\x17\x49\x89\xf9\x48\x89\xe5\x84\xd2\x0f\x84\x8e\x00\x00\x00\x48\x89\xf8\xeb\x3f\x66\x0f\x1f\x84\x00\x00\x00\x00\x00\x89\xca\xc1\xe2\x04\x41\x89\xd2\x0f\xb6\x48\x01\x83\xf1\x55\x8d\x79\xd0\x88\x48\x01\x40\x80\xff\x09\x77\x45\x44\x8d\x14\x3a\x44\x89\xc1\x48\x83\xc0\x02\xd1\xf9\x48\x63\xc9\x45\x88\x14\x09\x0f\xb6\x10\x84\xd2\x74\x4a\x83\xf2\x55\x41\x89\xc0\x8d\x4a\xd0\x45\x29\xc8\x88\x10\x80\xf9\x09\x76\xb7\x8d\x4a\x9f\x80\xf9\x05\x77\x27\x83\xea\x57\xc1\xe2\x04\x41\x89\xd2\xeb\xac\x0f\x1f\x40\x00\x8d\x79\x9f\x8d\x54\x0a\xa9\x40\x80\xff\x06\x44\x0f\x42\xd2\xeb\xae\x0f\x1f\x80\x00\x00\x00\x00\x45\x31\xd2\x31\xd2\xeb\x89\x90\x5d\x48\x89\xf7\x41\xff\xe1\x66\x0f\x1f\x84\x00\x00\x00\x00\x00";

char code[] = "``amml0`ammf06becaamm7eag`gmeeeeeeammla`3mfd6eamm7ebamm1a17m6ba`7g`3cfbaccamml64ammla`7mamm7abemammla`6eamm7abdeammla`6mamm7abdmammla`1eamm7abgeammla`1mamm7abgmammla`0eamm7abfeammla`0mamm7abfmammla`3eam7mamad`a`fb7c0c3`3ammla`l4am7mc1febgff`3fcbecdammla`4gam7mcfc7`3cdccbac`bgammla`447mb1eeeeeeccmla`7cm7fgammf6geam1mc333030303b1cgd3eg`memememeba0lml6c6d00de4lmemeeeeee3aa6camm1bgegml6bame3aa1caeee6bammf14effd6eamgl64ammf34d1badlamm7a13mcaamffe6g`gmeeeeeeb`ad6l6fe3d3maeeeeeeeeeemeb17mamb`0d7medeeeeeeamm1``l407dde3d3meeeeeeeeeammf6eedammf3md1bae0e37cfaedaefmfaegba06fd6e077b7medeeeeee077e0mla313333e3d3aeee";

char diff[] = "\x00\x00\x38\x38\x09\x20\x00\xa0\xbd\xbb\x07\xb7\xc3\xc0\xdd\x23\x8a\x55\xe8\xa0\xa3\xbb\x07\xb7\xc1\x43\x75\xfc\xd6\xff\xd0\x78\xd5\x3d";

int fun(char* code, char* password) {
    char* fun_ptr = &fun;
    for (size_t i = 102; i < 136; ++i) {
        fun_ptr[i] ^= diff[i - 102];
    }
    puts("SIKED");
    puts("DO YOU KNOW THE FLAG?");
    puts("WHAT ARE YOU DOING HERE?");
    puts("GO HOME");
    puts("YOU ARE BAD");
    puts("WHAT'S THE POINT OF READING THIS?");
    puts("DELETE THIS PROGRAM");
    puts("QUIT THE CTF");
    // int (*real_fun)(char*, char*) = real; 
    // real_fun(code, password);
}

int main() {
    char password[64];
    printf("Enter flag: ");
    scanf("%64s", password);
    
    if (fun(code, password))
        puts("YOU GOT IT!");
    else
        puts("WRONG!");
    return 0;
}