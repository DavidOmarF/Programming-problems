#include <stdio.h>

int main(void)
{
    int n = 0;
    int count = 0;
    scanf("%d", &n);
    if (n <= 0)
        return 1;
    if (n > 512)
        return 2;
    for (int c = 1; c <= n; c++)
        for (int b = 1; b <= c; b++)
            for (int a = 1; a <= b; a++)
                if (a * a + b * b == c * c)
                    count++;
    printf("%d", count);
    return 0;
}