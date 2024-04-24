#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CANDIDATES 100
// Candidate structure
typedef struct
{
    int id;
    char name[50];
    int votes;
} Candidate;
// Voter structure
typedef struct
{
    int id;
    int votedCandidateId;
    int hasVoted;
} Voter;

// Function to initialize candidates
void initializeCandidates(Candidate candidates[], int count)
{
    for (int i = 0; i < count; i++)
    {
        candidates[i].id = i + 1;
        candidates[i].votes = 0;
        sprintf(candidates[i].name, "Candidate %d", candidates[i].id);
    }
}
// Function to display candidates
void displayCandidates(Candidate candidates[], int count)
{
    printf("Candidates: \n");
    for (int i = 0; i < count; i++)
    {
        printf("%d. %s Votes: %d\n", candidates[i].id, candidates[i].name, candidates[i].votes);
        printf("\n");
    }
}

// Function to cast vote
void castVote(Voter voters[], Candidate candidates[], int voterId, int candidateId, int voterCount, int candidateCount)
{
    if (voterId < 1 || voterId > voterCount || voters[voterId - 1].hasVoted)
    {
        printf("Invalid voter ID or voter has already voted.\n");
        return;
    }
    if (candidateId < 1 || candidateId > candidateCount)
    {
        printf("Invalid candidate ID.\n");
        return;
    }

    candidates[candidateId - 1].votes++;
    voters[voterId - 1].votedCandidateId = candidateId;
    voters[voterId - 1].hasVoted = 1;
    printf("Vote cast successfully!\n");
}

int main()
{
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[] = {
        {1, 0, 0}, // Voter 1
        {2, 0, 0}, // Voter 2
        {3, 0, 0}, // Voter 3
    };
    // Add more voters as needed
    int candidateCount = 5;                              // Change as needed
    int voterCount = sizeof(voters) / sizeof(voters[0]); // Automatically determines voter count
    initializeCandidates(candidates, candidateCount);
    int choice, voterId, candidateId;
    // Simulating a basic menu-driven system
    do
    {
        printf("1. Display Candidates\n");
        printf("2. Cast Vote\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                displayCandidates(candidates, candidateCount);
                break;
            case 2:
                printf("Enter your voter ID: ");
                scanf("%d", &voterId);
                printf("Enter the candidate ID you want to vote for: ");
                scanf("%d", &candidateId);
                castVote(voters, candidates, voterId, candidateId, voterCount, candidateCount);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);
    return 0;
}