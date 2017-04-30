#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    char* s = (char *)malloc(82 * sizeof(char));
    scanf("%s",s);
    
    int len = strlen(s), 
        rows = floor(sqrt(len)),
        cols = ceil(sqrt(len));
    
    if(rows * cols < len)
        rows++;
           
    for(int cols_i = 0; cols_i < cols; cols_i++){
        for(int rows_i = 0; rows_i < rows; rows_i++){
            
            if(rows_i * cols + cols_i >= len)
                break;
            
            printf("%c", s[rows_i * cols + cols_i]);
        }
        printf(" ");
    }
    
    return 0;
}
