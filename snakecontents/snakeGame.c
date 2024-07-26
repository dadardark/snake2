#include<stdio.h>
#include<stdlib.h>
#include"playArea.h"
#include"linkedList.h"
#include"readFile.h"

/*Jacob Arvino | 19817082
 Dynamically creates a 2-D array based on the command-line arguments specified by the user. which is then passed to the playArea function*/
int main(int argc, char** argv)
{
    int i, row, col, end, totalFood, total, correctFood;
    int* dimensionsArray;
    char userMovement;
    char* fileName;
    char** array;
    linkedList* snakeList; /*Variable declaration*/
    
    correctFood = 0;
    while(correctFood != 1)
    {
        if(argc != 3)
        {
            printf("Invalid number of arguments. Program Usage: \n ./snake <File name> <# of Food to Win>");
            return 0; /*Checks that the number of command-line arguments is equal to the number required to run the program*/
        }
        
        if(atoi(argv[2]) < 2)
        {
            printf("Number of food to win must be atleast 2\n");
            return 0;
        }
        else
        {
            correctFood = 1;
        }
    }
        
    userMovement = '\0'; /*Sets user movement to the default char so that the playArea, snakeCoords, snakeChar and food location can be setup*/
   
    /*fileName = argv[1];
    dimensionsArray = (int*)malloc(2  *sizeof(int*));
     
    readFileDimensions(dimensionsArray, fileName);
     
    snakeList = createLinkedList();                                 Refer to Assignment2Report.
    readFile(snakeList, "snake.txt");
     
    row = dimensionsArray[0];
    col = dimensionsArray[1];*/
    
    row = 20;
    col = 30;
    totalFood = atoi(argv[2]);
    
    array = (char**)malloc((row + 2) * sizeof(char*)); /*Dynamically creates an array of size row with char pointers*/

    for(i = 0; i < (row + 2); i++)
    {
        array[i] = (char*)malloc((col + 2) * sizeof(char));/*For each char pointer in the array, assigns it column number of char memory */
    }
    
    snakeList = createLinkedList();
    insertLast(snakeList,6,10,'#');
    insertLast(snakeList,7,10,'|');
    insertLast(snakeList,8,10,'|');
    insertLast(snakeList,8,9,'-');
    insertLast(snakeList,8,8,'-');
    insertLast(snakeList,8,7,'-');
    insertLast(snakeList,9,7,'|');
    insertLast(snakeList,10,7,'|');
    insertLast(snakeList,11, 7,'|');
    insertLast(snakeList,12,7,'|');
    insertLast(snakeList,13,7,'v');
    
    end = playArea(array, row, col, totalFood, snakeList, userMovement); /*Calls the playArea function with the required parameters*/
    
    if(end == 0)
    {
        for(i = 0; i < (row + 2); i++)
        {
            free(array[i]);
        }
        free(array); /*Frees the play area array once the game is won/loss*/
        freeList(snakeList);
    }
}
