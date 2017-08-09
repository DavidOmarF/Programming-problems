#include <stdio.h>

#define MOST_STRINGS 10

typedef struct
{
    char ID[14];
    char string[1001] ;
} DNAString;

void getDNAString(FILE *fp, char* s);

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

    for (int i = 0; i < numStrings; i += 1)
    {
        puts(strings[i].ID);
        puts(strings[i].string);
    }
    return 0;
}

void getDNAString(FILE *fp, char* s)
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