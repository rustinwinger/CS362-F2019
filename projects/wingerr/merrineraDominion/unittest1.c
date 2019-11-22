#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"

//baron unit test

int main() {

	int choice1 = 1;
	int choice2 = 0;
	int seed = 1000;
	int player = 0;
	struct gameState state, test;
	int k[10] = { estate, estate, estate, tribute, mine
	, remodel, smithy, village, baron, great_hall };

	initializeGame(2, k, seed, &state);

	printf("\nBegin Testing baronRefactor\n");

	memcpy(&test, &state, sizeof(struct gameState));

	test.hand[player][1] = estate;
	baronEffect(player, &test, choice1);

	if (test.numBuys = (test.numBuys + 1)) {
		printf("buys are correct\n");
	}
	else {
		printf("buys are incorrect\n");
	}

	test.handCount[player] = 0;
	test.supplyCount[estate] = 1;
	baronEffect(player, &test, choice1);

	int preCoins = test.coins;
	test.supplyCount[estate] = 1;
	baronEffect(player, &test, choice2);

	if (test.coins = preCoins) {
		printf("Estate card not discarded\n");
	}
	else {
		printf("Estate card discarded\n");
	}

	return 0;
}