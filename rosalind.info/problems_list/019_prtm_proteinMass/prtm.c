// For problem background, go to:
// http://rosalind.info/problems/prtm/

#include <stdio.h>
#include <stdlib.h>

void scanString(FILE *fp, char *string, int *stringSize);
double CalculateMass(char *string, int size);
double getValue(char a);

int main(void)
{
    // open files
    FILE *fpInput = fopen("rosalind_prtm.txt", "r");
    FILE *fpOutput = fopen("rosalind_prtm_out.txt", "w");

    // create and scan string
    char *string = malloc(1001 * sizeof(char));
    int stringSize;
    scanString(fpInput, string, &stringSize);

    // calcualte possible combinations
    double mass = CalculateMass(string, stringSize);
    fprintf(fpOutput, "%.9lf", mass);

    return 0;
}

double CalculateMass(char *string, int size)
{
    double mass = 0.0;
    for (int i = 0; i < size; i++)
        mass += getValue(string[i]);
    return mass;
}

double getValue(char a)
{
    if (a == 'A') return 71.03711;
    if (a == 'C') return 103.00919;
    if (a == 'D') return 115.02694;
    if (a == 'E') return 129.04259;
    if (a == 'F') return 147.06841;
    if (a == 'G') return 57.02146;
    if (a == 'H') return 137.05891;
    if (a == 'I') return 113.08406;
    if (a == 'K') return 128.09496;
    if (a == 'L') return 113.08406;
    if (a == 'M') return 131.04049;
    if (a == 'N') return 114.04293;
    if (a == 'P') return 97.05276;
    if (a == 'Q') return 128.05858;
    if (a == 'R') return 156.10111;
    if (a == 'S') return 87.03203;
    if (a == 'T') return 101.04768;
    if (a == 'V') return 99.06841;
    if (a == 'W') return 186.07931;
    if (a == 'Y') return 163.06333;
    return 0.0;
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
    *stringSize = i - 1;
    return;
}