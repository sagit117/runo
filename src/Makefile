CC = gcc
TARGET = runo
HEADERS = ./headers/*.h
OBJECTS = ../build/*.o

all: $(TARGET)

logger.o: ./logger/console_logger.c $(HEADERS)
	$(CC) -O0 -g3 -Wall -c ./logger/console_logger.c -o ../build/logger.o

params.o: ./params/params_cmd.c $(HEADERS)
	$(CC) -O0 -g3 -Wall -c ./params/params_cmd.c -o ../build/params.o

config.o: ./config/config_app.c $(HEADERS)
	$(CC) -O0 -g3 -Wall -c ./config/config_app.c -o ../build/config.o

main.o:	main.c $(HEADERS)
	$(CC) -O0 -g3 -Wall -c main.c -o ../build/main.o

$(TARGET): main.o logger.o params.o config.o
	$(CC) -o ../build/runo $(OBJECTS)

clean:
	rm -f ../build/*.o

