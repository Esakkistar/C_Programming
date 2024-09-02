#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function
    int t = *a + *b; 
    *b = *a - *b; 
    *a = t;  
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d %d\n", a, b);

    return 0;
}
