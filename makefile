BIN = main
cc = g++
OBJ = main.o

$(BIN): $(OBJ)
	$(cc) $(OBJ) -o $(BIN)

.cpp.o:
	$(cc) -c $<

clean:
	rm *.o $(BIN)

