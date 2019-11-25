#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"

//minion unit test

int main(int argc, char* args[]) {
	int choice1 = 0;
	int choice2 = 1;
	int handPos = 0;
	int seed = 1000;
	int player = 0;
	struct gameState state, test;
	int k[10] = { minion, baron, estate, tribute, mine
	, remodel, smithy, ambassador, baron, great_hall };

	initializeGame(2, k, seed, &state);

	printf("\nBegin Testing ambassadorRefactor\n");

	memcpy(&test, &state, sizeof(struct gameState));

	minionEffect(choice1, choice2, &test, player, handPos);
	if (test.coins = (test.coins + 2)){
		printf("Choice 2 executed properly\n");
		}
	else {
		printf("Choice 2 not executed properly\n");
	}

	int cardCount = state.handCount[player];
	minionEffect(choice1, choice2, &test, player, handPos);
		if (state.handCount[player] == 4) {
			printf("Cards discarded correctly\n");
		}
		else {
			printf("Cards not discarded correctly\n");
		}

	return 0;

}