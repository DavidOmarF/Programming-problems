#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char* s = (char *)malloc(100001 * sizeof(char));
    scanf("%s",s);
    
    long numWords = 1;
    
    for(long i = 0, n = strlen(s); i < n; i++)
        if(s[i] >= 'A' && s[i] <= 'Z')
            numWords++;
    
    printf("%lu", numWords);
    
    return 0;
}
