#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void RotateArray(int* numbers, int size, int rotations);

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    
    int size, rotations;
    
    scanf("%d", &size);
    scanf("%d", &rotations);
    
    rotations = rotations % size;
    
    int* numbers;
    numbers = malloc(size*(sizeof(int)));
    
    for(int i = 0; i < size; i++){
        scanf("%d", &numbers[i]);
    }
    
    RotateArray(numbers, size, rotations);
    
    for(int i = 0; i < size; i++){
        printf("%d ", numbers[i]);
    }
    return 0;
}

void RotateArray(int* numbers, int size, int rotations){
    
    int auxiliar[size];
		
	for (int i = 0; i < size; i++){
		auxiliar[i] = numbers[i];
	}

	for(int i = 0; i < size; i++){
        
        numbers [i] = auxiliar [(i + rotations) % (size)];
        
	}
    
    return;
    
}
