/*
 * Partition problem | DP-18
   The partition problem is to determine whether a given set can be partitioned into two subsets such that the sum of elements in both subsets is the same. 

Examples: 

Input: arr[] = {1, 5, 11, 5}
Output: true 
The array can be partitioned as {1, 5, 5} and {11}

Input: arr[] = {1, 5, 3}
Output: false 
The array cannot be partitioned into equal sum sets. */


#include <stdio.h>
#include <stdbool.h>

void printEqualpartitions (int* a, int n, int sum) {
	int subset1[n], subset2[n];
	int subsetsum1, subsetsum2;
	int index1, index2;
	
	int total_partitions = 1 << n;

	for (int mask = 0; mask < total_partitions/2; mask++) {		
		index1 = 0, index2 = 0;
		subsetsum1 = 0, subsetsum2 = 0;
		
		for (int i = 0; i < n; i++) {
			if ( mask & (1 << i)) {
				subsetsum1 += a[i];
				subset1[index1++] = a[i];
			}
		}

		if (subsetsum1 != sum) 
			continue;
		
                for (int i = 0; i < n; i++) {
                        if ( !(mask & (1 << i)) ) {
				subsetsum2 += a[i];
                                subset2[index2++] = a[i];
                        }
                }

                if (subsetsum2 != sum)
                        continue;
                
		printf("Partition1 : {");
		for (int i = 0; i < index1; i++) {
			printf("%d",subset1[i]);
			if (i+1 != index1)
				printf(", ");
		}
                printf("}\n");

		printf("Partition2 : {");
                for (int i = 0; i < index2; i++) {
                        printf("%d",subset2[i]);
                        if (i+1 != index2)
                                printf(", ");
                }
                printf("}\n\n");
	}
}

int main () {
	int arr[] = {1, 2, 3, 7, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
 
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}

	if (sum % 2 == 0) 
	      printEqualpartitions(arr, n, sum/2);
	else 
	      printf("Can't able to partition the given array.\n");

	return 0;
}

/*
 #include <stdio.h>
#include <stdbool.h>

// Function to print all subsets that add up to a given sum
void printPartitions(int* nums, int numsSize, int target) {
    int numSubsets = 1 << numsSize; // Total number of subsets
    printf("Partitions of array into two subsets with equal sum %d:\n", target);

    for (int mask = 0; mask < numSubsets; mask++) {
        int subsetSum = 0;
        bool used[numsSize];
        for (int i = 0; i < numsSize; i++) {
            used[i] = false;
        }

        // Generate subset based on the bitmask
        for (int i = 0; i < numsSize; i++) {
            if (mask & (1 << i)) {
                subsetSum += nums[i];
                used[i] = true;
            }
        }

        if (subsetSum == target) {
            // Print subset 1
            printf("Subset 1: {");
            for (int i = 0; i < numsSize; i++) {
                if (used[i]) {
                    printf("%d ", nums[i]);
                }
            }
            printf("}\n");

            // Print subset 2
            printf("Subset 2: {");
            for (int i = 0; i < numsSize; i++) {
                if (!used[i]) {
                    printf("%d ", nums[i]);
                }
            }
            printf("}\n\n");
        }
    }
}

// Function to check if array can be partitioned and find target sum
bool canPartition(int* nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    
    if (sum % 2 != 0) {
        return false;
    }
    
    int target = sum / 2;
    printPartitions(nums, numsSize, target);
    return true;
}

int main() {
    int arr[] = {1, 5, 11, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    if (canPartition(arr, size)) {
        printf("The array can be partitioned into two subsets with equal sum.\n");
    } else {
        printf("The array cannot be partitioned into two subsets with equal sum.\n");
    }
    
    return 0;
}
*/
