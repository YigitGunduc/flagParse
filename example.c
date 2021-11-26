#include <stdio.h>
#include "flags.h"

int main(int argc, char *argv[])
{
  add_flag("--flag1", "this flags has a value of double", FLAG_DOUBLE);
  add_flag("--flag2", "this flag has a value of str", FLAG_STR); 
  add_flag("--flag3", "this flag has a value of bool", FLAG_BOOL); 
  add_flag("--flag4", "this flag has a value of uint", FLAG_UINT); 

  parse_flags(argc, argv); // parsing flags

  printf("value of flag 1 is: %f\n", get_double_val("--flag1"));
  printf("value of flag 2 is: %s\n", get_str_val("--flag2"));
  printf("value of flag 3 is: %i\n", get_bool_val("--flag3"));
  printf("value of flag 4 is: %i\n", get_uint_val("--flag4"));

  return 0;
}
