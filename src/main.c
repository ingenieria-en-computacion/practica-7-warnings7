#include <stdio.h>
#define LINKED_LIST_IMPLEMENTATION
#include "../include/linked_list.h" // Asegúrate de que este sea el nombre correcto del archivo de encabezado

// Funciones de impresión para cada tipo
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
    // Crear listas para cada tipo
    List_int* int_list = list_int_create();
    List_char* char_list = list_char_create();
    List_float* float_list = list_float_create();

    // Agregar elementos a las listas
    list_int_append(int_list, 10);
    list_int_append(int_list, 20);
    list_int_append(int_list, 30);

    list_char_append(char_list, 'A');
    list_char_append(char_list, 'B');
    list_char_append(char_list, 'C');

    list_float_append(float_list, 1.23f);
    list_float_append(float_list, 4.56f);
    list_float_append(float_list, 7.89f);

    // Imprimir las listas iniciales
    printf("Lista de enteros: ");
    list_int_print(int_list, print_int);
    printf("Lista de caracteres: ");
    list_char_print(char_list, print_char);
    printf("Lista de flotantes: ");
    list_float_print(float_list, print_float);

    // Obtener y mostrar elementos específicos
    int int_value;
    if (list_int_get(int_list, 1, &int_value)) {
        printf("Elemento en posición 1 de la lista de enteros: %d\n", int_value);
    }

    char char_value;
    if (list_char_get(char_list, 0, &char_value)) {
        printf("Elemento en posición 0 de la lista de caracteres: '%c'\n", char_value);
    }

    float float_value;
    if (list_float_get(float_list, 2, &float_value)) {
        printf("Elemento en posición 2 de la lista de flotantes: %.2f\n", float_value);
    }

    // Eliminar elementos
    list_int_remove_at(int_list, 0);  // Eliminar el primer elemento (10)
    list_char_remove_at(char_list, 1); // Eliminar el segundo elemento ('B')
    list_float_remove_at(float_list, 2); // Eliminar el tercer elemento (7.89)

    // Imprimir listas después de eliminar
    printf("\nDespués de eliminar elementos:\n");
    printf("Lista de enteros: ");
    list_int_print(int_list, print_int);
    printf("Lista de caracteres: ");
    list_char_print(char_list, print_char);
    printf("Lista de flotantes: ");
    list_float_print(float_list, print_float);

    // Insertar nuevos elementos en posiciones específicas
    list_int_insert(int_list, 15, 1); // Insertar 15 en la posición 1
    list_char_insert(char_list, 'D', 0); // Insertar 'D' al inicio
    list_float_insert(float_list, 9.99f, 1); // Insertar 9.99 en la posición 1

    // Imprimir listas después de insertar
    printf("\nDespués de insertar elementos:\n");
    printf("Lista de enteros: ");
    list_int_print(int_list, print_int);
    printf("Lista de caracteres: ");
    list_char_print(char_list, print_char);
    printf("Lista de flotantes: ");
    list_float_print(float_list, print_float);

    // Destruir las listas para liberar memoria
    list_int_destroy(int_list);
    list_char_destroy(char_list);
    list_float_destroy(float_list);

    return 0;
}
