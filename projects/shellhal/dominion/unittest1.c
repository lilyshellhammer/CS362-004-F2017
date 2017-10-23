#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>
#include "rngs.h"
#include "interface.h"
#include <assert.h>



int test_drawCard(int player, struct gameState *post){
	struct gameState pre;
	memcpy(&pre, post, sizeof(struct gameState));
	struct gameState temp;
	memcpy(&temp, post, sizeof(struct gameState));

	/*FIRST CHECK IF ILLEGAL DRAW IS ALLOWED*/
	temp.deckCount[0] = 0;
	int u = drawCard(player, &temp);
	if (u == -1 ){
		printf("ILLEGAL DRAWCARD TEST PASSED");
	}
	

	int b = drawCard(player, &post);
	if(b == 0){
		printf("DRAWCARD RETURN TYPE PASSED");
	}
	if( (post->deckCount[0] == (pre.deckCount[0]-1)) && (post->handCount[0] == (pre.handCount[0]+1)) ){
		printf("DRAWCARD AMOUNT PASSED");
	}
	else
		printf("DRAWCARD AMOUNT FAILED\n");
}

int main(){
	int random_seed = 3;
	int bonus = 0;
	int player = 0;
	int deckCounter;

	//int i, j;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

	struct gameState G;

  	initializeGame(2, k, random_seed, &G);
	printf ("Testing drawCard\n");

	
	test_drawCard(player, &G);
	return 0;
}

