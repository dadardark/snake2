#include <stdlib.h>
#include <stdio.h>
#include"linkedList.h"


/*Jacob Arvino | 19817082
Function that determines whether the player has won or lost the game, based on the position of the snake head relative to its body/the food. */
char winLossCheck(linkedList* snakeList, int foodRow, int foodCol)
{
    char result;
    linkedListNode* snakeListNode;
    
    if(snakeList->tail->row == foodRow && snakeList->tail->col == foodCol) /* Checks if the snake's head coordinates equal the coordinates of the randomly placed food*/
    {
        result = 'w';/* Assigns result the win character*/
    }
    else
    {
        snakeListNode = snakeList->head;
        while(snakeListNode->next != NULL)
        {
            if(snakeList->tail->row == snakeListNode->row && snakeList->tail->col == snakeListNode->col)
            {
                result = 'l'; /*If the user has not lost or won, the neutral character is returned.*/
                return result;
            }
            snakeListNode = snakeListNode->next;
        }
        
    }
    return result;
}
    
/*Jacob Arvino | 19817082
Function that determines if the players next move will cause the snake's head to be beyond the boundary of the playing area */
char boundCheck(linkedList* snakeList, int playAreaRow, int playAreaCol, char userMovement)
{
    char result; /* Variable initialisation*/
    
    if(userMovement == 'a') /* Determines where the head is going to be moved to based on the users input */
    {
        if((snakeList->tail->col) - 1 == 0) /* If the user tries to move the snake head to the 0th column (left '*' boundary of the play area) returns the n character*/
        {
            result = 'n';
        }
    }
    else if(userMovement == 'd')
    {
        if((snakeList->tail->col) + 1 == playAreaCol + 1) /* If the user tries to move the snake head to the final column (right '*' boundary of the play area) returns the n character*/
        {
            result = 'n';
        }
    }
    else if(userMovement == 'w') /* If the user tries to move the snake head to the 0th row (top '*' boundary of the play area) returns the n character*/
    {
        if((snakeList->tail->row) - 1  == 0)
        {
            result = 'n';
        }
    }
    else if(userMovement == 's') /* If the user tries to move the snake head to the final row (bottom '*' boundary of the play area) returns the n character*/
    {
        if((snakeList->tail->row) + 1 == playAreaRow + 1)
        {
            result = 'n';
        }
    }
    else
    {
        result = 'y'; /*If the snake head does not exceed the play area boundaries, the y character is returned.*/
    }
    
    return result;
    

}
