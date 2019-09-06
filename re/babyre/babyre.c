int main() {
    printf("Enter flag: ");
    char input[256];
    scanf("%256s", input);
    if (strcmp(input, "HATS{so_easy}") == 0) {
        printf("%s is the flag\n", input);
    }
    else {
        puts("SO NOOB");
    }
    return 0;
}