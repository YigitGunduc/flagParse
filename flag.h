#ifndef FLAGS_H_ /* Include guard */
#define FLAGS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>

#define MAX_NUMBER_OF_FLAGS 32

static int head = 0;

typedef enum {
  FLAG_BOOL = 0,
  FLAG_UINT = 1,
  FLAG_DOUBLE = 2,
  FLAG_STR = 3,
} Flag_Type;

typedef union {
  bool bool_val;
  double double_val;
  char *str_val;
  unsigned int uint_val;
} flag_value;

typedef struct {
  char *help;
  char *name;
  Flag_Type type;
  flag_value value;
} flag_t;

static flag_t flags[MAX_NUMBER_OF_FLAGS];

void add_flag(char *name, char *help, Flag_Type type)
{
  flag_t *flag = (flag_t*) malloc(sizeof(flag_t));

  flag->name = name;
  flag->help = help;
  flag->type = type;

  flags[head++] = *flag;
}

void get_help(int num_of_args, char *args[])
{
  bool help = false;
  for (int i = 1; i < num_of_args; i++)
  { 
    if (strcmp(args[i], "-h") == 0 || strcmp(args[i], "--help") == 0)
    {
      help = true;
    }
  }

  if (help)
  {
    for (int i = 0; i < head; i++)
    {
      printf("flag: %s\n", flags[i].name);
      printf("\t%s\n", flags[i].help);
      printf("\n");
    }
  }
}

void parse_flags(int num_of_args, char *args[])
{
  get_help(num_of_args, args);
  for (int i = 1; i < num_of_args; i++)
  { 
    for (int j = 0; j < head; j++)
    {
      if (strcmp(args[i], flags[j].name) == 0)
      {
        switch (flags[j].type)
        {
          case FLAG_BOOL: 
            flags[j].value.uint_val = atoi(args[i + 1]);
            break;

          case FLAG_UINT:
            flags[j].value.uint_val = atoi(args[i + 1]);
            break;

          case FLAG_DOUBLE:
            flags[j].value.double_val = atof(args[i + 1]);
            break;

          case FLAG_STR:
            flags[j].value.str_val = args[i + 1];
            break;

          default:
            fprintf(stderr, "[ERROR] unknown data type");
            exit(1);
        }
      }
    }
  }
}

char *get_str_val(char *name)
{
  for (int j = 0; j < head; j++)
  {
    if (strcmp(name, flags[j].name) == 0) 
    {
      return flags[j].value.str_val;
    }
  }
  return NULL;
}

unsigned int get_uint_val(char *name)
{
  for (int j = 0; j < head; j++)
  {
    if (strcmp(name, flags[j].name) == 0) 
    {
      return flags[j].value.uint_val; 
    }
  }
  return 0;
}

double get_double_val(char *name)
{
  for (int j = 0; j < head; j++)
  {
    if (strcmp(name, flags[j].name) == 0) 
    {
      return flags[j].value.double_val; 
    }
  }
  return 0;
}

bool get_bool_val(char *name)
{
  for (int j = 0; j < head; j++)
  {
    if (strcmp(name, flags[j].name) == 0) 
    {
      return flags[j].value.bool_val; 
    }
  }
  return 0;
}

#endif // FLAGS_H_
