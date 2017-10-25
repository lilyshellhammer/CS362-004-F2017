#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>
#include "rngs.h"
#include "interface.h"
#include <assert.h>

//BUGS:

//Province test pass, doesn't fail at the right time, but then when its supposed to end, doesn't end with 4
//people and 4 empty stacks.

int test_isGameOver(struct gameState *post){
	struct gameState pro;
	memcpy(&pro, post, sizeof(struct gameState));

	/*FIRST CHECK IF ILLEGAL DRAW IS ALLOWED*/
	pro.supplyCount[province] = 0;
	int u = isGameOver(&pro);
	assert(u == 1);
	printf("PROVINCE CHECK PASS\n");
	
	int i;
	for(i = 0; i < 26; i++){
		post->supplyCount[i] = 1;
	}
	post->supplyCount[4] = 0;
	post->supplyCount[5] = 0;
	post->supplyCount[6] = 0;

	u = isGameOver(&post);
	if(u == 1){
		printf("TOO EARLY ENDING FAIL\n");
	}
	post->supplyCount[7] = 0;
	
	u = isGameOver(&post);
	if(u == 1)
		printf("CORRECTLY ENDING WITH 4 PLAYERS\n");
	else
		printf("CORRECT ENDING FAILED\n");

	//TEST HERE: is to see if bugs in the way we check if 4! piles are emtpy
	
}

int main(){
	int random_seed = 3;
	int player_num = 4;
	int bonus = 0;
	int player = 0;
	int deckCounter;

	//int i, j;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

	struct gameState G;

  	initializeGame(player_num, k, random_seed, &G);
	printf ("Testing isGameOver\n");

	
	test_isGameOver(&G);
	return 0;
}
