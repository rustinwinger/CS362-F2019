#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"

//ambassador unit test

int main() {
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

	ambassadorRefactor(player, &test, choice1, choice2, handPos);

	player = 2;
	int size = state->handCount[player];
	ambassadorRefactor(0, &test, choice1, choice2, handPos);

	if (state->handCount[player] == (size + 1)) {
		printf("Even player properly given card\n");
	}
	else {
		printf("Even player skipped\n");
	}
	
	return 0;
}