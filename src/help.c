/* help.c */

#include <stdio.h>
#include "gtmd.h"
#include "version.h"

#include "help.h"

void help_opt()
{
        printf(_("\
Usage: %s [OPTION]\n\
\n\
Options:\n\
        -h, --help      this help\n\
        -V, --version   show version\n\
\n\
Report bugs to & %s home page: <%s>\n"),
               PACKAGE_NAME, PACKAGE_NAME, PACKAGE_PAGE);
}

void help_short()
{
        printf(_("Invalid command, try 'h' for help.\n"));
}

void help_full()
{
        printf(_("\
Here 3 modes:\n\
        [S/s] - single-linked list\n\
        [D/d] - doubly-linked list\n\
        [B/b] - binary tree\n\
You can manage dynamic data structures by these commands:\n\
        [M/m] - change mode\n\
        [C/c] - change current pointer\n\
        [A/a] - add item\n"));
        printf(_("\
        [D]   - dispose all items\n\
        [d]   - dispose current item\n\
        [S]   - show all items\n\
        [s]   - show current item\n\
        [?]   - search item\n\
Also these commands can be useful too:\n\
        [H/h] - this help\n\
        [Q/q] - quit\n"));
}
