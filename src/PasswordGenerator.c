#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CHARS 68 

void generate_combination(int num_chars_per_group, int num_groups, FILE* file) {
    int i, j;
    char characters[NUM_CHARS] = "ABCDEFGHIJKLMNIOPQRSTVWXYZ1234567890!@#$";
    for (i = 0; i < num_groups; i++) {
        for (j = 0; j < num_chars_per_group; j++) {
            fprintf(file, "%c", characters[rand() % NUM_CHARS]);
        }
        fprintf(file, "\n");
    }
}

int main() 
{
    int num_chars_per_group, num_groups, num_runs;

    FILE* file;

    srand(time(0)); 

    printf("Enter number of characters per group: ");
    scanf("%d", &num_chars_per_group);

    printf("Enter number of groups: ");
    scanf("%d", &num_groups);

    printf("Enter number of runs: ");
    scanf("%d", &num_runs);

    file = fopen("combinations.spha", "w");

    if (file == NULL) 
    {
        printf("Error opening file!\n");
    }

    int i;

    for (i = 0; i < num_runs; i++) 
    {
        generate_combination(num_chars_per_group, num_groups, file);
    }

    fclose(file);
}


