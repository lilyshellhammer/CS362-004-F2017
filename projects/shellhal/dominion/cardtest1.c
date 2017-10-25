#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>
#include "dominion_helpers.h"
#include "rngs.h"
#include "interface.h"
#include <math.h>
#include <assert.h>


/*My test mine function*/

int test_mine(int handPos, int currentPlayer, struct gameState *post){
	struct gameState pre;
	memcpy(&pre, post, sizeof(struct gameState));
	
	int i = playCard(mine, adventurer, gardens, gardens, post);

	if(i != 0){
		printf( "FALSE RETURN TEST PASS\n");
	}

	i = playCard(mine, copper, gold, copper, &pre);
	if(i == -1){
		printf( "FALSE RETURN TEST FAIL\n");
	}
	//assert(memcmp(&pre, post, sizeof(struct gameState)) == 0);
	return 0;
}

int main(){
	int random_seed = 3;
	//int i, j;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

	struct gameState G;

  	//initializeGame(2, k, random_seed, &G);
	printf ("Testing Mine\n");
	int minePos = 0;
	printf("Mine played from position %d\n", minePos);
	test_mine( 0, 0, &G);

	return 0;
}
