#include <stdio.h>
#include <stdlib.h>

void scanString(FILE *fp, char *string, int *size);
char getProtein(char *string, int i);

int main(void)
{
    // open files
    FILE *fpInput = fopen("rosalind_prot.txt", "r");
    FILE *fpOutput = fopen("rosalind_prot_out.txt", "w");

    char *string = (char *)malloc(10001 * sizeof(char));
    char *protein = (char *)malloc(3335 * sizeof(char));
    int stringSize = 0;
    scanString(fpInput, string, &stringSize);
    for (int string_i = 0, protein_i = 0; string_i < stringSize; string_i += 3)
    {
        protein[protein_i] = getProtein(string, string_i);
        if (protein[protein_i] == '\0')
            break;
        protein_i++;
    }

    fputs(protein, fpOutput);

    // close files
    fclose(fpInput);
    fclose(fpOutput);
}

char getProtein(char *string, int i)
{
    if (string[i] == 'U')
    {
        if (string[i + 1] == 'U')
        {
            if (string[i + 2] == 'U' || string[i + 2] == 'C')
                return 'F';
            return 'L';
        }
        if (string[i + 1] == 'C')
            return 'S';
        if (string[i + 1] == 'A')
        {
            if (string[i + 2] == 'U' || string[i + 2] == 'C')
                return 'Y';
            return '\0';
        }
        if (string[i + 1] == 'G')
        {
            if (string[i + 2] == 'U' || string[i + 2] == 'C')
                return 'C';
            if (string[i + 2] == 'G')
                return 'W';
            return '\0';
        }
    }

    if (string[i] == 'C')
    {
        if (string[i + 1] == 'U')
            return 'L';
        if (string[i + 1] == 'C')
            return 'P';
        if (string[i + 1] == 'A')
        {
            if (string[i + 2] == 'U' || string[i + 2] == 'C')
                return 'H';
            return 'Q';
        }
        if (string[i + 1] == 'G')
            return 'R';
    }

    if (string[i] == 'A')
    {
        if (string[i + 1] == 'U')
        {
            if (string[i + 2] == 'G')
                return 'M';
            return 'I';
        }
        if (string[i + 1] == 'C')
            return 'T';
        if (string[i + 1] == 'A')
        {
            if (string[i + 2] == 'U' || string[i + 2] == 'C')
                return 'N';
            return 'K';
        }
        if (string[i + 1] == 'G')
        {
            if (string[i + 2] == 'U' || string[i + 2] == 'C')
                return 'S';
            return 'R';
        }
    }

    if (string[i] == 'G')
    {
        if (string[i + 1] == 'U')
            return 'V';
        if (string[i + 1] == 'C')
            return 'A';
        if (string[i + 1] == 'A')
        {
            if (string[i + 2] == 'U' || string[i + 2] == 'C')
                return 'D';
            return 'E';
        }
        if (string[i + 1] == 'G')
            return 'G';
    }
    return '\0';
    
    // Dictionary
        // UUU F      CUU L      AUU I      GUU V
        // UUC F      CUC L      AUC I      GUC V
        // UUA L      CUA L      AUA I      GUA V
        // UUG L      CUG L      AUG M      GUG V
        // UCU S      CCU P      ACU T      GCU A
        // UCC S      CCC P      ACC T      GCC A
        // UCA S      CCA P      ACA T      GCA A
        // UCG S      CCG P      ACG T      GCG A
        // UAU Y      CAU H      AAU N      GAU D
        // UAC Y      CAC H      AAC N      GAC D
        // UAA Stop   CAA Q      AAA K      GAA E
        // UAG Stop   CAG Q      AAG K      GAG E
        // UGU C      CGU R      AGU S      GGU G
        // UGC C      CGC R      AGC S      GGC G
        // UGA Stop   CGA R      AGA R      GGA G
        // UGG W      CGG R      AGG R      GGG G
}

void scanString(FILE *fp, char *string, int *size)
{
    int i = 0;
    while (feof(fp) == 0)
    {
        fscanf(fp, "%c", &string[i]);
        i++;
    }
    string[i - 1] = '\0';
    *size = i;
    return;
}
