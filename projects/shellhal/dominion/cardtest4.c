#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>
#include "dominion_helpers.h"
#include "rngs.h"
#include "interface.h"
#include <math.h>
#include <assert.h>

/*quick adventurer test*/

int main(){

	int players = 2;
	int random_seed = 3;
	int results = 0;

	struct gameState G;

  	int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  //Test game initialized correctly
  	int i = initializeGame(2, k, random_seed, &G);
  	if(i != 0)
  		printf("Initialization fail\n");

	int choice = 0;
	buyCard(smithy, &G);
	int bonus;
	//int results = cardEffect(adventurer, choice, choice, choice, &G, 0, &bonus);
	if(results == 0){
		printf("CARD EFFECT PASS\n");
	}
	else printf("CARD EFFECT FAIL\n");

	return 0;
}
