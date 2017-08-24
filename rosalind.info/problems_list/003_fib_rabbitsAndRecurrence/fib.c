// For problem background, go to:
// http://rosalind.info/problems/fib/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


void printArray(uint64_t* arr, int size);

int main (void){

    // open input and output files
    FILE * fpInput = fopen("rosalind_fib.txt", "r");
    FILE * fpOutput = fopen("rosalind_fib_out.txt", "w");

    // scan months <= 40, and litter <= 5
    int months, litter;
    while(feof(fpInput) == 0){
        fscanf(fpInput, "%d", &months);
        fscanf(fpInput, "%d", &litter);
    }

    // create array and initialize first two values
    uint64_t *sequence = (uint64_t *) malloc(months * sizeof(uint64_t));
    sequence[0] = 1;
    sequence [1] = 1;

    // calculate full sequence
    for(int i = 2; i < months; i++){
        sequence[i] = sequence[i-1] + sequence[i - 2] * litter;
    }

    // print final value
    fprintf(fpOutput, "%llu", sequence[months - 1]);

    return 0;
}
