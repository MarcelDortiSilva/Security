//This small snippet simulates a brute-force of only 4 characters (only small letters)
//the idea is to use for loops to iterate each index of the array
//it works for didactic purposes

#include <stdio.h>
#include <string.h>

int main ()
{
    int i, j, k, l;
    char currentpass[5] = "pato";
    char trypass [6];

    printf("Insert the try with 4 characters only: ");
    fgets(trypass, sizeof(trypass) + 1, stdin);
    trypass[strcspn(trypass, "\n")] = 0; // Strip newline character (the enter)

    if (strcmp(currentpass, trypass) == 0) {
        printf("You guess the password: %s\n", trypass);
    }
    else
    {
        printf("Starting Light Force - 4 characters only\n");

        for (i=0; i <= 25; i++) {
            for (j=0; j <= 25; j++) {
                for (k=0; k <= 25; k++) {
                    for (l=0; l <= 25; l++) {
                        trypass[0] = 'a' + i;
                        trypass[1] = 'a' + j;
                        trypass[2] = 'a' + k;
                        trypass[3] = 'a' + l;
                        trypass[4] = '\0';

                        if (strcmp(trypass, currentpass) == 0) {
                            printf("The cracked pass is %s\n", trypass);
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 0;
}


