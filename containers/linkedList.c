#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"
/* Jacob Arvino | 19817082
  Linked list function file*/


linkedList* createLinkedList()/*Creates an empty linkedlist*/
{
    linkedList* list;
    
    list = (linkedList*)malloc(sizeof(linkedList));
    
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
    
    return list;
}

void insertFirst(linkedList* list, int snakeRow, int snakeCol, char snakeBody)/*Inserts a value into the front of the linkedlist*/
{
    linkedListNode* newNode, temp;
    
    newNode = (linkedListNode*)malloc(sizeof(linkedListNode));/*Allocate memory for new node*/
    
    newNode->row = snakeRow;
    newNode->col = snakeCol;
    newNode->body = snakeBody;
    newNode->next = NULL;
    newNode->prev = NULL; /*Assign user inputted values to the struct*/
    
    if(isEmpty(list) == 1)/*If the list only has 1 element, make the inserted node both the head and tail of the list*/
    {
        list->head = newNode;
        list->tail = newNode;
        list->count = list->count + 1;
    }
    else /*If the list has other nodes, make the new node the head and make it point to the old head of the list in the 'next' field. Make the old head of the list point to the new head in it's 'prev' field*/
    {
        if(list->head == NULL)
        {
            list->tail = list->head;
        }
        newNode->next = list-> head;
        
        list->head->prev = newNode;
        
        list->head = newNode;
        list->count = list->count + 1;
    }
}

void insertLast(linkedList* list, int snakeRow, int snakeCol, char snakeBody) /*Inserts a value into the end of the linkedlist*/
{
    linkedListNode* newNode, temp;
    
    newNode = (linkedListNode*)malloc(sizeof(linkedListNode)); /*Allocate memory for new node*/
    
    newNode->row = snakeRow;
    newNode->col = snakeCol;
    newNode->body = snakeBody;
    newNode->next = NULL;
    newNode->prev = NULL; /*Assign user inputted values to the struct*/
    
    if(isEmpty(list) == 1) /*If the list only has 1 element, make the inserted node both the head and tail of the list*/
    {
        list->head = newNode;
        list->tail = newNode;
        list->count = list->count + 1;
    }
    else /*If the list has other nodes, make the new node the tail and make it point to the old tail of the list in the 'prev' field. Make the old tail of the list point to the new tail in it's 'next' field*/
    {
        if(list->head == NULL)
        {
            list->head = list->tail;
        }
        newNode->prev = list->tail;
        
        list->tail->next = newNode;
        
        list->tail = newNode;
        list->count = list->count + 1;
    }
}

int isEmpty(linkedList* list)/*Checks if f a value exists in the head field of the linkedList, returning the corresponding value*/
{
    int empty;
    
    empty = 0;
    
    if(list->head == NULL)
    {
        empty = 1;
    }

    return empty;
}

void freeList(linkedList* list)/*Frees all the nodes in the linkedList*/
{
    linkedListNode* currentNode, prevNode;
    currentNode = list->tail; /*Points to the last node in the list*/
    
    while (currentNode != NULL)/*While there are still nodes in the list, point to the node prev to the current node, free the current node and remove any pointers to it, then repeat the process until no nodes are left */
    {
        prevNode = *currentNode->prev;
        free(currentNode);
        prevNode.next = NULL;
        
        currentNode = &prevNode;
    }

}


