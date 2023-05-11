#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv) {

    if(argc != 3) {
        printf("Usage: <len> <u><l><s><n>\n");
        return 1;
    }

    srand(time(NULL));
    int len = atoi(argv[1]);

    char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lower[] = "abcdefghijklmnopqrstuvwxyz";
    char symbols[] = "~`!@#$%^&*()_-+={[}]|\\:;'<,>.?/";
    char numbers[] = "0123456789";
    char alphabet[96];

    for(int i = 0; i < strlen(argv[2]); i++) {
        if(argv[2][i] == 'u') {
            strcat(alphabet, upper);
            upper[0] = '\0';
        }
        else if(argv[2][i] == 'l') {
            strcat(alphabet, lower);
            lower[0] = '\0';
        }
        else if(argv[2][i] == 's') {
            strcat(alphabet, symbols); 
            symbols[0] = '\0';
        }
        else if(argv[2][i] == 'n') {
            strcat(alphabet, numbers);
            numbers[0] = '\0';
        }
    }

    char password[len + 1];

    for(int i = 0; i < len; i++) {
        int rn = rand() % strlen(alphabet);
        password[i] = alphabet[rn];
    }

    password[len] = '\0';
    printf("Your password is: %s\n", password);

    return 0;
} 
