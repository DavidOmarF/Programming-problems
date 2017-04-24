#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int numCases;
    scanf("%d", &numCases);
    for(int i = 0; i < numCases; i++){
        int pairs;
        scanf("%d", &pairs);
        printf("%d\n", pairs + 1);
    }
    
    return 0;
}
