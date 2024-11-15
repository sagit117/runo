CC = gcc
TARGET = runo
HEADERS = ./headers/*.h
OBJECTS = ../build/*.o

all: $(TARGET)

logger.o: ./logger/console_logger.c ./headers/logger.h ./headers/common.h
	$(CC) -O0 -g3 -Wall -c ./logger/console_logger.c -o ../build/logger.o

params.o: ./params/params_cmd.c ./headers/params.h ./headers/logger.h
	$(CC) -O0 -g3 -Wall -c ./params/params_cmd.c -o ../build/params.o

config.o: ./config/config_app.c ./headers/config.h ./headers/common.h ./headers/utils.h ./headers/logger.h
	$(CC) -O0 -g3 -Wall -c ./config/config_app.c -o ../build/config.o

utils.o: ./utils/utils_string.c ./headers/utils.h
	$(CC) -O0 -g3 -Wall -c ./utils/utils_string.c -o ../build/utils.o

main.o:	main.c $(HEADERS) logger.o params.o config.o utils.o
	$(CC) -O0 -g3 -Wall -c main.c -o ../build/main.o

$(TARGET): main.o 
	$(CC) -o ../build/runo $(OBJECTS)

clean:
	rm -f ../build/*.o

