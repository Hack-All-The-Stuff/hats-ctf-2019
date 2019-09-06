int main() {

    char target[] = {71, 78, 66, 67, 94, 71, 68, 92, 92, 75, 71, 64, 84, 113, 92, 68, 88, 94, 95, 107, 68, 67, 94, 76, 92, 101, 94, 70, 98, 82, 94, 61};
    char input[256];

    printf("Enter flag: ");
    scanf("%255s", input);
    for (int i = 0; i < strlen(input); ++i) {
        input[i] ^= 33 + i;
    }

    if (strlen(input) == sizeof(target) && memcmp(target, input, sizeof(target)) == 0) {
        puts("Correct");
    }
    else
        puts("NOOB");

    return 0;
}