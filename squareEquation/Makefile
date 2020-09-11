CC:=gcc
CFLAGS:=-Wall

SRC:=src
OBJ:=obj
BIN:=bin
DOCS:=docs

.PHONY: full docs exeFile runExe clean tests runTests

full: exeFile docs tests

exeFile: $(BIN)/exeFile

docs: $(DOCS)/index.html

tests: $(BIN)/tests

runExeFile: $(BIN)/exeFile
	$?

runTests: $(BIN)/tests
	$?

clean:
	@echo "Removing $(OBJ), $(BIN), and $(DOCS) directories"
	@rm -rf $(OBJ) $(BIN) $(DOCS)

Program files:

$(BIN)/exeFile: $(OBJ)/main.o
	@echo "Linking $@"
	@mkdir -p $(BIN)
	@$(CC) -o $@ $^ -lm

$(OBJ)/main.o: $(SRC)/main.c $(OBJ)/solveEquation.o  $(OBJ)/output.o
	@echo "Compiling $@"
	@mkdir -p $(OBJ)
	@$(CC) -c $(CFLAGS) -o $@ $<

$(BIN)/tests: $(OBJ)/tests.o $(OBJ)/solveEquation.o
	@echo "Linking $@"
	@mkdir -p $(BIN)
	@$(CC) -o $@ $^ -lm

$(OBJ)/tests.o: $(SRC)/tests.c $(SRC)/testLibrary.c
	@echo "Compiling $@"
	@mkdir -p $(OBJ)
	@$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ)/solveEquation.o: $(SRC)/solveEquation.c $(SRC)/calculate.c
	@echo "Compiling $@"
	@mkdir -p $(OBJ)
	@$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ)/output.o: $(SRC)/output.c
	@echo "Compiling $@"
	@mkdir -p $(OBJ)
	@$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ)/testing.o: $(SRC)/testing.c
	@echo "Compiling $@"
	@mkdir -p $(OBJ)
	@$(CC) -c $(CFLAGS) -o $@ $<

# Documentation:

$(DOCS)/index.html: $(wildcard $(SRC)/*)
	@echo "Compiling documentation"
	@doxygen Doxyfile