/*
 * Longest Consecutive Subsequence
Last Updated : 16 Jul, 2024
Given an array of integers, find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order. 

Examples:  

Input: arr[] = {1, 9, 3, 10, 4, 20, 2}
Output: 4
Explanation: The subsequence 1, 3, 4, 2 is the longest subsequence of consecutive elements

Input: arr[] = {36, 41, 56, 35, 44, 33, 34, 92, 43, 32, 42}
Output: 5
Explanation: The subsequence 36, 35, 33, 34, 32 is the longest subsequence of consecutive elements. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50

void print_array(int* arr,int n) {
	for (int i = 0; i< n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int duplicates (int* a, int n ) {
    int f[n], cnt, k = 0;

    for (int i = 0; i<n; i++) {
            f[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (!f[i]) {
                if (a[i] == a[j]) {
                    f[j] = 1;
                }
            }
        }
        if (!f[i]) {
            a[k++] = a[i];
        }
    }
    a = (int*) realloc (a, k*sizeof(int));
    printf("Dulpicate Remove Array : ");
    print_array(a,k);

    return k;
}

int longest_consecutive (int* a ,int n) {
	int maxCount = 0, cnt = 0;
	int c;

	int f[n], ele1[n], ele2[n];

	for (int i = 0; i < n; i++) {
		f[i] = 0;
	}
        int k =  0,l;

	for (int i = 0; i < n; i++) {
		c = a[i];
		for (int j = 0; j < n; j++) {
			if (!f[j]) {
				if (a[j] == c+1 || a[j] == c-1) {
					cnt++;
					ele1[k++] = c;
					c = a[j];
					f[j] = 1;
					f[i] = 1;
					j = 0;
					continue;
				}
			}
		}
		cnt++;
		ele1[k++] = c;
		print_array(ele1,k);
		if (cnt > maxCount) {
			maxCount = cnt;
			l = 0;
			for (int i = 0; i < k; i++) {
         		       ele2[l++] = ele1[i];
			}
		}
		cnt = 0, k = 0;
	}
        
	printf ("Consective Elements : ");
	print_array(ele2, l);

	return maxCount;
}


void longest_consecutive_hash (int* a, int n) {
	int hash[MAX];
	int maxCount = 0, cnt = 0;
	int ele1[n], ele2[n];


	for (int i = 0; i < MAX; i++) {
                hash[i] = 0;
        }
	for (int i = 0; i < n; i++) {
		hash[a[i]] = 1;
	}

	for (int i = 0; i < MAX; i++) {
		if(hash[i] == 1) {
			printf("%d ", i);
		}
	}
	printf("\n");
}


int main () {
	int N;
	printf("Enter the Array Size : ");
	scanf("%d", &N);

	/*int* arr = (int*) malloc (N*sizeof(int));


	srand(time(NULL));
	for(int i = 0; i < N; i++) {
		arr[i] = rand() % MAX;
	}*/

	int arr[] = { 41, 37, 8, 47, 33, 9, 46, 28, 12, 49, 25, 31, 19, 48 };
	N = sizeof(arr) / sizeof(arr[0]);

	printf("Array : ");
	print_array(arr,N);

	longest_consecutive_hash(arr, N);

	// int n = duplicates(arr, N);

	int cnt = longest_consecutive(arr,N);

	printf("Longest subsequence of consecutive elements : %d\n", cnt);

	//free(arr);

	return 0;
}



