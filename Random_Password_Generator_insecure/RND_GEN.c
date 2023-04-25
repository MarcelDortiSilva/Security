/*This small program will teach how to create a random password to be
used in any password application, it is known this program generation is not
as secure as the next program we will create, the purpose here is to be able to
have a clear distinction of how the level of randomness - affects the security
of the password for elevation of privileges - i.e. low entropy - low randomness,
easier password break.*/
#include <stdio.h>
#include <string.h>
#include<time.h>
int
main ()
{
 int password_length; //let us define the length of password to be 22 characters
 printf("Please, enter the password length in characters: "); // let us request from the human the quantity of characters
 scanf("%d", &password_length); // let us get the integer variable as input from the human via keyboard (stdarin)

char charSet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcefghijklmnopkrstuvwxyz0123456789@§$%?"; // declared a char, with a charset, those will be the elements of the password
int charSetLength = sizeof(charSet) -1; // defines an integer with the charset, and gets the sizeof in bytes, -1, to remove the special character byte: \n

//generate seed from time of the computer - seed is the primary number from which all the randomness is derived,
srand (time(NULL)); // gets seed random from the time on the computer in UTC format

//allocating memory for the password, use pointer char and malloc;
char *password = (char *) malloc ((password_length + 1)*sizeof(char));
password[password_length] =  '\0';

//Generate the password
for (int i = 0; i < password_length; i++ )
{
    password[i] = charSet[rand() % charSetLength]; //the mod operator between rand and CharSetLength will define the password
}

//printf info
printf("The generated password = %s\n",password);

//free memory allocation
free(password);

return 0;
}




