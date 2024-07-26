CC = gcc
CFLAGS = -pedantic -ansi -Werror
OBJ = snakeGame.o playArea.o conditionCheck.o random.o snakeMaker.o readFile.o linkedList.o
EXEC = snake

snake : snakeGame.o playArea.o conditionCheck.o random.o snakeMaker.o terminal.o readFile.o linkedList.o
	gcc snakeGame.o playArea.o conditionCheck.o random.o snakeMaker.o terminal.o readFile.o linkedList.o -o snake 
	
snakeGame.o: snakeGame.c playArea.c terminal.c readFile.c linkedList.c playArea.h terminal.h readFile.h linkedList.h
	$(CC) -c snakeGame.c $(CFLAGS) playArea.c $(CFLAGS) readFile.c $(CFLAGS) linkedList.h $(CFLAGS)

playArea.o: playArea.c conditionCheck.c random.c snakeMaker.c terminal.c linkedList.c playArea.h conditionCheck.h random.h snakeMaker.h terminal.h linkedList.h
	$(CC) -c playArea.c $(CFLAGS) conditionCheck.c $(CFLAGS) random.c $(CFLAGS) snakeMaker.c $(CFLAGS) terminal.c $(CFLAGS) $(CFLAGS) linkedList.c
	
conditionCheck.o: conditionCheck.c conditionCheck.h linkedList.c linkedList.h
	$(CC) -c conditionCheck.c $(CFLAGS) linkedList.c $(CFLAGS)
	
random.o: random.c random.h
	$(CC) -c random.c $(CFLAGS)
	
snakeMaker.o: snakeMaker.c snakeMaker.h linkedList.c linkedList.h
	$(CC) -c snakeMaker.c $(CFLAGS) linkedList.c $(CFLAGS) 
	
terminal.o: terminal.c terminal.h
	$(CC) -c terminal.c $(CFLAGS)

readFile.o: readFile.c readFile.h linkedList.c linkedList.h
	$(CC) -c readFile.c $(CFLAGS) linkedList.c $(CFLAGS)

linkedList.o: linkedList.c linkedList.h
	$(CC) -c linkedList.c $(CFLAGS)

clean:
		rm -f $(EXEC) $(OBJ)
