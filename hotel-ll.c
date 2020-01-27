#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "hotel-ll.h"
node_t *Initialize(void* ch) {
    node_t *head;
    head=(node_t*)calloc(1,sizeof(node_t));
    if(head==NULL){ fprintf(stderr,"Failed to assign memory!\n"); exit(-1); }
    head->next=NULL; head->ch=ch;
    return head;
}

void FreeList(node_t **head) {
    node_t *tmp=NULL; node_t *pHead=*head;
    while(pHead->next!=NULL) { tmp=pHead; pHead=pHead->next; free(tmp); }
    free(pHead);
}
bool IsEmptyList(node_t *head){
    if(head==NULL)
        return true;
    else
        return false;
}
void InsertFirstList(node_t **head,void* insert_char){
    node_t *first;
    first=(node_t*)calloc(1,sizeof(node_t));
    first->ch=insert_char;//
    first->next=*head;
    (*head)=first;//let the head pointer to the new initial point//
}
void InsertLastList(node_t **head,void* insert_char){
    node_t *temp=*head;
    node_t *last=calloc(1,sizeof(node_t));//use temp to trace the last element of the list
    while(temp->next!=NULL){temp=temp->next;};
    last->ch=insert_char;
    last->next=NULL;
    temp->next=last;
}
void DeleteFirstList(node_t **head){
    node_t* first=*head;
    (*head)=first->next;
    free(first);
}
void DeleteLastList(node_t **head){
    node_t *temp=*head;//use temp to trace the last element of the list
    while(temp->next->next!=NULL){temp=temp->next;};
    free(temp->next);
    temp->next=NULL;//WONDER if this writing style is ok.
}
int SizeList(node_t *head){
    if (head==NULL)
        return 0;
    node_t *temp= head;
    int i=1;
    while(temp->next!=NULL){temp=temp->next;i=i+1;};
    return i;

}
int SearchList(node_t **head, void* target){
    int i=0;
    node_t *temp= *head;
    while(temp!=NULL){
        if (temp->ch==target)
            i++;
        temp=temp->next;}
    return i;
}
void SplitList(node_t **head, node_t **tail, int pos){
    int i;
    node_t *temp= *head;
    for(i=0;i<(pos-1);i++){
        temp=temp->next;
    }
    *tail=temp->next;
    temp->next=NULL;
}
void MergeList(node_t **head1, node_t **head2){
    node_t *temp= *head1;
    while(temp->next!=NULL){temp=temp->next;}
    temp->next=*head2;
}

