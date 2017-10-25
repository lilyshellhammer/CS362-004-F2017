#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>
#include "dominion_helpers.h"
#include "rngs.h"
#include "interface.h"
#include <math.h>
#include <assert.h>


/*My test embargo function*/

int test_embargo(int choice1, int handPos, int currentPlayer, struct gameState *post){
	struct gameState pre;
	memcpy(&pre, post, sizeof(struct gameState));
	
	int i = playCard(embargo, choice1, -1, -1, post);

	if(post->coins == post->coins+2){
		printf("COIN INCREASE TEST PASSED\n");
	}
	else
		printf("COIN INCREASE TEST FAIL\n");

	if(post->embargoTokens[choice1] == pre.embargoTokens[choice1]+1) {
		printf("EMBARGO TOKEN INCREASE FAIL\n");
	}
	else printf("EMBARGO TOKEN INCREASE PASS\n");

	pre.embargoTokens[choice1]++;

	discardCard(handPos, currentPlayer, &pre, 0);
	if(memcmp(&pre, post, sizeof(struct gameState)) == 0){
		printf("EMBARGO PASS\n");
	}
	else printf("EMBARGO MEMORY FAIL\n");

	return 0;
}

int main(){
	int random_seed = 3;
	//int i, j;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

	struct gameState G;

  	initializeGame(2, k, random_seed, &G);
	printf ("Testing Embargo\n");

	int choice1 = 1;
	int embargoPos = 0;

	test_embargo(choice1, embargoPos, 0, &G);

	return 0;
}
