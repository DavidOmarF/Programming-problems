// See original problem at:
// https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/magical-word/

#include <stdio.h>

int main(void)
{
    int upperPrimes [] = { 67, 71, 73, 79, 83, 89 };
    int lowerPrimes []= { 97, 101, 103, 107, 109, 113 };
    for(int i = 0; i < 6; i++){
        printf("%c ", upperPrimes[i]);
    } printf("\n");
    for (int i = 0; i < 6; i++){
        printf("%c ", lowerPrimes[i], lowerPrimes[i]);
    }
}