// For problem background, go to:
// http://rosalind.info/problems/cons/

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
char chooseNucleotide(int **matrix, int i);
int main(void)
{
    FILE *fpInput = fopen("rosalind_cons.txt", "r");
    FILE *fpOutput = fopen("rosalind_cons_out.txt", "w");

    DNAString strings[MOST_STRINGS];
    int numStrings = 0;

    for (;numStrings < MOST_STRINGS; numStrings++)
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

    char *consString = malloc(sizeof(char) * (dnaLength + 1));
    consString[dnaLength] = '\0';

    for (int i = 0; i < dnaLength; i++)
    {
        consString[i] = chooseNucleotide(matrix, i);
    }
    fputs(consString, fpOutput);
    fprintf(fpOutput, "\n");
    for(int i = 0; i < 4; i++){
        if(i == 0) fprintf(fpOutput, "A: ");
        if(i == 1) fprintf(fpOutput, "C: ");
        if(i == 2) fprintf(fpOutput, "G: ");
        if(i == 3) fprintf(fpOutput, "T: ");
        for(int j = 0; j < dnaLength; j++){
            fprintf(fpOutput, "%d ", matrix[j][i]);
        }
        fprintf(fpOutput, "\n");
    }
    return 0;
}

char chooseNucleotide(int **matrix, int i){
    int max = 0;
    int pos = 0;
    for(int j = 0; j < 4; j++)
    {
        if(matrix[i][j] > max){
            max = matrix[i][j];
            pos = j;
        }
    }
    if(pos == 0) return 'A';
    if(pos == 1) return 'C';
    if(pos == 2) return 'G';
    if(pos == 3) return 'T';
    return 'E';
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