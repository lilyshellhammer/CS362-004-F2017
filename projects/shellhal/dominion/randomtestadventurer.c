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
 * Description: Initializes game, test adventurer with random numbers
 * Testing for: If any situation where playing adventurer with random cards will 
 * 			break adventurer functionality
 */
int main()
{
	/*DEFINITIONS*/
	int random_seed = 3;
	int num_players = 2;
	int n, i, j, player;
	int counter = 0;
	int temp;
	int amount_cards, handPos;
	int kingdom[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};
	struct gameState G;

	/*INITIALIZE GAME*/
  	initializeGame(num_players, kingdom, random_seed, &G);
	
	/*START RANDOMIZATION*/
	printf ("RANDOM TESTS.\n");
	SelectStream(2);
	PutSeed(3);

	for (n = 0; n < 1000; n++) 
	{
	    for (i = 0; i < sizeof(struct gameState); i++) 
	    {
	    	((char*)&G)[i] = floor(Random() * 256);
		}
	    player = floor(Random() * num_players);
	    G.deckCount[player] = floor(Random() * MAX_DECK);
	    G.discardCount[player] = floor(Random() * MAX_DECK);
	    G.handCount[player] = floor(Random() * MAX_HAND);
		
		for(j = 0; j <  G.handCount[player] ; j++)
		{
			G.hand[player][j] = floor(Random() * 27);
		}
		/*SET UP ROUND TO BE BEGINNING OF ROUND*/
		temp = G.hand[player][G.handCount[player]-1];
		G.whoseTurn = player;
		G.outpostPlayed = player;
  		G.phase = 0;
  		G.numActions = 1;
		/*SET UP ADVENTURER TO BE PLAYED*/
		handPos = 0;
		G.hand[player][handPos] = adventurer;

		/*PRINT DEBUG STATEMENTS*/
		if(DEBUG){
		    printf("player is : %d\n", player);
		    printf("Previously had/added is: %d\n", temp);
		    printf("Most recently added is: %d\n", G.hand[player][G.handCount[player]-1]);
		}
		/*TEST PLAYING ADVENTURE CARD*/
		if (DEBUG) printf("iteration: %d successful\n", counter);
		//playCard(handPos, G.hand[player][1], G.hand[player][2], G.hand[player][3], &G);
	}

  printf ("ALL TESTS OK\n");

	return 0;
}
    