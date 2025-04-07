#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// ----------------------------
// Macro para declarar estructuras y prototipos
// ----------------------------
#define DECLARE_CIRCULAR_LINKED_LIST(TYPE) \
    typedef struct Node_##TYPE { \
        TYPE data; \
        struct Node_##TYPE* next; \
    } Node_##TYPE; \
    Node_##TYPE* node_##TYPE##_create(TYPE); \
    Node_##TYPE* node_##TYPE##_destroy(Node_##TYPE*); \
    \
    typedef struct { \
        Node_##TYPE* head; \
        Node_##TYPE* tail; \
        size_t length; \
    } CLlist_##TYPE; \
    \
    CLlist_##TYPE* CLlist_##TYPE##_create(); \
    void CLlist_##TYPE##_destroy(CLlist_##TYPE* list); \
    bool CLlist_##TYPE##_insert(CLlist_##TYPE* list, TYPE data, size_t pos); \
    bool CLlist_##TYPE##_append(CLlist_##TYPE* list, TYPE data); \
    bool CLlist_##TYPE##_remove_at(CLlist_##TYPE* list, size_t pos); \
    bool CLlist_##TYPE##_remove(CLlist_##TYPE* list, TYPE data); \
    bool CLlist_##TYPE##_get(const CLlist_##TYPE* list, size_t pos, TYPE* out); \
    size_t CLlist_##TYPE##_length(const CLlist_##TYPE* list); \
    bool CLlist_##TYPE##_is_empty(const CLlist_##TYPE* list); \
    bool CLlist_##TYPE##_contains(const CLlist_##TYPE* list, TYPE data); \
    void CLlist_##TYPE##_clear(CLlist_##TYPE* list); \
    void CLlist_##TYPE##_print(const CLlist_##TYPE* list, void (*print_fn)(TYPE));

// ----------------------------
// Macro para implementación
// ----------------------------
#define IMPLEMENT_CIRCULAR_LINKED_LIST(TYPE) \
    Node_##TYPE* node_##TYPE##_create(TYPE data) { \
        Node_##TYPE* new_node = malloc(sizeof(Node_##TYPE)); \
        new_node->data = data; \
        new_node->next = NULL; \
        return new_node; \
    } \
    \
    Node_##TYPE* node_##TYPE##_destroy(Node_##TYPE *node) { \
        free(node); \
        return NULL; \
    } \
    CLlist_##TYPE* CLlist_##TYPE##_create() { \
        CLlist_##TYPE* list = malloc(sizeof(CLlist_##TYPE)); \
        if (!list) return NULL; \
        list->head = list->tail = NULL; \
        list->length = 0; \
        return list; \
    } \
    \
    void CLlist_##TYPE##_destroy(CLlist_##TYPE* list) { \
        if (!list) return; \
        CLlist_##TYPE##_clear(list); \
        free(list); \
    } \
    \
    bool CLlist_##TYPE##_insert(CLlist_##TYPE* list, TYPE data, size_t pos) { \
        if (!list || pos > list->length) return false; \
        Node_##TYPE* new_node = node_##TYPE##_create(data); \
        if (!new_node) return false; \
        \
        if (pos == 0) { \
            if (list->length == 0) { \
                list->head = list->tail = new_node; \
                new_node->next = new_node; \
            } else { \
                new_node->next = list->head; \
                list->head = new_node; \
                list->tail->next = list->head; \
            } \
        } else { \
            Node_##TYPE* current = list->head; \
            for (size_t i = 0; i < pos - 1; ++i) { \
                current = current->next; \
            } \
            new_node->next = current->next; \
            current->next = new_node; \
            if (pos == list->length) { \
                list->tail = new_node; \
            } \
        } \
        list->length++; \
        return true; \
    } \
    \
    bool CLlist_##TYPE##_append(CLlist_##TYPE* list, TYPE data) { \
        return CLlist_##TYPE##_insert(list, data, list->length); \
    } \
    \
    bool CLlist_##TYPE##_remove_at(CLlist_##TYPE* list, size_t pos) { \
        if (!list || pos >= list->length) return false; \
        Node_##TYPE* to_delete = NULL; \
        \
        if (pos == 0) { \
            to_delete = list->head; \
            list->head = list->head->next; \
            list->tail->next = list->head; \
            if (list->length == 1) { \
                list->head = list->tail = NULL; \
            } \
        } else { \
            Node_##TYPE* current = list->head; \
            for (size_t i = 0; i < pos - 1; ++i) { \
                current = current->next; \
            } \
            to_delete = current->next; \
            current->next = to_delete->next; \
            if (pos == list->length - 1) { \
                list->tail = current; \
            } \
        } \
        free(to_delete); \
        list->length--; \
        return true; \
    } \
    \
    bool CLlist_##TYPE##_remove(CLlist_##TYPE* list, TYPE data) { \
        if (!list) return false; \
        Node_##TYPE* prev = NULL; \
        Node_##TYPE* current = list->head; \
        for (size_t i = 0; i < list->length; ++i) { \
            if (current->data == data) { \
                if (prev) { \
                    prev->next = current->next; \
                    if (current == list->tail) { \
                        list->tail = prev; \
                        list->tail->next = list->head; \
                    } \
                } else { \
                    list->head = current->next; \
                    list->tail->next = list->head; \
                    if (list->length == 1) { \
                        list->head = list->tail = NULL; \
                    } \
                } \
                free(current); \
                list->length--; \
                return true; \
            } \
            prev = current; \
            current = current->next; \
        } \
        return false; \
    } \
    \
    bool CLlist_##TYPE##_get(const CLlist_##TYPE* list, size_t pos, TYPE* out) { \
        if (!list || !out || pos >= list->length) return false; \
        Node_##TYPE* current = list->head; \
        for (size_t i = 0; i < pos; ++i) { \
            current = current->next; \
        } \
        *out = current->data; \
        return true; \
    } \
    \
    size_t CLlist_##TYPE##_length(const CLlist_##TYPE* list) { \
        return list ? list->length : 0; \
    } \
    \
    bool CLlist_##TYPE##_is_empty(const CLlist_##TYPE* list) { \
        return list ? list->length == 0 : true; \
    } \
    \
    bool CLlist_##TYPE##_contains(const CLlist_##TYPE* list, TYPE data) { \
        if (!list) return false; \
        Node_##TYPE* current = list->head; \
        for (size_t i = 0; i < list->length; ++i) { \
            if (current->data == data) return true; \
            current = current->next; \
        } \
        return false; \
    } \
    \
    void CLlist_##TYPE##_clear(CLlist_##TYPE* list) { \
        if (!list) return; \
        Node_##TYPE* current = list->head; \
        while (list->length > 0) { \
            Node_##TYPE* temp = current; \
            current = current->next; \
            free(temp); \
            list->length--; \
        } \
        list->head = list->tail = NULL; \
    } \
    \
    void CLlist_##TYPE##_print(const CLlist_##TYPE* list, void (*print_fn)(TYPE)) { \
        if (!list || !print_fn) return; \
        \
        printf("["); \
        Node_##TYPE* current = list->head; \
        for (size_t i = 0; i < list->length; ++i) { \
            print_fn(current->data); \
            if (i < list->length - 1) printf(", "); \
            current = current->next; \
        } \
        printf("]\n"); \
    }

// ----------------------------
// Declaración para tipos concretos
// ----------------------------
DECLARE_CIRCULAR_LINKED_LIST(int)
DECLARE_CIRCULAR_LINKED_LIST(char)
DECLARE_CIRCULAR_LINKED_LIST(float)

// ----------------------------
// Implementación para tipos concretos
// ----------------------------
#ifdef CIRCULAR_LINKED_LIST_IMPLEMENTATION
IMPLEMENT_CIRCULAR_LINKED_LIST(int)
IMPLEMENT_CIRCULAR_LINKED_LIST(char)
IMPLEMENT_CIRCULAR_LINKED_LIST(float)
#endif

