#include <stdio.h>
#include <stdlib.h>
#include "playArea.h"
#include "conditionCheck.h"
#include "random.h"
#include "snakeMaker.h"
#include "terminal.h"
#include "linkedList.h"


/*Jacob Arvino | 19817082
 Takes in a 2-D array and creates a '*' boundary and randomly placed food with char '@'. Also takes in user inputted movement and moves the snake accordingly.*/
int playArea(char** defaultArray, int rows, int columns, int totalFood, linkedList* snakeList, char userMovement)
{
    int i, x, y, randomFoodRow, randomFoodCol, lastRow, lastCol, invalidDimensions, snakeListCount, test;
    char winLossResult, boundResult, newFood, foodEaten, validLocation;
    linkedListNode* snakeListNode; /*Variable declarations*/
    
        for(x = 0; x < rows + 2; x++)
        {
            for( y = 0; y < columns + 2; y++)
            {
                if(x == 0 || x == (rows + 1))
                {
                    defaultArray[x][y] = '*'; /*Places '*' char around the border of the 2-D array*/
                }
                else if (y == 0 || y == (columns + 1))
                {
                    defaultArray[x][y] = '*'; /*Places '*' char around the border of the 2-D array*/
                }
                else if (y != 0 || y != (columns + 1))
                {
                    defaultArray[x][y] = ' '; /*Places ' ' char on the inside of the borders*/
                }
            }
        }
        if(userMovement == '\0' || newFood == 't')
        {
            validLocation = 'f';
            while (validLocation == 'f')
            {
                validLocation = 't';
                initRandom(); /*Calls random function*/
                randomFoodRow = Random(2,rows - 1); /*Assigns random int for the foods row coordinate*/
                randomFoodCol = Random(1,columns - 1);/*Assigns random int for the foods column coordinate*/
                snakeListNode = snakeList->head;
                
                while(snakeListNode->next != NULL) /*Checks each coordinate for each body part already occupied by the snake and checks if it equals the randomly generated food position. Repeats this process until the food coords =! any of the snake coords*/
                {
                    if(snakeListNode->row == randomFoodRow && snakeListNode->col == randomFoodCol)
                    {
                        validLocation = 'f';
                    }
                    snakeListNode = snakeListNode->next;
                }
            }
            defaultArray[randomFoodRow][randomFoodCol] = '@'; /*Assigns the @ char to a random position in the play area*/
            newFood = 'f';
        }
        
        if(userMovement == '\0')
        {
            foodEaten = 0; /*Sets food eaten to 0 as the user hasent moved the snake/eaten any food yet.*/
        }
    
        defaultArray[randomFoodRow][randomFoodCol] = '@'; /*Assigns the @ char to a random position in the play area*/
        
        snakeListCount = snakeList->count;
        snakeListNode = snakeList->head;
        
        for(x = 0; x < snakeListCount; x++)
        {
            defaultArray[snakeListNode->row][snakeListNode->col] = snakeListNode->body; /*Assigns the body chars into the play area area at each body pieces coordinates stored inside the snake linkedlist*/
            snakeListNode = snakeListNode->next;
        }
        
        while (winLossResult != 'l' || userMovement == '\0') /*Checks if the play area is being setup or if loss char has not been returned by the conditionCheck function*/
        {
            if(userMovement == '\0' || newFood == 't')
            {
                validLocation = 'f';
                while (validLocation == 'f') /*Checks each coordinate for each body part already occupied by the snake and checks if it equals the randomly generated food position. Repeats this process until the food coords =! any of the snake coords*/
                {
                    validLocation = 't';
                    initRandom(); /*Calls random function*/
                    randomFoodRow = Random(2,rows - 1); /*Assigns random int for the foods row coordinate*/
                    randomFoodCol = Random(1,columns - 1);/*Assigns random int for the foods column coordinate*/
                    snakeListNode = snakeList->head;
                    
                    while(snakeListNode->next != NULL)
                    {
                        if(snakeListNode->row == randomFoodRow && snakeListNode->col == randomFoodCol)
                        {
                            validLocation = 'f';
                        }
                        snakeListNode = snakeListNode->next;
                    }
                    
                }
                defaultArray[randomFoodRow][randomFoodCol] = '@'; /*Assigns the @ char to a random position in the play area*/
                newFood = 'f';
            }
            
            if (userMovement == 'w' || userMovement == 'a' || userMovement == 's' || userMovement == 'd' || userMovement == '\0') /*Checks that user inputted movement is valid*/
            {
                if(boundCheck(snakeList, rows, columns, userMovement) == 'n') /*Does the bound check to see if the users desired movement is 'illegal'*/
                {
                    for(x = 0; x < (rows + 2); x++)
                    {
                        for( y = 0; y < (columns + 2); y++)
                        {
                            printf("%c", defaultArray[x][y]); /*Prints the array, which has not be altered, until the users inputs a valid movement command*/
                        }
                        printf("\n");
                    }
                    printf("Food eaten: %d / %d\n", foodEaten, totalFood);
                    printf("Cannot move snake beyond play area bounds\n");
                    
                    disableBuffer();
                    scanf(" %c", &userMovement);
                    enableBuffer();
                    system("clear"); /*Asks users for another character and clears the terminal screen*/
                }
                else /*Enters this else statement if the user's movement is 'legal'*/
                {
                    if(userMovement != '\0')
                    {
                        defaultArray[snakeList->head->row][snakeList->head->col] = ' ';
                        snakeUpdater(snakeList, userMovement); /*Calls the snakeUpdater function with the 2 specified paramaters*/
                    }
                    
                    snakeListCount = snakeList->count;
                    snakeListNode = snakeList->head;
                    
                    for(x = 0; x < snakeListCount; x++)
                    {
                        defaultArray[snakeListNode->row][snakeListNode->col] = snakeListNode->body; /*Assigns the body chars into the play area area at each body pieces coordinates stored inside the snake linkedlist*/
                        snakeListNode = snakeListNode->next;
                    }
                    
                    for(x = 0; x < (rows + 2); x++)
                    {
                        for( y = 0; y < (columns + 2); y++)
                        {
                            printf("%c", defaultArray[x][y]); /*Prints the array, which has not be altered, until the users inputs a valid movement command*/
                        }
                        printf("\n");
                    }
                    printf("Food eaten: %d / %d", foodEaten, totalFood);
            
                    winLossResult = winLossCheck(snakeList, randomFoodRow, randomFoodCol); /*Calls the winLossCheck function and assigns the return value to winLossResult*/
                    
                    if(winLossResult == 'l') /*If the winLossCheck function determines that the loss condition has been met, the game ends*/
                    {
                        printf("\nYou lose :(\n");
                        return 0; /*Prints a loss message and frees both malloc'd arrays as the function is over*/
                    }
                    else if (winLossResult == 'w' && foodEaten == totalFood - 1) /*If the winLossCheck function determines that the win condition has been met, the game ends*/
                    {
                        printf("\nYou won!\n");
                        return 0; /*Prints a win message and frees both malloc'd arrays as the function is over*/
                    }
                    else if (winLossResult == 'w') /*If the user eats the food, but they have not eaten the required number of food, increases the number of food eaten by 1 and calls the snakeUpdater function with the default char to generate a new food location*/
                    {
                        newFood = 't';
                        foodEaten = foodEaten + 1;
                    
                        snakeUpdater(snakeList, '\0');
                        
                        disableBuffer();
                        scanf(" %c", &userMovement);
                        enableBuffer();
                        system("clear"); /*If the neutral char was returned from the winLossCheck function, ask the user for a new movement char and repeat the process until a win/loss condition is met*/
                    }
                    else
                    {
                    
                        disableBuffer();
                        scanf(" %c", &userMovement);
                        enableBuffer();
                        system("clear"); /*If the neutral char was returned from the winLossCheck function, ask the user for a new movement char and repeat the process until a win/loss condition is met*/
                    }
                }
            }
            else
            {
                for(x = 0; x < (rows + 2); x++)
                {
                    for( y = 0; y < (columns + 2); y++)
                    {
                        printf("%c", defaultArray[x][y]); /*Prints the array, which has not be altered, until the users inputs a valid movement command*/
                    }
                    printf("\n");
                }
            
                printf("Food eaten: %d / %d\n", foodEaten, totalFood);
                printf("Invalid input!\n");
                
            
                disableBuffer();
                scanf(" %c", &userMovement);
                enableBuffer();
                system("clear"); /*Asks user for a valid input and clears terminal*/
            }
        }
    return 0;
}

