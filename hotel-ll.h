//
// Created by sy585 on 7/10/2018.
//

#ifndef PROJECT_2_HOTEL_LL_H
typedef struct node {
    void *ch;
    struct node *next;
} node_t;
typedef enum {
    false, true
} bool;

node_t *initList(void *ch);

node_t *generateVisitors(int a);

void freeList(node_t **head);

void insertLastList(node_t **head, void *insert_char); // Append a node
#define PROJECT_2_HOTEL_LL_H
#endif //PROJECT_2_HOTEL_LL_H
