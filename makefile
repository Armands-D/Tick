FILES = main.c
FLAGS = -Wall -Werror -fstack-protector -fsanitize=leak -fsanitize=address
OUT = tick
ARGS = add do my laundry
CC = gcc

all: compile run clean

compile: $(FILES)
	$(CC) $(FILES) -o $(OUT) $(FLAGS)

run: $(OUT)
	-./$(OUT) $(ARGS)

clean: $(OUT)
	rm $(OUT)

.PHONY: clean

