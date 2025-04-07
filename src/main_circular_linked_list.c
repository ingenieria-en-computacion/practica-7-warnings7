#include <stdio.h>
#define CIRCULAR_LINKED_LIST_IMPLEMENTATION
#include "../include/circular_linked_list.h"

void print_int(int data) {
    printf("%d", data);
}

void print_char(char data) {
    printf("%c", data);
}

void print_float(float data) {
    printf("%.2f", data);
}

int main() {
    CLlist_int* int_list = CLlist_int_create();
    CLlist_char* char_list = CLlist_char_create();
    CLlist_float* float_list = CLlist_float_create();

    // Agregar elementos a las listas
    CLlist_int_append(int_list, 10);
    CLlist_int_append(int_list, 20);
    CLlist_int_append(int_list, 30);
    
    CLlist_char_append(char_list, 'A');
    CLlist_char_append(char_list, 'B');
    CLlist_char_append(char_list, 'C');

    CLlist_float_append(float_list, 3.14f);
    CLlist_float_append(float_list, 2.71f);
    CLlist_float_append(float_list, 1.61f);

    // Imprimir listas
    printf("Lista de enteros: ");
    CLlist_int_print(int_list, print_int);
    printf("\n");

    printf("Lista de caracteres: ");
    CLlist_char_print(char_list, print_char);
    printf("\n");

    printf("Lista de flotantes: ");
    CLlist_float_print(float_list, print_float);
    printf("\n");

    int value_int;
    if (CLlist_int_get(int_list, 1, &value_int)) {
        printf("Elemento en la posición 1 de la lista de enteros: %d\n", value_int);
    }

    char value_char;
    if (CLlist_char_get(char_list, 2, &value_char)) {
        printf("Elemento en la posición 2 de la lista de caracteres: %c\n", value_char);
    }

    float value_float;
    if (CLlist_float_get(float_list, 0, &value_float)) {
        printf("Elemento en la posición 0 de la lista de flotantes: %.2f\n", value_float);
    }

    // Eliminar un elemento de cada lista
    CLlist_int_remove_at(int_list, 1);
    CLlist_char_remove_at(char_list, 0); 
    CLlist_float_remove_at(float_list, 2); 

    printf("\nLista de enteros después de eliminar en la posición 1: ");
    CLlist_int_print(int_list, print_int);
    printf("\n");

    printf("Lista de caracteres después de eliminar en la posición 0: ");
    CLlist_char_print(char_list, print_char);
    printf("\n");

    printf("Lista de flotantes después de eliminar en la posición 2: ");
    CLlist_float_print(float_list, print_float);
    printf("\n");

    // Limpiar las listas
    CLlist_int_clear(int_list);
    CLlist_char_clear(char_list);
    CLlist_float_clear(float_list);

    printf("\nLista de enteros después de limpiar: ");
    CLlist_int_print(int_list, print_int);
    printf("\n");

    printf("Lista de caracteres después de limpiar: ");
    CLlist_char_print(char_list, print_char);
    printf("\n");

    printf("Lista de flotantes después de limpiar: ");
    CLlist_float_print(float_list, print_float);
    printf("\n");

    CLlist_int_destroy(int_list);
    CLlist_char_destroy(char_list);
    CLlist_float_destroy(float_list);

    return 0;
}
