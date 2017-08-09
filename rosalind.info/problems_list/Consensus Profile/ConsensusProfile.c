#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOST_STRINGS 10

typedef struct
{
    char ID[14];
    char string[1001];
} DNAString;

void getDNAString(FILE *fp, char *s);
void countNucleotides(DNAString *strings, int numStrings, int ith, int *nucleotides);

int main(void)
{
    FILE *fpInput = fopen("rosalind_cons.txt", "r");

    DNAString strings[MOST_STRINGS];
    int numStrings = 0;

    for (;; numStrings++)
    {
        getDNAString(fpInput, strings[numStrings].ID);
        getDNAString(fpInput, strings[numStrings].string);
        if (strings[numStrings].ID[0] == '\0' || strings[numStrings].string[0] == '\0')
            break;
    }
    int dnaLength = strlen(strings[0].string);
    int **matrix = malloc(sizeof(int *) * dnaLength);

    for (int i = 0; i < dnaLength; i++)
    {
        matrix[i] = calloc(sizeof(int), 4);
    }

    for (int i = 0; i < dnaLength; i++)
    {
        countNucleotides(strings, numStrings, i, matrix[i]);
    }
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < dnaLength; j++){
            printf("%d ", matrix[j][i]);
        }
        printf("\n");
    }

    return 0;
}

void countNucleotides(DNAString *strings, int numStrings, int ith, int *nucleotides)
{
    for (int i = 0; i < numStrings; i++)
    {
        if (strings[i].string[ith] == 'A')
        {
            nucleotides[0]++;
            continue;
        }
        if (strings[i].string[ith] == 'C')
        {
            nucleotides[1]++;
            continue;
        }
        if (strings[i].string[ith] == 'G')
        {
            nucleotides[2]++;
            continue;
        }
        if (strings[i].string[ith] == 'T')
        {
            nucleotides[3]++;
            continue;
        }
    }
    return;
}

void getDNAString(FILE *fp, char *s)
{
    int i = 0;
    do
    {
        fscanf(fp, "%c", &s[i]);
        i++;
        if (s[i - 1] == 10 || s[i - 1] == 13)
            break;
    } while (!feof(fp));
    s[i - 1] = '\0';
    return;
}