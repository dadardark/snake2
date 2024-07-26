#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct linkedListNode
{
    int row;
    int col;
    char body;
    struct linkedListNode* next;
    struct linkedListNode* prev;
} linkedListNode;

typedef struct linkedList
{
    linkedListNode* head;
    linkedListNode* tail;
    int count;
} linkedList;


linkedList* createLinkedList();
void insertFirst(linkedList* list, int snakeRow, int snakeCol, char snakeBody);
void insertLast(linkedList* list, int snakeRow, int snakeCol, char snakeBody);
int isEmpty(linkedList* list);
void freeList(linkedList* list);

#endif
