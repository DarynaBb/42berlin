#include <stdio.h>
#include "ft_printf.h"  // Include your header file if needed

int main() {
    char *str = "Hello, world!";
    int num = 42;
	int my = 0;
	int orig = 0;

    // Example of testing print_pointer
    ft_printf("%p", (void *)-14523);
	printf("%p", (void *)-14523);
	
	// my = ft_printf("%p", NULL);
	// printf("\nmy return value:%d\n", my);
	
	// orig = printf("%p", NULL);
	// printf("\noriginal return value:%d\n", orig); // Test pointer printing with a string pointer

    
// cc -c main.c -o main.o
// cc main.o -L. -lftprintf -o test_program
    return 0;
}