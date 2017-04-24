#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int NumRepetitions(char** stringList, char* numQueries, int numStrings);

int main() {

    int numStrings, numQueries;
    
    scanf("%d", &numStrings);
    
    
    // Pointers thing, ignore it.
    char** stringList;
    stringList = malloc(numStrings * 21 * sizeof(char*) );
    
    for(int i = 0; i < numStrings; i++){
        stringList[i]= malloc(21 * sizeof(char));
    }
    
        
    // Input of strings 
    for(int i = 0; i < numStrings; i++){
        scanf("%s", stringList[i]);
    }
    
    
    scanf("%d", &numQueries);
    
    
    // More pointers thing, ignore it.
    char** queriesList;
    queriesList = malloc(numStrings * 21 * sizeof(char*) );

    for(int i = 0; i < numQueries; i++){
        queriesList[i]= malloc(21 * sizeof(char));
    }
    
    
    // Input of strings
    for(int i = 0; i < numQueries; i++){
        scanf("%s", queriesList[i]);
    }
    
    
    
    for(int i = 0; i < numQueries; i++){
        printf("%i\n", NumRepetitions(stringList, queriesList[i], numStrings));
    }
    
    return 0;
}


int NumRepetitions(char** stringList, char* querie, int numStrings){
    
    int repetitions = 0;
    for(int i = 0; i < numStrings; i++){
        
        int coincidences = 0;
        
        if(strlen(querie) == strlen(stringList[i])){
            
            for(int j = 0, n = strlen(querie); j < n; j++)
                if(stringList[i][j] == querie[j])
                    coincidences ++;
            
        }
        
        if (coincidences == strlen(querie))
                repetitions++;
        
    }
    return repetitions;
}
