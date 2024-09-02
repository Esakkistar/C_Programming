
/*
 * Write a C program to find the optimal number of units for Ingredient A and Ingredient B, and calculate the minimum total cost.

Quest: The Magic Potion

Objective: Write a C program to help a wizard create the perfect potion. The wizard needs to mix exactly 100 units of two ingredients: A and B. Each ingredient has a specific unit cost and you need to calculate the total cost based on the amounts used.

Problem Statement:

Ingredients:

Ingredient A: $5 per unit
Ingredient B: $3 per unit
Requirements:

You need to mix exactly 100 units of ingredients A and B.
You need to find out how many units of each ingredient are needed to minimize the cost while meeting the total unit requirement.
Constraints:

The units of Ingredient A (let's call it x) and Ingredient B (let's call it y) must be non-negative integers.
The total cost should be minimized. */

/*#include <stdio.h>

int main () {
	int costA = 5;
	int costB = 3;
	int Total_cost = 100;

	int unitA = 0, unitB = 0,cost;
	int min_cost = 0;

	for (int A = 0; A <= Total_cost; A++) {
		int B = Total_cost - A;
		cost = A*costA + B*costB;

		if (min_cost == 0 || cost < min_cost) {
			min_cost = cost;
			unitA = A;
			unitB = B;
		}
	}
	printf("Ingredient A : %d\tIngredient B : %d\n", unitA,unitB);
	printf("Minimum cost : %d\n",min_cost);

	return 0;
} */


/*#include <stdio.h>

int main() {
    // Ingredient costs
    const int costA = 5;
    const int costB = 3;
    
    // Total units required
    const int totalUnits = 100;
    
    int optimalA = 0, optimalB = 0;
    int minCost = -1;

    // Iterate through all possible values for Ingredient A
    for (int unitsA = 0; unitsA <= totalUnits; unitsA++) {
        // Calculate units for Ingredient B
        int unitsB = totalUnits - unitsA;
        
        // Calculate the cost for the current combination
        int cost = (unitsA * costA) + (unitsB * costB);
        
        // Update the minimum cost and optimal units if this combination is cheaper
        if (minCost == -1 || cost < minCost) {
            minCost = cost;
            optimalA = unitsA;
            optimalB = unitsB;
        }
    }

    // Output the results
    printf("Optimal number of units for Ingredient A: %d\n", optimalA);
    printf("Optimal number of units for Ingredient B: %d\n", optimalB);
    printf("Minimum total cost: $%d\n", minCost);

    return 0;
}*/


/*#include <stdio.h>

int main() {
    // Ingredient costs
    const int costA = 5;
    const int costB = 3;
    const int costC = 1;

    // Total units required
    const int totalUnits = 100;

    int optimalA = 0, optimalB = 0, optimalC = 0;
    int minCost = -1;

    // Iterate through all possible values for Ingredient A
    for (int unitsA = 0; unitsA <= totalUnits; unitsA++) {
        // Iterate through all possible values for Ingredient B
        for (int unitsB = 0; unitsB <= totalUnits - unitsA; unitsB++) {
            // Calculate units for Ingredient C
            int unitsC = totalUnits - unitsA - unitsB;

            // Ensure unitsC is non-negative
            if (unitsC >= 0) {
                // Calculate the cost for the current combination
                int cost = (unitsA * costA) + (unitsB * costB) + (unitsC * costC);

                // Update the minimum cost and optimal units if this combination is cheaper
                if (cost == totalUnits ) {
                    minCost = cost;
                    optimalA = unitsA;
                    optimalB = unitsB;
                    optimalC = unitsC;
                }
            }
        }
    }

    // Output the results
    printf("Optimal number of units for Ingredient A: %d\n", optimalA);
    printf("Optimal number of units for Ingredient B: %d\n", optimalB);
    printf("Optimal number of units for Ingredient C: %d\n", optimalC);
    printf("Minimum total cost: $%d\n", minCost);

    return 0;
}*/































