.SUFFIXES: .cpp .o .x
CC = g++
CFLAGS = -std=c++11
GRAFICZNIE =  -lsfml-graphics -lsfml-window -lsfml-system

name1 = main
target1 = $(name1).cpp
OBJECT1 = $(name1).o
EXEC1 = $(name1).x

LIBS =
RM = rm -f

# Reguła kompilacji pliku źródłowego na plik obiektowy
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Reguła kompilacji pliku obiektowego na plik wykonywalny
$(EXEC1): $(OBJECT1)
	$(CC) $(CFLAGS) $(OBJECT1) -o $(EXEC1) $(GRAFICZNIE)

# Określenie celów sztucznych.
.PHONY: clean run1 

clean:
	$(RM) $(EXEC1)  *.o cor

run1: $(EXEC1)
	./$(EXEC1)

-std=c++11
