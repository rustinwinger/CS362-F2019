#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"


//tribute unit test

int main() {

	int seed = 1000;
	int player = 0;
	struct gameState state, test;
	int k[10] = { estate, estate, estate, tribute, mine
	, remodel, smithy, village, baron, great_hall };

	initializeGame(2, k, seed, &state);

	printf("\nBegin Testing tributeRefactor\n");

	memcpy(&test, &state, sizeof(struct gameState));

	int playerTwo = whoseTurn(&test);
	tributeEffect(player, &test, playerTwo);

	return 0;
}