#include <stdio.h>
#include <stdlib.h>
#include"linkedList.h"

/*Jacob Arvino | 19817082
 Takes in a linkedList struct of a snake and updates the location of each body part based on the users movement*/

void snakeUpdater(linkedList* snakeList, char userMovement)
{
    linkedListNode* snakeListNode;

    if (userMovement == 'd')
    {
        snakeListNode = snakeList->head;
        while(snakeListNode->next != NULL) /*Shuffles all row/col values, except for the head of the snake, down one position in the snake.*/
        {
            snakeListNode->row = snakeListNode->next->row;
            snakeListNode->col = snakeListNode->next->col;
            snakeListNode = snakeListNode->next;
        }
        
        snakeListNode = snakeList->head;
        while((snakeListNode->next)-> next != NULL) /*Shuffles all body values, except for the head of the snake, down one position in the snake.*/
        {
            snakeListNode->body = snakeListNode->next->body;
            snakeListNode = snakeListNode->next;
        }
        
        snakeList->tail->col = snakeList->tail->col + 1; /*Increases the snakes head col coord by 1 as the user has moved the snake right, updates its head and tail body values accordingly*/
        snakeList->tail->body = '>';
        snakeList->tail->prev->body = '-';
        snakeList->head->body = '#';
        
        
    }
    else if (userMovement == 'a')
    {
        snakeListNode = snakeList->head;
        while(snakeListNode->next != NULL) /*Shuffles all row/col values, except for the head of the snake, down one position in the snake.*/
        {
            snakeListNode->row = snakeListNode->next->row;
            snakeListNode->col = snakeListNode->next->col;
            snakeListNode = snakeListNode->next;
        }
        
        snakeListNode = snakeList->head;
        while((snakeListNode->next)-> next != NULL) /*Shuffles all body values, except for the head of the snake, down one position in the snake.*/
        {
            snakeListNode->body = snakeListNode->next->body;
            snakeListNode = snakeListNode->next;
        }
        
        snakeList->tail->col = snakeList->tail->col - 1; /*Decreases the snakes head col coord by 1 as the user has moved the snake left, updates its head and tail body values accordingly*/
        snakeList->tail->body = '<';
        snakeList->tail->prev->body = '-';
        snakeList->head->body = '#';
        
        
    }
    else if (userMovement == 's')
    {
        snakeListNode = snakeList->head;
        while(snakeListNode->next != NULL) /*Shuffles all row/col values, except for the head of the snake, down one position in the snake.*/
        {
            snakeListNode->row = snakeListNode->next->row;
            snakeListNode->col = snakeListNode->next->col;
            snakeListNode = snakeListNode->next;
        }
        
        snakeListNode = snakeList->head;
        while((snakeListNode->next)-> next != NULL) /*Shuffles all body values, except for the head of the snake, down one position in the snake.*/
        {
            snakeListNode->body = snakeListNode->next->body;
            snakeListNode = snakeListNode->next;
        }
        
        snakeList->tail->row = snakeList->tail->row + 1; /*Increases the snakes head row coord by 1 as the user has moved the snake down, updates its head and tail body values accordingly*/
        snakeList->tail->body = 'v';
        snakeList->tail->prev->body = '|';
        snakeList->head->body = '#';
        
    }
    else if (userMovement == 'w')
    {
        snakeListNode = snakeList->head;
        while(snakeListNode->next != NULL) /*Shuffles all row/col values, except for the head of the snake, down one position in the snake.*/
        {
            snakeListNode->row = snakeListNode->next->row;
            snakeListNode->col = snakeListNode->next->col;
            snakeListNode = snakeListNode->next;
        }
        
        snakeListNode = snakeList->head;
        while((snakeListNode->next)-> next != NULL) /*Shuffles all body values, except for the head of the snake, down one position in the snake.*/
        {
            snakeListNode->body = snakeListNode->next->body;
            snakeListNode = snakeListNode->next;
        }
        
        snakeList->tail->row = snakeList->tail->row - 1; /*Decreases the snakes head row coord by 1 as the user has moved the snake up, updates its head and tail body values accordingly*/
        snakeList->tail->body = '^';
        snakeList->tail->prev->body = '|';
        snakeList->head->body = '#';
    }
    else if (userMovement == '\0') /*Called when a food piece is eaten meaning an extra body part has to be added to the snake*/
    {
        snakeListNode = snakeList->head;
        
        if (snakeListNode->next->body == '-') /*If the last body piece(excluding the tail) is horizontal, inserts a new body piece to the 1 col left of the tail, makes the new body piece the new tail of the entire snake and updates the old tail to a '-' body piece*/
        {
            insertFirst(snakeList,snakeListNode->next->row,(snakeListNode->next->col)-1, '#');
            snakeList->head->next->body = '-';
        }
        else if (snakeListNode->next->body == '|')
        {
            insertFirst(snakeList,(snakeListNode->next->row) - 1,snakeListNode->next->col,'#');
            snakeList->head->next->body = '|';
        }
    }
}
