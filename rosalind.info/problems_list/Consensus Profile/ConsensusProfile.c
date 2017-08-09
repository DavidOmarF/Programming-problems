#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MOST_STRINGS 10

char *getDNAString(FILE *fp);


int main(void)
{
    FILE *fpInput = fopen("rosalind_cons.txt", "r");
    char **DNAStrings = malloc(sizeof(char) * MOST_STRINGS);
    for (int i = 0; i < MOST_STRINGS * 2; i++)
    {
        DNAStrings[i] = getDNAString(fpInput);
    }

    return 0;
}

char *getDNAString(FILE *fp)
{
    char* string = malloc(sizeof(char) * 1001);
    for(int i = 0; ;i++){
        fscanf(fp, "%c", &string[i]);
        if(string[i] == 10 || feof(fp)){
            string[i] == '\0';
            break;
        }
    }
    return string;
}