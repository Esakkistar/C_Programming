#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void findUnique(int* a, int n) {
    int cnt[256];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }
    
    printf("Unique Elements : ");
    for (int i = 0; i < n; i++) {
        if (cnt[a[i]] == 1) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
    printf("Duplicated Elements : ");
    for (int i = 0; i < n; i++) {
        if (cnt[a[i]] > 1) { // if (cnt[a[i]]) -> this condtion gives the all unique elements.
            printf("%d ", a[i]);
            cnt[a[i]] = 0;
        }
    }
    printf("\n");
}
int main() {
      int arr[] = {1, 5, 8, 5, 7, 3, 2, 4, 5, 5, 1, 6, 7, 3, 9, 10,11,1,2, 4};
      int n = sizeof(arr) / sizeof(arr[0]);
      
      findUnique(arr, n);
      
      printf("All Unique Elements : ");
      int i, j;
      for (i = 0; i < n; i++) {
          for (j = 0; j < i; j++) {
              if (arr[i] == arr[j]){
                  break;
              }
          }
          if (i == j) {
              printf("%d ", arr[i]);
          }
      }
      printf("\n");

    return 0;
}
