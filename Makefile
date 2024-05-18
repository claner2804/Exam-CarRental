# Variablen
CC = g++
CFLAGS = -Wall -std=c++11

# Dateien
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = main

# Regeln
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)