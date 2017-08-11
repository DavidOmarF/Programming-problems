// For problem background, go to:
// http://rosalind.info/problems/iprb/

#include <stdio.h>

int main(void)
{
    FILE *fpInput = fopen("rosalind_iprb.txt", "r");
    FILE *fpOutput = fopen("rosalind_iprb_out.txt", "w");

    // I declared these as floats to avoid casts in math step
    float homoDominant, homoRecessive, hetero;
    fscanf(fpInput, "%f %f %f", &homoDominant, &hetero, &homoRecessive);
    float total = homoDominant + hetero + homoRecessive;

    float type100 = (homoDominant / total) + (hetero / total) * (homoDominant / (total - 1)) + (homoRecessive / total) * (homoDominant / (total - 1));
    float type75 = (hetero / total) * ((hetero - 1) / (total - 1)) * .75;
    float type50 = ((hetero / total) * (homoRecessive / (total - 1)) + (homoRecessive / total) * (hetero / (total - 1))) * .5;

    float answer = type100 + type75 + type50;
    fprintf(fpOutput, "%.5f", answer);

    fclose(fpInput);
    fclose(fpOutput);
}
