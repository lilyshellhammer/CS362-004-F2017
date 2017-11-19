#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>
#include "dominion_helpers.h"
#include "interface.h"
#include "rngs.h"
#include <math.h>
#include <assert.h>

/*My test mine function*/

int test_smithy(int choice1, int choice2, int choice3, int handPos, int player, struct gameState *post){
	post->phase == 0;
	post->numActions = 1;
	struct gameState pre;
	memcpy(&pre, post, sizeof(struct gameState));
	

	int i = playCard(handPos, 0, 0, 0, post);
	if(i != 0)
		printf("testsmithy return value is: %d\n", i);

	// Draw 3 cards
    drawCard(player, &pre);
    drawCard(player, &pre);
    drawCard(player, &pre);
	//assert(i == 0);
	discardCard(handPos, player, &pre, 1);
	if(sizeof(pre) != sizeof(post)){
		printf("SMITHY SIZE TEST FAIL\n");
	}
	return 0;
}

int main(){
	int random_seed = 3;
	struct gameState G;
	int player = 0;
	int n, i, p;
	//int i, j;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};


  	initializeGame(2, k, random_seed, &G);
	printf ("Testing Smithy\n");
	for (n = 0; n < 2000; n++) {
		for (i = 0; i < sizeof(struct gameState); i++) {
		  ((char*)&G)[i] = floor(Random() * 256);
	}
		p = floor(Random() * 2);
		G.deckCount[p] = floor(Random() * MAX_DECK);
		G.discardCount[p] = floor(Random() * MAX_DECK);
		G.handCount[p] = floor(Random() * MAX_HAND);
	}
	test_smithy(0, 1, 2, 0, player, &G);

	return 0;
}
