#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FLAG_LENGTH 256

typedef enum {
    FLAG_STR = 0,
    FLAG_FLOAT,
    FLAG_BOOL,
    FLAG_UINT64,
    FLAG_UINT32,
    FLAG_DOUBLE,
} Flag_Type;

typedef struct {
  char* desc;
	Flag_Type type;
	Flag_Type value;
  char *name;
} flag_t;

void parser_args(int argc, char *argv[], char flag[])
{
    for (int i = 1; i < argc; i++) 
    {
      if (strcmp(argv[i], flag) == 0)
      {
        puts("found");
      }
    }
}

flag_t* add_flag(char *name, char *desc, Flag_Type type)
{
  flag_t *flag = malloc(sizeof(flag_t));
  flag->name = name;
  flag->desc = desc;
  flag->type = type;

  return flag;
}

int main(int argc, char* argv[])
{
    flag_t* flag = add_flag("flag name", "flag desc", 1);
    printf("%s\n", flag->name);

    return 0;
}
