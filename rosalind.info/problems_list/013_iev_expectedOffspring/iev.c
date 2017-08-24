// For problem background, go to:
// http://rosalind.info/problems/iev/

#include <stdio.h>

int main(void)
{
    FILE *fpInput = fopen("rosalind_iev.txt", "r");
    FILE *fpOutput = fopen("rosalind_iev_out.txt", "w");
    int AA_AA, AA_Aa, AA_aa, Aa_Aa, Aa_aa, aa_aa;
    fscanf(fpInput, "%d %d %d %d %d %d", &AA_AA, &AA_Aa, &AA_aa, &Aa_Aa, &Aa_aa, &aa_aa);
    int prob100 = AA_AA + AA_Aa + AA_aa;
    fprintf(fpOutput, "%.2f", (prob100 + Aa_Aa * .75 + Aa_aa * .5) * 2);
}