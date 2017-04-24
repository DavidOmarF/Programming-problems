#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void Initialize(int* types, int numBirds);
int maxIndex(int* types, int numBirds);


int main(){
    
    int numBirds; 
    scanf("%d",&numBirds);
    
    int* types;
    types = malloc(5 * sizeof(int));
    
    Initialize(types, 5);
    
    for(int i = 0; i < numBirds; i++){
        int type;
        scanf("%d",&type);
        types[type - 1]++;
    }
    
    printf("%d", maxIndex(types, 5));
    
        
    
    return 0;
}

int maxIndex(int* types, int size){
    int max = 0;
    int maxIndex = 0;
    for(int i = 0; i < size; i++){
        if(types[i] > max){
            max = types[i];
            maxIndex = i;
        }
    }
    
    return maxIndex + 1;
}

void Initialize(int* types, int size){
    for(int i = 0; i < size; i++){
        types[i] = 0;
    }
}
