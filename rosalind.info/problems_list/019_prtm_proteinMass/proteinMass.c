#include <stdio.h>
#include <stdlib.h>

void scanString(FILE *fp, char *string, int *stringSize);
int CombinationsRNA(char *string, int size);
int getValue(char a);

int main(void)
{
    // open files
    FILE *fpInput = fopen("rosalind_mrna.txt", "r");
    FILE *fpOutput = fopen("rosalind_mrna_out.txt", "w");

    // create and scan string
    char *string = malloc(1001 * sizeof(char));
    int stringSize;
    scanString(fpInput, string, &stringSize);

    // calcualte possible combinations
    int combinations = CombinationsRNA(string, stringSize);
    fprintf(fpOutput, "%d", combinations);

    return 0;
}

int CombinationsRNA(char *string, int size)
{
    int combinations = 1;
    for (int i = 0; i < size; i++)
    {
        combinations *= getValue(string[i]);
        combinations = combinations % 1000000;
    }
    return combinations;
}

int getValue(char a)
{
    if (a == 'W' || a == 'M')
        return 1;
    if (a == 'Y' || a == 'C' || a == 'H' || a == 'Q' || a == 'N' ||
        a == 'K' || a == 'D' || a == 'E' || a == 'F')
        return 2;
    if (a == 'I' || a == '\0')
        return 3;
    if (a == 'P' || a == 'T' || a == 'V' || a == 'A' || a == 'G')
        return 4;
    if (a == 'L' || a == 'S' || a == 'R')
        return 6;
}

void scanString(FILE *fp, char *string, int *stringSize)
{
    int i = 0;
    while (feof(fp) == 0)
    {
        fscanf(fp, "%c", &string[i]);
        i++;
    }
    string[i - 1] = '\0';
    *stringSize = i;
    return;
}