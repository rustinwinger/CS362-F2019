#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"

//mine unit test

int main() {
	int choice1 = 1;
	int choice2 = 0;
	int handPos = 0;
	int seed = 1000;
	int player = 0;
	struct gameState state, test;
	int k[10] = { silver, silver, estate, tribute, mine
	, remodel, smithy, village, baron, great_hall };

	initializeGame(2, k, seed, &state);

	printf("\nBegin Testing mineRefactor\n");

	memcpy(&test, &state, sizeof(struct gameState));

	mineRefactor(player, &test, choice1, choice2, handPos);

	if (test.discardCount == (test.discardCount + 1)) {
		printf("discard is correct\n");
	}
	else {
		printf("discard is incorrect\n");
	}

	int j[10] = { treasure_map, ambassador, estate, tribute, mine
	, remodel, smithy, village, baron, great_hall };

	initializeGame(2, j, seed, &state);
	memcpy(&test, &state, sizeof(struct gameState));
	mineRefactor(player, &test, choice1, choice2, handPos);

	int n[10] = { ambassador, ambassador, estate, tribute, mine
	, remodel, smithy, village, baron, great_hall };

	initializeGame(2, n, seed, &state);
	memcpy(&test, &state, sizeof(struct gameState));

	if (mineRefactor(player, &test, choice1, choice2, handPos)) == -1) {
		printf("Exited with -1\n");
	}
	else {
		printf("Skipped\n");
	}

	return 0;
}