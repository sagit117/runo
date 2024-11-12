CC = gcc
TARGET = runo
HEADERS = ./headers/logger.h
OBJECTS = main.o console_logger.o

all: $(TARGET)

logger.o: ./logger/console_logger.c $(HEADERS)
	$(CC) -O0 -g3 -Wall -c ./logger/console_logger.c

main.o:	main.c $(HEADERS)
	$(CC) -O0 -g3 -Wall -c main.c

$(TARGET): logger.o main.o 
	$(CC) -o ../build/runo $(OBJECTS)

clean:
	rm -f *.o

