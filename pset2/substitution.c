#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

//argc = number of arguments
//argv = array of said arguments
//argv[0] = name of file to run
//argv[1] = first command-line argument
int main(int argc, string argv[])
{

    string alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    //check to see if only one key is input as an argument
    if (argc != 2)
        {
        printf("ERROR: ONE COMMAND-LINE-KEY ARGUMENT NEEDED\n");

        return 1;
        }

    //check to see if length of argument is 26 characters
    else if (strlen(argv[1]) != 26)
        {
        printf("ERROR: KEY MUST BE 26 CHARACTERS\n");

        return 1;
        }

    //check to see if key is only letters, either upper- or lower-case
    for (int i = 0; i < strlen(argv[1]); i+=1)
        {
        if (isalpha(argv[1][i]) == 0)
            {
            printf("ERROR: KEY MUST CONTAIN ONLY LETTERS\n");

            return 1;
            }
        }

    //check to make sure no duplicate letters exist in key
    //loop through key, loop through alphabet, change each one to
    //a space, if any letters are left, then duplicates exist
    //this works because all other tests have been checked
    //so it is of length 26, only letters
    char dup_check_arr[26]; //array for duplicate character checker

    //first loop through key, first element will always be a new character not already in dup char checker
    //so just add it to the array to check duplicates
    dup_check_arr[0] = argv[1][0];
    int i = 1;

    //every time a character is found not to be in the duplicate checker array, increment this number by 1 to count the number of non duplicates
    //start with 1 because at least 1 letter exists as a non-duplicate, the first letter of the key
    int non_dups= 1;
    while (i < 27)
        {
        //now loop through alphabet

        //if character not in dup_check_arr, great, add it, and increment non_dups by 1 to count non-duplicates
        if (strchr(dup_check_arr,argv[1][i]) == 0)
            {
            dup_check_arr[non_dups] = argv[1][i];
            non_dups += 1;
            }
        //move on to next char of the command-line-key
        i += 1;
        }

    //if non_dups!= 26, duplicates exist
    if (non_dups != 26)
        {
        printf("ERROR: DUPLICATE CHARACTERS ARE NOT ALLOWED IN COMMAND-LINE-KEY\n");
        return 1;
        }

    //if non_dups== 26, then no duplicates exist
    else //NO DUPLICATES EXIST, GO THROUGH THIS PATH
        {
        string to_cipher = get_string("plaintext:  ");

        //pseudocode
        //loop through plaintext
        //IF ALPHABET CHAR AND UPPERCASE
            //find char of plaintext in alphabet, return that index
            //replace plaintext char with UPPER(key[index])
            //return to loop
        //IF ALPHABET CHAR AND LOWERCASE
            //find char of plaintext in alphabet, return that index
            //replace plaintext char with LOWER(key[index])
            //return to loop

        //loop through plain text, start with first letter
        //loop through alphabet with alph_ind as a counter
        //once that char is found, use alph_ind to replace plain_text[plaintext_ind] with argv[1][alph_ind]

    char ciphered[strlen(to_cipher)+1];
    for (int plaintext_ind = 0; plaintext_ind < strlen(to_cipher); plaintext_ind += 1)
        {
        //maybe use pointers to find index, but I'm tired, and stopping for the day

        //check upper vs lower
        if (isupper(to_cipher[plaintext_ind]) != 0) //if isupper() != 0, then char is upper case
            {
            for (int alph_ind = 0; alph_ind < strlen(alph); alph_ind += 1)
                {
                //when the char in plaintext matches a char in alphabet, use that alphabet index
                //as index for char in command-line-key
                if (to_cipher[plaintext_ind] == toupper(alph[alph_ind])) //make sure key char is uppercase for equality check
                    {
                    ciphered[plaintext_ind] = toupper(argv[1][alph_ind]); //exit loop once replacement is complete
                    break;
                    }
                }
            }

        else if  (islower(to_cipher[plaintext_ind]) != 0)//lower case if isupper == 0
            {
            for (int alph_ind = 0; alph_ind < strlen(alph); alph_ind += 1)
                {
                //when the char in plaintext matches a char in alphabet, use that alphabet index
                //as index for char in command-line-key
                if (to_cipher[plaintext_ind] == tolower(alph[alph_ind])) //make sure key char is lowercase for equality check
                    {
                    ciphered[plaintext_ind] = tolower(argv[1][alph_ind]); //exit loop once replacement is complete
                    break;
                    }
                }
            }

        //if not a character, then just copy it back in
        else
            {
            ciphered[plaintext_ind] = to_cipher[plaintext_ind];
            }
        }

    //to avoid over buffer overuns values, I don't understand this much, but ensures last character is \0 so that ends the string
    //i used this because I had a problem with extra characters being inputted
    if (strlen(ciphered) == 1)
        {
        ciphered[1] = '\0';
        }
    else
        {
        ciphered[strlen(to_cipher)] = '\0';
        }
    printf("ciphertext: %s\n", ciphered);
    return 0;
    }
}