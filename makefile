FILES = main.c
FLAGS = -Wall -Werror -fstack-protector -fsanitize=leak -fsanitize=address
BIN = tick
OUT = task.list
ARGS ?=
ARGS ?= add do my laundry
CC = gcc

all: compile run read clean

compile: $(FILES)
	$(CC) $(FILES) -o $(BIN) $(FLAGS)

wipe: $(OUT).bak
	cat $(OUT).bak > $(OUT)

run: $(BIN)
	-./$(BIN) $(ARGS)

read: $(OUT)
	@echo "--- TASK LIST START ---"
	@cat $(OUT)
	@echo "---  TASK LIST END  ---"

clean: $(BIN)
	rm $(BIN)

.PHONY: wipe read clean

