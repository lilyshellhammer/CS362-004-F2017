#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>
#include "rngs.h"
#include "interface.h"


int main(){
	int random_seed = 3;
	int bonus = 0;
	int player = 0;
	int deckCounter;
	int i, n, r, p, deckCount, discardCount, handCount;
	//int i, j;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

	struct gameState G;

  	initializeGame(2, k, random_seed, &G);
	printf ("Testing DrawCard\n");


	SelectStream(2);
	PutSeed(3);

	for (n = 0; n < 2000; n++) {
		for (i = 0; i < sizeof(struct gameState); i++) {
		  ((char*)&G)[i] = floor(Random() * 256);
		}
		p = floor(Random() * 2);
		G.deckCount[p] = floor(Random() * MAX_DECK);
		G.discardCount[p] = floor(Random() * MAX_DECK);
		G.handCount[p] = floor(Random() * MAX_HAND);
		//checkDrawCard(p, &G);
	}
	//test_playCard(player, &G);
	return 0;
}
