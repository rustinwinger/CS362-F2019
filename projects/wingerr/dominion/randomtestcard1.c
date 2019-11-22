#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>

int main(int argc, char* args[]) {

	srand(time(NULL));

	int choice1 = 1;
	int choice2 = 0;
	int seed = 1000;
	int player = 0;
	int i, j;
	struct gameState state, test;
	int k[10] = { estate, estate, estate, tribute, mine
	, remodel, smithy, village, baron, great_hall };

	printf("\nBegin Random Testing baronRefactor\n");

	for (i = 0; i < 10000; i++) {
		int players = (rand() % 10);
		initializeGame(players, k, seed, &state);
		
		printf("Case %d\n", i + 1);

		memcpy(&test, &state, sizeof(struct gameState));

		test.hand[player][1] = estate;
		baronRefactor(player, &test, choice1);

		if (test.numBuys = (test.numBuys + 1)) {
			printf("buys are correct\n");
		}
		else {
			printf("buys are incorrect\n");
		}

		test.handCount[player] = 0;
		test.supplyCount[estate] = 1;
		baronRefactor(player, &test, choice1);

		int preCoins = test.coins;
		test.supplyCount[estate] = 1;
		baronRefactor(player, &test, choice2);

		if (test.coins = preCoins) {
			printf("Estate card not discarded\n");
		}
		else {
			printf("Estate card discarded\n");
		}
	}
	return 0;
}