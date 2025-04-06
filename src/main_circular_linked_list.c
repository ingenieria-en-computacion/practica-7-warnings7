#define LINKED_LIST_IMPLEMENTATION
#include "circular_linked_list.h"
#include <stdio.h>

void print_int(int value) {
    printf("%d", value);
}

void print_char(char value) {
    printf("%c", value);
}

int main() {
    printf("=== Lista Simple (int) ===\n");
    List_int* nums = list_int_create(false);  // Lista simple
    list_int_append(nums, 10);
    list_int_append(nums, 20);
    list_int_append(nums, 30);
    
    printf("Lista: ");
    list_int_print(nums, print_int);  // Output: [10, 20, 30]
    
    list_int_destroy(nums);

    printf("\n=== Lista Circular (char) ===\n");
    List_char* chars = list_char_create(true);  // Lista circular
    list_char_append(chars, 'a');
    list_char_append(chars, 'b');
    list_char_append(chars, 'c');
    
    printf("Lista: ");
    list_char_print(chars, print_char);  // Output: [a, b, c]
    
    list_char_destroy(chars);

    return 0;
}
