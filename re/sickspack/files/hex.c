#include <string.h>

char code[] = "``amml0`ammf06becaamm7eag`gmeeeeeeammla`3mfd6eamm7ebamm1a17m6ba`7g`3cfbaccamml64ammla`7mamm7abemammla`6eamm7abdeammla`6mamm7abdmammla`1eamm7abgeammla`1mamm7abgmammla`0eamm7abfeammla`0mamm7abfmammla`3eam7mccc6cdcbb7c0c3`3ammla`l4am7mc1febgff`3fcbecdammla`4gam7mcfc7`3cdccbac`bgammla`447mb1eeeeeeccmla`7cm7fgammf6geam1mc333030303b1cgd3eg`memememeba0lml6c6d00de4lmemeeeeee3aa6camm1bgegml6bame3aa1caeee6bammf14effd6eamgl64ammf34d1badlamm7a13mcaamffe6g`gmeeeeeeb`ad6l6fe3d3maeeeeeeeeeemeb17mccb`0d7medeeeeeeamm1``l407dde3d3meeeeeeeeeammf6eedammf3md1bae0e37cfaedaefmfaegba06fd6e077b7medeeeeee077e0mla313333e3d3aeee";

#pragma GCC push_options
#pragma GCC optimize ("O3")
int fun(char* code, char* password) {
    for(int i = 0; code[i] != 0; i += 2) {
        char c = 0;
        code[i] ^= 0x55;
        if (code[i] >= '0' && code[i] <= '9')
            c += code[i] - '0';
        else if (code[i] >= 'a' && code[i] <= 'f')
            c += code[i] - 'a' + 10;
        
        c *= 0x10;

        code[i + 1] ^= 0x55;
        if (code[i + 1] >= '0' && code[i + 1] <= '9')
            c += code[i + 1] - '0';
        else if (code[i + 1] >= 'a' && code[i + 1] <= 'f')
            c += code[i + 1] - 'a' + 10;

        code[i/2] = c;
    }

    int (*check)(char*) = code; 
    return check(password);
}
#pragma GCC pop_options

int main() {
    char password[64];
    scanf("%63s", password);
    
    if (fun(code, password))
        puts("YOU GOT IT!");
    else
        puts("WRONG!");

    return 0;
}