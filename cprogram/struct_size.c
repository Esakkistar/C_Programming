#include <stdio.h>

struct Example {
    char a;            // 1 byte
    int b;             // 4 bytes
    char c;            // 1 byte
    union ExampleUnion { // Union inside the structure
        //int d;
        long e;        	// 4 bytes
    } u;               // Instance of the union
};

int main() {
    struct Example ex;
    printf("Size of struct Example: %zu\n", sizeof(ex));
    long f;
    printf("Size of long: %zu\n", sizeof(f));
    return 0;
}
