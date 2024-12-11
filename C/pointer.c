#include <stdio.h>

int main() {
    int number = 10;
    int* ptr = &number;

    printf("Value of number: %d\n", number);
    printf("Address of number: %p\n", &number);
    printf("Value of ptr (address it points to): %p\n", ptr);
    printf("Value at the address stored in ptr: %d\n", *ptr);

    *ptr = 20;
    printf("\nAfter modifying value using pointer:\n");
    printf("Value of number: %d\n", number);

    return 0;
}
