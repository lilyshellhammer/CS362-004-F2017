#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>


int test_updateCoins(int player, struct gameState *post){
	struct gameState pre;
	memcpy(&pre, post, sizeof(struct gameState));
	int u = updateCoins(player, post, 0);

	//reset coin count
	pre.coins = 0;


	if(u == 0){
		printf("BUYCARD TEST 1 PASSED");
	}
	if( memcmp(pre, post) == 0){
		printf("BUYCARD TEST 2 PASSED");
	}
}

int main(){
	int random_seed = 3;
	int bonus = 0;
	int player = 0;

	//int i, j;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

	struct gameState G;

  	initializeGame(2, k, random_seed, &G);

	test_updateCoins(player, &G);
	return 0;
}
