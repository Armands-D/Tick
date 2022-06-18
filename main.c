#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ADD_CMD "add"
#define TASK_FILE_PATH "/home/armands/Dev/Projects/Tick/task.list"
#define RESET_COLOUR "\e[0m"
#define RED_COLOUR "\e[0;31m"

void pError(char* str){
  printf("%sError:\n%s\n%s", RED_COLOUR, str, RESET_COLOUR);
}

char* join(int argc, char* args[]){
  int str_size = 1;
  char* str = (char*)calloc(str_size, sizeof(char));
  for(int i = 2; i < argc; i ++){
    char* arg = args[i];
    int arg_size = strlen(arg) + 1;
    str_size +=  arg_size;
    str = (char *)realloc(str, str_size);
    printf("Arg Size: %d\nStr Alloc Size: %d\n\n", arg_size, str_size);
    str = strcat(str, arg);
    str = strcat(str, " ");
  }
  str[str_size - 2] = '\0'; // Remove space at the end
  str = (char*)realloc(str, str_size - 1);
  return str;
}

int addTask(int argc, char* args[]){
  FILE *file_ptr;
  file_ptr = fopen(TASK_FILE_PATH, "a");
  if(file_ptr == NULL){
    pError("Unable to create task list file");
    return 1;
  }
  if(argc < 3){
    pError("Cannot add empty task");
    return 1;
  }
  char* entry = join(argc, args);
  printf("Joined args = '%s'\n", entry);
  fprintf(file_ptr, "TASK: %s\n", entry);
  free(entry);
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
