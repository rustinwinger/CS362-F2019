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
	int handPos = 0;
	int seed = 1000;
	int player = 0;
	int i;

	int k[10] = { minion, baron, estate, tribute, mine
	, remodel, minion, ambassador, baron, great_hall };

	printf("\nBegin Random Testing minionRefactor\n");

	for (i = 0; i < 10000; i++) {
		struct gameState state, test;
		int players = (rand() % 75);
		initializeGame(players, k, seed, &state);

		printf("Case %d\n", i + 1);

		memcpy(&test, &state, sizeof(struct gameState));

		test.hand[player][1] = estate;
		minionRefactor(player, &test, choice1, choice2, handPos);

		if (test.coins = (test.coins + 2)) {
			printf("Choice 2 executed properly\n");
			}
		else {
			printf("Choice 2 not executed properly\n");
		}

		minionRefactor(player, &test, choice1, choice2, handPos);
		
		if (state.handCount[player] == 4) {
			printf("Cards discarded correctly\n");
		}
		else {
			printf("Cards not discarded correctly\n");
		}
	}
	return 0;
}