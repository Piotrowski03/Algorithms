.SUFFIXES: .cpp .o .x
CC = g++
CFLAGS = -Wall -std=c++11

name1 = bubblesort
name2 = quicksort
target1 = $(name1).cpp
target2 = $(name2).cpp
OBJECT1 = $(name1).o
OBJECT2 = $(name2).o
EXEC1 = $(name1).x
EXEC2 = $(name2).x

LIBS =
RM = rm -f

# Reguła kompilacji pliku źródłowego na plik obiektowy
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Reguła kompilacji pliku obiektowego na plik wykonywalny
$(EXEC1): $(OBJECT1)
	$(CC) $(CFLAGS) $(OBJECT1) -o $(EXEC1)

$(EXEC2): $(OBJECT2)
	$(CC) $(CFLAGS) $(OBJECT2) -o $(EXEC2)

# Określenie celów sztucznych.
.PHONY: clean run1 run2

clean:
	$(RM) $(EXEC1) $(EXEC2) *.o cor

run1: $(EXEC1)
	./$(EXEC1)

run2: $(EXEC2)
	./$(EXEC2)


