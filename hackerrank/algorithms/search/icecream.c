// See original problem at: 
// https://www.hackerrank.com/challenges/icecream-parlor

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    FILE *fp = fopen ("icecream.txt", "r");

    int trips;
    fscanf(fp, "%d", &trips);

    for(int trips_i = 0; trips_i < trips; trips_i++){
        int money, numFlavors;
        fscanf(fp, "%d %d", &money, &numFlavors);
        int *flavors = (int *) malloc(sizeof(int) * numFlavors);

        for(int flavors_i = 0; flavors_i < numFlavors; flavors_i++)
        {
            fscanf(fp, "%d", &flavors[flavors_i]);
        }

    }
}