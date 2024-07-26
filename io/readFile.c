#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#include "readFile.h"
/* Jacob Arvino | 19817081 | Refer to Assignment2Report for more information
 Function that reads in a file and creates a linkedList struct (snake struct) based on the input*/
linkedList* readFile(linkedList* snakeList, char* fileName)
{
    FILE* snakeFile;
    int lineCount, splitCount, snakeRow, snakeCol;
    char snakeBody;
    char line[100];
    char* splitLine;
    linkedListNode* snakeListNode; /*Variable declaration*/
    
    snakeFile = fopen(fileName,"r"); /*Creates a file stream set to read based on user inputted file name*/

    if(snakeFile == NULL)
    {
        perror("Error opening file: ");
    }
    else
    {
        lineCount = 0;
        splitCount = 0;
        
        fgets(line,sizeof(line),snakeFile); /*Reads in a line*/
        
            splitLine = strtok(line, " "); /*Splits the line by the space delimiter*/
            
            while(splitLine != NULL)
            {
                if(splitCount == 0) /*Stores the first element read into the snakeRow variable. Increments splitcount by 1*/
                {
                    snakeRow = atoi(splitLine);
                    splitCount++;
                }
                else if (splitCount == 1)
                {
                    snakeCol = atoi(splitLine);/*Stores the second element read into the snakeCol variable. Increments splitcount by 1*/
                    splitCount++;
                }
                else if (splitCount == 2)/*Stores the third element read into the snakeBody variable. Since all 3 parts of the snake have been read in, signified by the splitCount number, the snake body node is inserted into the list, and the splitCount is reset.*/
                {
                    snakeBody = *splitLine;
                    insertLast(snakeList, snakeRow, snakeCol, snakeBody);
                    splitCount = 0;
                }
                splitLine = strtok(NULL, " ");/*Reads the element in the line, seperated by the delimitier.*/
            }
    }
    fclose(snakeFile);
    return snakeList;/*Closes file and returns the snakeList linkedList struct*/
}

/* Jacob Arvino | 19817081 | Refer to Assignment2Report for more information
 Function that reads in a file and returns the row and col values for the playArea*/
int* readFileDimensions(int* dimensionsArray, char* fileName)
{
    FILE* snakeFile;
    int row, col, count;
    char line[100];
    char* splitLine;
    snakeFile = fopen(fileName,"r"); /*Variable declaration*/

    if(snakeFile == NULL)
    {
        perror("Error opening file: ");
    }
    else
    {
        fgets(line,sizeof(line),snakeFile); /*Reads in a line*/
        splitLine = strtok(line, " "); /*Splits the line by the space delimiter*/
        count = 0;
        while(splitLine != NULL)
        {
            if (count == 0) /*Stores first read in element in the row variable. Increases count by 1.*/
            {
                row = atoi(splitLine);
                count++;
            }
            else if (count == 1)
            {
                col = atoi(splitLine);/*Stores second read in element in the col variable. Increases count by 1.*/
                count++;
            }
            splitLine = strtok(NULL, " ");/*Reads the element in the line, seperated by the delimitier.*/
        }
        
        dimensionsArray[0] = row;
        dimensionsArray[1] = col; /*Stores values in array*/
    }
    fclose(snakeFile);
    return dimensionsArray;/*Closes files and returns array*/
}

