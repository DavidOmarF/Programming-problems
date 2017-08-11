// For problem background, go to:
// http://rosalind.info/problems/gc/

#include <stdio.h>

typedef struct
{
    char ID[14];
    float string;
} DNAString;

void getID(FILE *fp, char *string);
void printDNAString(DNAString *DNAStrings, int DNAStrings_i, FILE *fp);
void scanStrings(FILE *fp, DNAString *DNAStrings, int *DNAStrings_i);

int main(void)
{
    // open file with DNA Strings in FASTA
    FILE *fpInput = fopen("rosalind_gc.txt", "r");
    FILE *fpOutput = fopen("rosalind_gc_out.txt", "w");

    // array of DNAStrings (10 max), and an index which will represent
    // the actual number of strings scanned
    DNAString DNAStrings[10];
    int DNAStrings_i = 0;

    // scan strings and assign its values to the array
    scanStrings(fpInput, DNAStrings, &DNAStrings_i);

    // print the DNA string with the max CG content
    printDNAString(DNAStrings, DNAStrings_i, fpOutput);

    // close files
    fclose(fpInput);
    fclose(fpOutput);
}

void printDNAString(DNAString *DNAStrings, int DNAStrings_i, FILE *fp)
{
    // selects the string with the maximum cg content
    int max_i = 0;
    float max = 0.0;
    for (int i = 0; i < DNAStrings_i; i++)
    {
        if (DNAStrings[i].string > max)
        {
            max = DNAStrings[i].string;
            max_i = i;
        }
    }

    // and prints it
    fprintf(fp, "%s\n%f\n", DNAStrings[max_i].ID, DNAStrings[max_i].string);
}

void getID(FILE *fp, char *string)
{
    // scans full ID
    for (int j = 0; j < 13; j++)
    {
        fscanf(fp, "%c", &string[j]);
    }

    // add null character to end of string
    string[13] = '\0';
    return;
}

void scanStrings(FILE *fp, DNAString *DNAStrings, int *i)
{
    int DNAStrings_i = *i, total = 0, cgCount = 0;
    // scans whole file to the end
    while (feof(fp) == 0)
    {
        // scans one single char
        char temp;
        fscanf(fp, "%c", &temp);

        // '>' represents the start of the string ID
        if (temp == '>')
        {
            getID(fp, DNAStrings[DNAStrings_i].ID);
            // calculate CG content of the **previous** ID
            if (DNAStrings_i)
                DNAStrings[DNAStrings_i - 1].string = ((float)cgCount / total * 100);
            DNAStrings_i++;
            cgCount = 0;
            total = 0;
            continue;
        }

        // proceed only if it's a MAYUS char (to avoid new line char)
        if (temp >= 'A' && temp <= 'Z')
        {
            total++;
            if (temp == 'G' || temp == 'C')
                cgCount++;
        }
    }
    // calculate CG content of last ID
    DNAStrings[DNAStrings_i - 1].string = ((float)cgCount / total * 100);

    // updates the original variable sent
    *i = DNAStrings_i;
}
