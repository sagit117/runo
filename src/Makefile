CC = gcc
TARGET=runo

all: $(TARGET)

logger.o: ./headers/logger.h
	$(CC) -O0 -g3 -Wall -c ./logger/console_logger.c

main.o:	main.c ./headers/logger.h
	$(CC) -O0 -g3 -Wall -c main.c

$(TARGET): logger.o main.o 
	$(CC) -o ../build/runo main.o console_logger.o

clean:
	rm -f *.o

