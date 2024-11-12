CC = gcc
TARGET=runo
HEADERS=./headers/logger.h

all: $(TARGET)

logger.o: ./logger/console_logger.c $(HEADERS)
	$(CC) -O0 -g3 -Wall -c ./logger/console_logger.c

main.o:	main.c $(HEADERS)
	$(CC) -O0 -g3 -Wall -c main.c

$(TARGET): logger.o main.o 
	$(CC) -o ../build/runo main.o console_logger.o

clean:
	rm -f *.o

