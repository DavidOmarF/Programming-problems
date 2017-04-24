#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int numCases;
    
    scanf("%d",&numCases);
    
    for(int i = 0; i < numCases; i++){
        int numPeople; 
        scanf("%d",&numPeople);
        printf("%d\n", (numPeople * (numPeople - 1)) / 2);
        
    }
    return 0;
}
