//
// Created by sy585 on 7/10/2018.
//

#ifndef PROJECT_2_HOTEL_LL_H
#define PROJECT_2_HOTEL_LL_H

#include <stdbool.h>

typedef struct node {
    void *ch;
    struct node *next;
} node_t;

node_t *initList(void *ch);

node_t *manualInputVisitor(void);

void freeList(node_t **head);

void insertLastList(node_t **head, void *insert_char); // Append a node

#endif //PROJECT_2_HOTEL_LL_H
