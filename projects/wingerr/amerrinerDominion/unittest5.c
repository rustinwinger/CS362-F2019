#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"

//mine unit test

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

	printf("\nBegin Testing mineRefactor\n");

	memcpy(&test, &state, sizeof(struct gameState));

	mineEffect(&test, player, choice1, choice2, handPos);

	player = 2;
	int size = state.handCount[player];
	mineEffect(&test, player, choice1, choice2, handPos);

	if (test.discardCount == (test.discardCount + 1)) {
		printf("discard is correct\n");
	}
	else {
		printf("discard is incorrect\n");
	}

	return 0;
}