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
    int arg_size = strlen(arg);
    str_size +=  arg_size + 1;
    str = (char *)realloc(str, str_size);
    str = strcat(str, arg);
    str = strcat(str, " ");
    printf("Str: '%s'\nArg Size: %d\nStr Alloc Size: %d\n\n",str, arg_size, str_size);
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
  fprintf(file_ptr, "TASK: %s\n", entry);
  free(entry);
  fclose(file_ptr);
  return 0;
}

int readTasks(char** task_array, int size){
  if(task_array == NULL){
    //char** task_array = (char**)calloc(0, sizeof(char));
  }
  FILE *file_ptr;
  file_ptr = fopen(TASK_FILE_PATH, "r");
  if(file_ptr == NULL){
    pError("Unable to create task list file");
    return 1;
  }

  char c;
  int ln_size = 1;
  char *line = (char*)calloc(ln_size, sizeof(char));
  while(((c = fgetc(file_ptr)) != EOF)){
    if(c != '\n'){
      ln_size ++;
      line = (char*)realloc(line, ln_size);
      line[ln_size - 1] = '\0';
      line[ln_size - 2] = c;
      printf("ReadChar: %c\n", c);
    }else{
      printf("ReadLine: '%s'\n", line);
      free(line);
      ln_size = 1;
      line = (char*)calloc(ln_size, sizeof(char));
    }
  }
  free(line);
  fclose(file_ptr);
  return 0;
}

int printTasks(){
  char** task_arr = (char**)calloc(0, sizeof(char));
  int ta_size = 0;
  int status = readTasks(task_arr, ta_size);
  if(status){
    free(task_arr);
    return status;
  }
  free(task_arr);
  return status;
}

int main(int argc, char *argv[]){
  int STATUS = 0;
  if(argc > 1){
    if(strcmp(argv[1], ADD_CMD) == 0){
      STATUS = addTask(argc, argv);
    }
  }else{
    STATUS = printTasks();
  }
  return STATUS;
}

// TODO:
//   - Add
//   - Remove
