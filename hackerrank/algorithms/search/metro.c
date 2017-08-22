// See original problem at:
// https://www.hackerrank.com/challenges/gridland-metro

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int start; 
    int end;
} Track_t;

int main (void)
{
    FILE *fp = fopen("metro.txt", "r");
    int numRows, numColumns, numTracks;
    fscanf(fp, "%d %d %d", &numRows, &numColumns, &numTracks);

    Track_t *tracks = (Track_t *) malloc(sizeof(Track_t) * numTracks);

    // Scans **every track and stores each one in a Track_t type
    // for(int tracks_i = 0; tracks_i < numTracks; tracks_i++)
    // {
    //     fscanf(fp, "%d %d %d", &tracks[tracks_i].row, &tracks[tracks_i].start, &tracks[tracks_i].end);
    // }

    // for()
    fclose(fp);


}