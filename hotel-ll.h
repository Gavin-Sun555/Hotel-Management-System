//
// Created by sy585 on 7/10/2018.
//

#ifndef PROJECT_2_HOTEL_LL_H
typedef struct node{ void* ch; struct node *next; } node_t;
typedef enum{false, true} bool;
node_t *Initialize(void* ch);
node_t* generatevistors(int a);
void PrintRoomList(node_t *head);
void PrintVisitorList(node_t *head);
void FreeList(node_t **head);
bool IsEmptyList(node_t *head); // Return true if the list is empty, false otherwise
void InsertFirstList(node_t **head,void* insert_char); // Prepend a node
void InsertLastList(node_t **head,void* insert_char); // Append a node
void DeleteFirstList(node_t **head); // Delete the first element in the list
void DeleteLastList(node_t **head); // Delete the last element in the list
int SizeList(node_t *head); // Return the size of the list(not work for empty list!!)
int SearchList(node_t **head, void* target); // Count how many times target appears
void SplitList(node_t **head, node_t **tail, int pos); // Split into [0;pos-1] and [pos,end]
void MergeList(node_t **head1, node_t **head2); // Merge two lists
#define PROJECT_2_HOTEL_LL_H
#endif //PROJECT_2_HOTEL_LL_H
