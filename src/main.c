#include <stdio.h>
#define LINKED_LIST_IMPLEMENTATION
#include "../include/linked_list.h"

void print_int(int data) {
    printf("%d", data);
}

void print_char(char data) {
    printf("'%c'", data);
}

void print_float(float data) {
    printf("%.2f", data);
}

int main() {
    List_int* int_list = list_int_create();
    List_char* char_list = list_char_create();
    List_float* float_list = list_float_create();

    list_int_append(int_list, 10);
    list_int_append(int_list, 20);
    list_int_append(int_list, 30);

    list_char_append(char_list, 'A');
    list_char_append(char_list, 'B');
    list_char_append(char_list, 'C');

    list_float_append(float_list, 1.23f);
    list_float_append(float_list, 4.56f);
    list_float_append(float_list, 7.89f);

    printf("Lista de enteros: ");
    list_int_print(int_list, print_int);
    printf("Lista de caracteres: ");
    list_char_print(char_list, print_char);
    printf("Lista de flotantes: ");
    list_float_print(float_list, print_float);

    list_int_destroy(int_list);
    list_char_destroy(char_list);
    list_float_destroy(float_list);

    printf("\n\nListas destruidas.\n");
    list_int_print(int_list, print_int);
    list_char_print(char_list, print_char);
    list_float_print(float_list, print_float);

    return 0;
}
