#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 

#define MAX_NUMBER_OF_FLAGS 32

static int head = 0;

typedef enum {
  FLAG_BOOL = 0,
  FLAG_UINT = 1,
  FLAG_DOUBLE = 2,
  FLAG_STR = 3,
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

void add_flag(char *name, char *desc, Flag_Type type)
{
  flag_t flag = {.name = name, .desc = desc, .type = type};

  flags[head++] = flag;
}

// TODO: test in function
bool in(char **arr, char *val, int length)
{
  for (int i = 0; i < length; i++)
  { 
    printf("i th value %s\n", arr[i]);
    if (strcmp(arr[i], val) == 0)
    {
      return true;
    }
  }
  return false;
}

void parse_flags(int num_of_args, char *args[])
{
  bool help = false;
  for (int i = 1; i < num_of_args; i++)
  { 
    if (strcmp(args[i], "-h") == 0)
    {
      help = true;
    }
    if (help)
    {
      for (int i = 0; i < head; i++)
      {
        printf("flag: %s\n", flags[i].name);
        printf("\t%s\n", flags[i].desc);
      }
    }
    for (int j = 0; j < head; j++)
    {
      if (strcmp(args[i], flags[j].name) == 0)
      {
        switch (flags[j].type)
        {
          case FLAG_BOOL: 
            break;

          case FLAG_UINT: // code to be executed if n = 2;
            flags[j].value.uint_val = atoi(args[i + 1]);
            break;

          case FLAG_DOUBLE:// code to be executed if n = 2;
            flags[j].value.double_val = atof(args[i + 1]);
            break;

          case FLAG_STR:// code to be executed if n = 2;
            flags[j].value.str_val = args[i + 1];
            break;

          default: // code to be executed if n doesn't match any cases
            printf("[ERROR] unknown data type");
            exit(1);
        }
      }
    }
  }
}

void get_flag(void) {}

int main(int argc, char *argv[])
{
  add_flag("--f1", "type of this flag is unsigned int", FLAG_DOUBLE);
  add_flag("--f2", "type of this flag is string", FLAG_STR);

  parse_flags(argc, argv);

  printf("value of %s\n", flags[1].value.str_val);

  return 0;
}
