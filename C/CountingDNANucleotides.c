#include <stdio.h>
#include <string.h>

int main (){
	char string [1000];
	int t [4] = {0, 0, 0, 0}, i = 0;
	gets(string);
	for ( ; i < strlen(string); i++){
		if (string[i] == 'A')
			t[0]++;
		else if (string [i] == 'C')
			t[1]++;
		else if (string [i] == 'G')
			t[2]++;
		else if (string [i] == 'T')
			t[3]++;
	}
	printf("%d %d %d %d", t[0], t[1], t[2], t[3]);	
}
