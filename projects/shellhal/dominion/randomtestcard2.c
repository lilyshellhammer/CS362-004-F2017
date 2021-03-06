#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <string.h>

#include "dominion.h"
#include "rngs.h"
#include "dominion_helpers.h"
#include "interface.h"

#define DEBUG 0
#define NOISY_TEST 1


/* Name: Main
 * Description: Initializes game, test embargo with random arrangements of deck
 * 			to try and find places where return type doesn't match with whether or
 *			not embargo can actually be played on user's choice1.
 * Testing for: Tests that return type matches expected
 */
int main()
{
	/*DEFINITIONS*/
	int random_seed = 3;
	int num_players = 2;
	int n, i, j, player;
	int temp;
	int amount_cards, handPos;
	int flag = 0;
	int kingdom[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};
	struct gameState G;

	/*INITIALIZE GAME*/
  	initializeGame(num_players, kingdom, random_seed, &G);
	
	/*START RANDOMIZATION*/
	printf ("RANDOM TESTS.\n");
	SelectStream(2);
	PutSeed(3);
	/*SET UP RANDOM VALUES*/
	for (n = 0; n < 100; n++) 
	{
	    for (i = 0; i < sizeof(struct gameState); i++) 
	    {
	    	((char*)&G)[i] = floor(Random() * 256);
		}
	    player = floor(Random() * num_players);
	    G.deckCount[player] = floor(Random() * MAX_DECK);
	    G.discardCount[player] = floor(Random() * MAX_DECK);
	    G.handCount[player] = floor(Random() * (MAX_HAND-3));
		/*ADD 4 RANDOM CARDS TO INITIALIZE TURN*/
		for(j = 0; j <  10 ; j++)
		{
			G.hand[player][j] = floor(Random() * 27);
		}
		/*SET UP EMBARGO TO BE PLAYED*/
		handPos = 0;
		G.hand[player][handPos] = embargo;

		/*SET UP ROUND*/
		G.whoseTurn = player;
		G.outpostPlayed = player;
  		G.phase = 0;
  		G.numActions = 1;

		/*TEST PLAYING EMBARGO CARD*/
		temp = playCard(handPos, G.hand[player][1], G.hand[player][2], G.hand[player][3], &G);
		if((G.supplyCount[G.hand[player][1]] == -1 ) && (temp != -1)){
      		flag += 1;
		}
		if((G.supplyCount[G.hand[player][1]] != -1 ) && (temp != 0)){
			flag += 1;
		}

	}
	/*PRINT MESSAGES DEPENDING ON IF ERRORS OR NOT*/
	if(flag != 0){
		printf("ERROR: Incorrect return type! Occured: %d time(s).\n", flag);
	}
	else{
		printf("ALL RETURN TYPE TESTS PASSED\n");
	}


	return 0;
}
    