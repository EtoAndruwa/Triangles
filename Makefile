CFLAGS = -g -c -Wall -Wextra -O0

EXE_FLAG_VALGRIND = valgrind -s --leak-check=yes --show-leak-kinds=all --track-origins=yes --log-file="logs/valgrind_log.txt" 

CC = g++
TARGET = TRIANGLES

PREF_OBJ = ./obj/
PREF_SRC = ./src/

TRIAN_SRC = $(wildcard $(PREF_SRC)*.cpp)
TRIAN_OBJ = $(patsubst $(PREF_SRC)%.cpp, $(PREF_OBJ)%.o, $(TRIAN_SRC))

OBJ = $(TRIAN_OBJ)

all : $(TARGET) run

$(TARGET) : $(OBJ) 
	$(CC) $(OBJ) -o $(TARGET).exe -lgtest -lgtest_main -pthread

$(PREF_OBJ)%.o : $(PREF_SRC)%.cpp
	$(CC) $(CFLAGS) $< -o $@

clean: 
	rm $(TARGET).exe $(PREF_OBJ)*.o

run:
	$(EXE_FLAG_VALGRIND) ./$(TARGET).exe