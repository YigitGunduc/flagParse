/*
 *
 
 Python implementation

import sys

class Args:
    def __init__(self):
        self.flags = []
        self.desc = []
        self.values = {}

    def get_flag(self, arg):
        return self.values.get(arg, None)

    def add_arg(self, arg, desc=''):
        if arg[:2] != '--':
            arg = '--' + arg

        self.flags.append(arg)
        self.desc.append(str(arg) + ' | ' + str(desc))

    def parse(self):
        self.__parse()

    def __parse(self):
        args = sys.argv[1:]

        if '--help' in args or '-h' in args:
            print('help')
            for i in range(len(self.desc)):
                print(self.desc[i])

        for i in range(len(self.flags)):
            for j in range(len(args)):
                if args[j] == self.flags[i]:
                    value = args[j + 1]
                    self.values[args[j]] = value


                }

*/


#include <stdio.h>
#include <stdlib.h>

#define MAX_FLAG_LENGTH 256


void parse_cmdline(int argc, char *argv[])
{
}

int parser_args(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++) 
    {
        printf("%s\n", argv[i]);
    }

}

int main(int argc, char* argv[])
{
    parser_args(argc, argv);

    return 0;
}






