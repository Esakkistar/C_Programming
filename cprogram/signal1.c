#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigsegv_handler(int sig) {
    printf("Caught signal %d (SIGSEGV). Segmentation fault occurred.\n", sig);
    // Clean up resources or log the error as needed
    exit(1); // Exit the program
}

int main() {
    // Register the signal handler for SIGSEGV
    signal(SIGSEGV, sigsegv_handler);

    // Example code that causes a segmentation fault
    int *ptr = NULL;
    printf("Value: %d\n", *ptr); // Dereferencing a null pointer

    return 0;
}

