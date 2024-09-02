#include <stdio.h> 
int main () {

    int i = 5;
    printf("%d %d\n", ++i, i++);

    int x = 2;
    int y = ++x * ++x;
    printf("%d\n", y);
    
    return 0; 
}
