#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char ** parse_args(char * line){
  char ** args = calloc(6, sizeof(line)); // maximum number of args is 5, with maximum size of line
                                          // also one at the end for the NULL
  char * line_copy = malloc(sizeof(line));
  strcpy(line_copy, line);

  int c = 0;
  while((args[c] = strsep(&line_copy, " ")) && ++c);

  return args;
}

int main(){
  char * line = "ls -a -l";
  char ** args = parse_args(line);

  execvp(args[0], args);

  return 0;
}
