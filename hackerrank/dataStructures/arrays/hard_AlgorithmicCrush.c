#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


long maxValue(long* list, long listSize);
void initializeList(long * list, long listSize);
void doOperations(long* list, long lowerBound, long upperBound, long summand);


int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    long listSize, numOperations;
    
    scanf("%lu", &listSize);
    scanf("%lu", &numOperations);
    
    long* list;
    list = malloc(listSize * (sizeof(long)) );
    
    initializeList(list, listSize);
    
    
    for(long i = 0; i < numOperations; i++){
        
        long lowerBound, upperBound, summand;

        scanf("%lu", &lowerBound);
        scanf("%lu", &upperBound);
        scanf("%lu", &summand);
        
        doOperations(list, lowerBound - 1, upperBound - 1, summand);
    }
    
    printf("%lu", maxValue(list, listSize));

    return 0;
}

long maxValue(long* list, long listSize){
    long maxValue = list[0];
    for(long i = 0; i < listSize; i++)
        if(list[i] > maxValue)
            maxValue = list[i];

    return maxValue;
}

void initializeList(long* list, long listSize){
    
    for(long i = 0; i < listSize; i++){
        list[i] = 0;
    }
    
    return;
}


void doOperations(long* list, long lowerBound, long upperBound, long summand){
    
    for(long i = lowerBound; i <= upperBound; i++){
        list[i] += summand;
    }
    
    return;
}
