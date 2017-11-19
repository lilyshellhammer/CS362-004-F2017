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
 * Description: Initializes game, test smithy to see if correct amount of cards are added each time
 * Testing for: Tests that hand count is correct after playing smithy
 * 				(Hint: it won't be because I caught my own bug)
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
		/*SET UP ADVENTURER TO BE PLAYED*/
		handPos = 0;
		G.hand[player][handPos] = smithy;

		/*SAVE PREVIOUS HAND VALUE*/
		temp = G.handCount[player];
		G.whoseTurn = player;
		G.outpostPlayed = player;
  		G.phase = 0;
  		G.numActions = 1;
  		
		/*TEST PLAYING SMITHY CARD*/
		playCard(handPos, G.hand[player][1], G.hand[player][2], G.hand[player][3], &G);
		if(G.handCount[player] != (temp + 2))
		{
			flag++;
			if(DEBUG)
			{
				printf("Hand count at player %d is %d\n", player, G.handCount[player]);
				printf("Hand count previously was %d\n", temp);
			}
		}
	}

	/*IF NO ERRORS, PRINT PASSED, ELSE PRINT HOW MANY OCCURANCES*/
	if(flag == 0){
			printf("PASSES ALL TESTS\n");
		}
		else
			printf("ERROR IN AMOUNT OF CARDS ADDED: %d OCCURANCES OUT OF %d TESTS\n", flag, 100);
		

	return 0;
}
