#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"


//tribute unit test

int main(int argc, char* args[]) {

	int choice1 = 1;
	int choice2 = 0;
	int seed = 1000;
	int player = 0;
	int player2 = 0;
	int handPos = 0;
	int i, j;
	struct gameState state, test;
	int k[10] = { estate, estate, estate, tribute, mine
	, remodel, smithy, village, baron, great_hall };

	printf("\nBegin Testing tributeRefactor\n");

	int players = (rand() % 75);
	initializeGame(players, k, seed, &state);

	memcpy(&test, &state, sizeof(struct gameState));

	test.hand[player][1] = tribute;
	player2 = whoseTurn(&test);

	tributeEffect(&test, player, player2, handPos);

	if (test.numBuys = (test.numBuys + 1)) {
		printf("buys are correct\n");
	}
	else {
		printf("buys are incorrect\n");
	}

	test.handCount[player] = 0;
	test.supplyCount[estate] = 1;
	tributeEffect(&test, player, player2, handPos);

	int preCoins = test.coins;
	test.supplyCount[estate] = 1;
	tributeEffect(&test, player, player2, handPos);

	if (test.coins = preCoins) {
		printf("Estate card not discarded\n");
	}
	else {
		printf("Estate card discarded\n");
	}

	return 0;
}