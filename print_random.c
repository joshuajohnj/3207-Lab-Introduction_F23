#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char randchar(){
	char alphabet[26] = "abcdefghijklmnopqrstuvwxyz";
	
	int ranNum = (rand() +1) % 26;

	

	return alphabet[ranNum];
}


int main()
{
	int a;

	/* seed the randomizer */
	srand( (unsigned)time(NULL) );

	printf("Today's random word: ");
	for(a=0;a<7;a++)
		putchar(randchar());
	putchar('\n');

	return(0);
}

