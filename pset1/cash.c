#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
    {

    float change;

    do
        {
        change = get_float("Enter Change: ");
        }

    while (change < 0);

    change *= 100;

    change = round(change);

    int total_coins = 0;

    int qu, di, ni, pe = 0;

    //make a loop that tracks number of times we can use a quarter, subtract each time,
    //ensuring that you don't go negative, if negative, moves to next smallest coin

    //gives how many times 25 goes into change value as an integer
    qu = change/25;

    //updates change to subtract 25*how many times it goes into change value
    change -= qu*25;

    //move onto dimes
    //repeat again for dimes, nickels, pennies

    di = change/10;

    change -= di*10;

    ni = change/5;

    change -= ni*5;

    pe = change;

    total_coins = qu + di + ni + pe;

    printf("%d \n", total_coins);
    }