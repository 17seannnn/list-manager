#include <stdio.h>

#include "help.h"

void help_short()
{
        printf("Invalid command, try 'h' for help\n");
}

void help_full()
{
        printf("\
Here 3 modes:\n\
        [S/s]ingle-linked list\n\
        [D/d]oubly-linked list\n\
        [B/b]inary tree\n\
You can manage dynamic data structures by these commands:\n\
        [M/m] - change mode\n\
        [C/c] - change current pointer\n\
        [A/a] - add item\n\
        [D]   - dispose all\n\
        [d]   - dispose current\n\
        [S]   - show all\n\
        [s]   - search item\n\
Also these commands can be useful too:\n\
        [H/h] - this help\n\
        [Q/q] - quit\n");
}
