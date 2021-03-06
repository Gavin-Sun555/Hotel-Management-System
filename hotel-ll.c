#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "hotel-ll.h"

node_t *initList(void *ch) {
    node_t *head;
    head = (node_t *) calloc(1, sizeof(node_t));
    if (head == NULL) {
        fprintf(stderr, "Failed to assign memory!\n");
        exit(-1);
    }
    head->next = NULL;
    head->ch = ch;
    return head;
}

void freeList(node_t **head) {
    node_t *tmp = NULL;
    node_t *pHead = *head;
    while (pHead->next != NULL) {
        tmp = pHead;
        pHead = pHead->next;
        free(tmp);
    }
    free(pHead);
}

void insertLastList(node_t **head, void *insert_char) {
    node_t *temp = *head;
    node_t *last = calloc(1, sizeof(node_t));//use temp to trace the last element of the list
    while (temp->next != NULL) { temp = temp->next; };
    last->ch = insert_char;
    last->next = NULL;
    temp->next = last;
}



