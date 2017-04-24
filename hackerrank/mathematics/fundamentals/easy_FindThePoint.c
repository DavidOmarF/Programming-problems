#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int numPairs;
    scanf("%d", &numPairs);
    
    int pairs [numPairs][4];
    
    for(int i = 0; i < numPairs; i++)
        for(int j = 0; j < 4; j++)
            scanf("%d", &pairs[i][j]);
        
    for(int i = 0; i < numPairs; i++)
        printf("%d %d\n", 2 * pairs[i][2] - pairs[i][0], 2 * pairs[i][3] - pairs[i][1]);
    
    
    return 0;
}
