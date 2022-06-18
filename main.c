#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define ADD_CMD "add"
#define TASK_FILE_PATH "/home/armands/Dev/Projects/Tick/task.list"
#define RESET_COLOUR "\e[0m"
#define RED_COLOUR "\e[0;31m"

struct Task{
  int number;
  char* entry;
};

void pError(char* str){
  printf("%sError:\n%s\n%s", RED_COLOUR, str, RESET_COLOUR);
}

char* joinArgs(int argc, char* args[]){
  char* str = NULL;
  return str;
}

int addTask(int argc, char* args[]){
  FILE *file_ptr;
  file_ptr = fopen(TASK_FILE_PATH, "a");
  if(file_ptr == NULL){
    pError("Unable to create task list file");
    return 1;
  }
  char* entry = joinArgs(argc, args);
  printf("Joined Args:\n%s\n", entry);
  fclose(file_ptr);
  return 0;
}

int main(int argc, char *argv[]){
  int STATUS = 0;
  if(argc){
    if(strcmp(argv[1], ADD_CMD) == 0){
      STATUS = addTask(argc, argv);
    }
  }
  return STATUS;
}

// TODO:
//   - Add
//   - Remove
