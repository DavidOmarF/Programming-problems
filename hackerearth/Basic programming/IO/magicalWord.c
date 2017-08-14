// See original problem at:
// https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/magical-word/

#include <stdio.h>
#include <stdlib.h>

char getClosest(char a);
char *getWord(void);
int strlen(char* s);

int main(void)
{
    int tests = 0;
    scanf("%d", &tests);
    for (int test_i = 0; test_i < tests; test_i++)
    {
        char *word = getWord();
        for(int word_i = 0, word_l = strlen(word); word_i < word_l; word_i++)
        {
            word[word_i] = getClosest(word[word_i]);
            printf("%c", word[word_i]);
        }printf("\n");
    }
}

char getClosest(char a)
{
    
    if(a >= 'A' && a <= 'Z'){
        int upperPrimes[] = {67, 71, 73, 79, 83, 89};
        if(a < upperPrimes[0]) return upperPrimes[0];
        for(int upper_i = 1; upper_i < 6; upper_i++)
        {
            if(a < upperPrimes[upper_i]){
                if(a - upperPrimes[upper_i - 1] <= upperPrimes[upper_i] - a) return upperPrimes[upper_i - 1];
            }
        }
        return upperPrimes[5];
    }

    else if(a >= 'a' && a <= 'z'){
        int lowerPrimes[] = {97, 101, 103, 107, 109, 113};
        if(a < lowerPrimes[0]) return lowerPrimes[0];
        for(int lower_i = 1; lower_i < 6; lower_i++)
        {
            if(a < lowerPrimes[lower_i]){
                if(a - lowerPrimes[lower_i - 1] <= lowerPrimes[lower_i] - a) return lowerPrimes[lower_i - 1];
            }
        }
        return lowerPrimes[5];
    }
    else if(a < 'A') return 67;
    else if(a > 'z') return 113;
    else if(a > 'Z' && a < 'a'){
        if(a - 89 <= 97 - a) return 89;
        else return 97;
    }
    return a;
}

int strlen(char* s)
{
    int i = 0; 
    while(s[i] != '\0'){
        i++;
    }
    return i;
}

char *getWord(void)
{
    int l;
    scanf("%d", &l);
    l++;
    char *s = (char *)malloc(sizeof(char) * l);
    scanf("%s", s);
    return s;
}

