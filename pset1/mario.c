#include <stdio.h>
#include <cs50.h> //to use get input functions

int main(void)
{
    int height = get_int("Height: ");
    do
    {
        if (height < 0)
        {
            height = get_int("Height: ");
        }
        else if (height > 8)
        {
            height = get_int("Height: ");
        }
    }
    while (height < 1 || height > 8);

    for (int row_counter = 1; row_counter<height + 1; row_counter += 1) //this initializes the counter for the rows, where the number of rows = height of pyramid
    {
        //this initializes the counter for spaces, where spaces for each row equals the height minus that row number
        for (int space_counter = 0; space_counter < (height-row_counter); space_counter += 1)
        {
            printf(" ");
        }

        //this initializes the counter for pounds, where each row contains a number of pounds equal to that row number
        for (int pound_counter = 0; pound_counter < (row_counter); pound_counter += 1)
        {
            printf("#");
        }

        printf("  ");

        //this initializes the counter for pounds on the right side, where each row contains a number of pounds equal to that row number, just mimics the left side
        for (int pound_counter = 0; pound_counter < (row_counter); pound_counter += 1)
        {
            printf("#");
        }

        //new line for the next portion of the pyramid before the next loop
        printf("\n");
    }

}

