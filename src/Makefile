CC = gcc
TARGET = runo
HEADERS = ./headers/*.h
OBJECTS = *.o

all: $(TARGET)

logger.o: ./logger/console_logger.c $(HEADERS)
	$(CC) -O0 -g3 -Wall -c ./logger/console_logger.c

params.o: ./params/check_params_cmd.c $(HEADERS)
	$(CC) -O0 -g3 -Wall -c ./params/check_params_cmd.c

main.o:	main.c $(HEADERS)
	$(CC) -O0 -g3 -Wall -c main.c

$(TARGET): main.o logger.o params.o
	$(CC) -o ../build/runo $(OBJECTS)

clean:
	rm -f *.o

