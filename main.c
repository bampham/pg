#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv) {

    if(argc > 3 || argc < 2) {
        printf("Usage: <len> <u><l><s><n>\n");
        return 1;
    }

    srand(time(NULL));
    int len = atoi(argv[1]);

    char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lower[] = "abcdefghijklmnopqrstuvwxyz";
    char symbols[] = "~`!@#$%^&*()_-+={[}]|\\:;'<,>.?/";
    char numbers[] = "0123456789";
    char alphabet[256];

    for(int i = 0; i < strlen(argv[2]); i++) {
        if(argv[2][i] == 'u') {
            strcat(alphabet, upper);
        }
        else if(argv[2][i] == 'l') {
            strcat(alphabet, lower);
        }
        else if(argv[2][i] == 's') {
            strcat(alphabet, symbols); 
        }
        else if(argv[2][i] == 'n') {
            strcat(alphabet, numbers);
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
