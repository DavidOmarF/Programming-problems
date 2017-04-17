#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int TotalCost(double mealCost, int tipPercent, int taxPercent);

int main() {
    
    double mealCost = 0.0;
    int tipPercent = 0;
    int taxPercent = 0;
    
    scanf("%lf", &mealCost);
    scanf("%d", &tipPercent);
    scanf("%d", &taxPercent);
    
    printf("The total meal cost is %d dollars.", TotalCost(mealCost, tipPercent, taxPercent));
    return 0;
}

int TotalCost(double mealCost, int tipPercent, int taxPercent){
    return round((1.0 + (float)(tipPercent + taxPercent)/100.0) * mealCost);
}
