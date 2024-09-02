#include <stdio.h>

int main() {
    int x = 10, z = 10;
    int y = ++x + ++z + z++ + ++z;
    printf("%d\n", y);
    x = 10;
    y = ++x + ++x + ++x + x++ + ++x + x++;
    printf("%d\n", y);

    int a = 10;
    a += a += a *= a;
    printf("%d\n", a);

    x = 10, y = 20;
    z = x + y >> 1;
    printf("%d\n", z);
    return 0;
}
