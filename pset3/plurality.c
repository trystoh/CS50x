/*This code allows users to enter a maximum number of 9 candidates as command-line arguments that will be running for office!!! Yes this is real, take it seriously and make sure to vote.*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
string print_winner();
void print_max_votes();

int main(int argc, string argv[])
{
    // Check for invalid usage
    //Must have at least two candidates
    if (argc < 3)
    {
        printf("At least two candidates for a vote to matter.\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i += 1)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (vote(name) != true)
            {
            printf("Invalid vote.\n");
            i -= 1;
            }
    }
    string winners;
    print_max_votes();
}

// Update vote totals given a new vote
//return true if valid vote
//return false if invalid vote
//Update vote count in here, since it returns true if it's valid, so might as well update here
bool vote(string name)
    {
    for (int i = 0; i < candidate_count; i += 1)
        {
        //if capital vs lowercase, strcmp is 32 or -32 bc it's diff in ASCII
        if (((strcmp(name, candidates[i].name)) == 0) || ((strcmp(name, candidates[i].name)) == 32) || ((strcmp(name, candidates[i].name)) == -32))
            {
            candidates[i].votes += 1;
            return true;
            }
        }
    //return false if looped through entire candidate list with no equality
    return false;
    }

// Print the winner (or winners) of the election
// Updates max vote count,
//max votes updated by (difference of max_votes and current vote counts if current vote counts greater than max_votes)
void print_max_votes()
    {
    string winner_s[candidate_count];
    int max_votes = 0;
    //loop through to find what the max_vote value is
    for (int i = 0; i < candidate_count - 1; i += 1)
        {
        if (candidates[i].votes > max_votes)
            {
            max_votes += (candidates[i].votes - max_votes);
            }
        }
    //loop through to see if multiple people have the same max_votes
    //if so, print their name with \n
    int j = 0; //counter for winner_s array indices
    for (int i = 0; i < candidate_count; i += 1)
        {
        //counter for winner_s array indices
        if (candidates[i].votes == max_votes)
            {
            printf("%s\n", candidates[i].name);
            }
        }
    }