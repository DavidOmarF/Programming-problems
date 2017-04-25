#include <stdio.h>

int main(){
    
    
    int numHurdles; 
    int maxHeight; 
    scanf("%d %d", &numHurdles, &maxHeight);
    
    int originalHeight = maxHeight;
    
    int *hurdles;
    hurdles = malloc(sizeof(int) * numHurdles);
    
    for(int i = 0; i < numHurdles; i++){
       scanf("%d", &hurdles[i]);
       if(hurdles[i] > maxHeight){
           maxHeight += hurdles[i] - maxHeight;
       }
    }
    
    printf("%d", maxHeight - originalHeight);
    
    return 0;
}
