#ifndef CONDITIONCHECK_H
#define CONDITIONCHECK_H
struct linkedList;

char winLossCheck(struct linkedList* snakeList, int foodRow, int foodCol);
char boundCheck(struct linkedList* snakeList, int playAreaRow, int playAreaCol, char userMovement);

#endif

