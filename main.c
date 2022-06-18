#include <stdio.h>
#include <string.h>

#define ADD_CMD "add"
#define TASK_FILE_PATH "~/armands/Dev/Projects/Tick/"

int addTask(int STATUS, char* args[]){
  return STATUS;
}

int main(int argc, char *argv[]){
  int STATUS = 0;
  if(argc){
    if(strcmp(argv[1], ADD_CMD) == 0){
      STATUS = addTask(STATUS, argv);
    }
  }else{
  }
  return STATUS;
}

// TODO:
//   - Add
//   - Remove
