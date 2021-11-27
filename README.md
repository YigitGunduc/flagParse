
# flagParse

A header-only library to parser command line arguments for C.

## Getting Started

Types

```c
typedef enum {
  FLAG_BOOL = 0,
  FLAG_UINT = 1,
  FLAG_DOUBLE = 2,
  FLAG_STR = 3,
} Flag_Type;

```

Adding a new flag
```c
  add_flag("--FLAG_NAME", "FLAG DESCRIPTION", Flag_Type);
```

Parsing flags
```c
  parse_flags(argc, argv); // parsing flags
```

Getting the value of the flags
```c
  // for flags which value if a double
  printf("value of flag 1 is: %f\n", get_double_val("--FLAG_NAME"));

  // for flags which value if a str
  printf("value of flag 2 is: %s\n", get_str_val("--FLAG_NAME"));

  // for flags which value if a bool
  printf("value of flag 3 is: %i\n", get_bool_val("--FLAG_NAME"));
  
  // for flags which value if a uint
  printf("value of flag 4 is: %i\n", get_uint_val("--FLAG_NAME"));

```

## License

[MIT](https://choosealicense.com/licenses/mit/)

