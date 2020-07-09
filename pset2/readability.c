#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <math.h>

float col_liau_ind(float let_count,float wor_count,float sen_count);

int main(void)
    {
    string text = get_string("Text: ");
    float letter_count = 0, word_count = 0, sentence_count = 0;

    for (int i = 0; i < strlen(text); i++)
        //start with letter, if lower case or upper case, letter_total += 1
        {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
            {
            letter_count += 1;
            }

        //spaces cover commas or quotations, and periods always come after a word
        //if (((text[i-1] >= 'a' && text[i-1] <= 'z') || (text[i-1] >= 'A' && text[i-1] <= 'Z')) && text[i] == ' ' && ((text[i+1] >= 'a' && text[i+1] <= 'z') || (text[i+1] >= 'A' && text[i+1] <= 'Z')) )
        //so ugly and probably could be way cleaner with better functions with characters
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i-1] == ' ' && (text[i] >= 'a' && text[i] <= 'z')) || ((text[i-1] == '"' && ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')))))
            {
            word_count += 1;
            //printf("%c",text[i]);
            }

        //periods indicate end of sentence, sentence_count += 1
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
            {
            sentence_count += 1;

            }
        }


        //move on to words, if encounters a space, word_count += 1

    //printf("Letter Count: %.f\n",letter_count);
    //printf("Word Count: %.f\n",word_count);
    //printf("Sentence Count: %.f\n",sentence_count);

    if (col_liau_ind(letter_count,word_count,sentence_count) < 1)
        {
            printf("Before Grade 1\n");
        }

    else if (col_liau_ind(letter_count,word_count,sentence_count) >1 && col_liau_ind(letter_count,word_count,sentence_count) < 16)
        {
            printf("Grade %.f\n", col_liau_ind(letter_count,word_count,sentence_count));
        }

    else
        {
            printf("Grade 16+\n");
        }

    //printf("Coleman-Liau Index: %.f\n", col_liau_ind(letter_count,word_count,sentence_count));

    }

float col_liau_ind(float let_count,float wor_count,float sen_count)
{
    float L = (let_count/wor_count)*100;
    //printf("L EQUALS: %f\n", L);
    float S = (sen_count/wor_count)*100;
    //printf("S EQUALS: %f\n", S);
    //printf("\nSEN COUNT EQUALS: %.f\n", sen_count);
    //printf("WOR COUNT EQUALS: %.f\n", wor_count);
    //printf("LET COUNT EQUALS: %.f\n", let_count);
    float index = round(0.0588*L - 0.296*S - 15.8);
    return index;
}