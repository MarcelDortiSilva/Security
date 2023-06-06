/*The purpose of this program is to work with arrays, for loop and string manipulation in the context of cybersecurity
basic knowledge of cryptography requires the knowledge of the caesar cipher, the first cipher used by the Roman Empire to cryptograph messages with a Cryptex
more on https://www.dcode.fr/caesar-cipher
the ctype lib is used to check some elements of the string, so that, we keep between the numbers related to ASCII code and do not fall in a region, where
no small or cap letters are found
More on https://www.ascii-code.com/*/


#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main ()
{
int key; // declares key
char string[20]; //create an array with alphabet, and a string where the message will be stored

printf ("Enter message to be ciphered:"); // human interface
fgets (string, sizeof(string), stdin); // fgets allocates the string into the array, and avoids bufferoverflow - scanf ("%s", string) may cause bufferoverlow
printf ("Enter the Key of the Caeser simplified Cipher: ");// human interface
scanf ("%d", &key); //stores key

for ( int i =0; string[i] != '\0'; i++) // for index = 0, loop until the index is different than end of line -'\0'- i.e. checks all the indexes (characterers of the array)
    {
        if (isspace((unsigned char)string[i])) // checks if it there is space in the string
        {
        continue;
        }
        else if (islower((unsigned char) string[i])) // checks if there lower case in the string
            {
            string[i] = (string[i] - 'a' - key) % 26 + 'a';
            }
        else if (isupper((unsigned char)string[i])) // checks if there is upper case in the string
            {
            string[i] = (string[i] - 'A' - key) % 26 + 'A';
            }
    //string[i] = string[i] + key; // regular way to add, without ctype.h library
    }
printf ("The value of the ciphered text is %s\n", string);

return 0;
}
