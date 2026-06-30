CC = gcc

CFLAGS = -Wall -Wextra -Wpedantic -std=c99 -Iinclude $(shell pkg-config --cflags raylib)

LDFLAGS = $(shell pkg-config --libs raylib)

SRC = $(wildcard src/*.c)

OBJ = $(SRC:.c=.o)

TARGET = game_of_life

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all run clean