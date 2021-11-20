#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 

#define MAX_NUMBER_OF_FLAGS 32

typedef enum {
  FLAG_BOOL = 0,
  FLAG_UINT,
  FLAG_DOUBLE,
  FLAG_STR,
} Flag_Type;

typedef struct {
  bool bool_val;
  double double_val;
  char *str_val;
  unsigned int uint_val;
} flag_value;

typedef struct {
  char *desc;
  char *name;
  Flag_Type type;
  flag_value value;
} flag_t;

static flag_t flags[MAX_NUMBER_OF_FLAGS];

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

flag_t *add_flag(char *name, char *desc, Flag_Type type)
{
  flag_t *flag = malloc(sizeof(flag_t));
  flag->name = name;
  flag->desc = desc;
  flag->type = type;

  return flag;
}

int main(int argc, char* argv[])
{
  flag_t* flag = add_flag("--flagname", "flagdesc", 1);
  printf("%s\n", flag->name);

  return 0;
}
