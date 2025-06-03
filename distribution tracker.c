#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// I used a typedef struct to avoid the use of the word 'struct'
// in the main function.

// I also used indexing rather than arrow operator to
// access the array of structs.

typedef struct {
    // proper struct padding
    int members;
    int purok;
    int relief_packs;
    char head_name[80];
} Households;

void display_recipents(Households *brgy_recipents, int n);
int num_of_reliefs(Households *brgy_recipents, int n);

int main()
{
    int num;

    printf("Enter number of households to record: ");
    scanf("%d", &num);

    Households *recipents = (Households*)malloc(num * sizeof(Households));

    if (!recipents) {
        printf("Memory Allocation Failed.\n");
        return 1;
    }

    for (int i = 0; i < num; i++) {
        printf("\n--- Household #%d ---\n", i + 1);
        printf("Name of Head of Household: ");
        // Input Handling for Newline
        while (getchar() != '\n');
        fgets(recipents[i].head_name, sizeof(recipents[i].head_name), stdin);
        recipents[i].head_name[strcspn(recipents[i].head_name, "\n")] = '\0';
        printf("Number of Members: ");
        scanf("%d", &recipents[i].members);
        printf("Purok: ");
        scanf("%d", &recipents[i].purok);
        printf("Number of Relief Packs: ");
        scanf("%d", &recipents[i].relief_packs);
    }

    display_recipents(recipents, num);

    free(recipents);

    return 0;
}

void display_recipents(Households *brgy_recipents, int n)
{
    int total = num_of_reliefs(brgy_recipents, n);

    printf("\n\n==== Relief Distribution List ====\n\n");
    for (int i = 0; i < n; i++) {
        printf("Household #%d:\n", i + 1);
        printf("Head: %s\n", brgy_recipents[i].head_name);
        printf("Members: %d\n", brgy_recipents[i].members);
        printf("Purok: %d\n", brgy_recipents[i].purok);
        printf("Relief Packs: %d\n", brgy_recipents[i].relief_packs);
        printf("\n");
    }
    printf("Total number of relief packs distributed: %d\n", total);
}

int num_of_reliefs(Households *brgy_recipents, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += brgy_recipents[i].relief_packs;
    }
    return sum;
}

