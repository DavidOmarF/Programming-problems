#include <stdio.h>

void WhoWins(int catA, int catB, int mouse);

int main(){
    int numQueries; 
    scanf("%d",&numQueries);
    for(int i = 0; i < numQueries; i++){
        int catA; 
        int catB; 
        int mouse; 
        scanf("%d %d %d", &catA, &catB, &mouse);
        WhoWins(catA, catB, mouse);
    }
    return 0;
}



void WhoWins(int catA, int catB, int mouse){
    if( abs(catA - mouse) == abs(catB - mouse)){
        printf("Mouse C\n");
    } else if( abs(catA - mouse) > abs(catB - mouse)){
        printf("Cat B\n");
    } else {
        printf("Cat A\n");
    }
    return;
}
