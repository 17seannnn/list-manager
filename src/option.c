#include <stdio.h>

#include "lm_string.h"

#include "option.h"

void help_opt()
{
        printf("\
Usage: %s [OPTION]\n\
\n\
Options:\n\
        -h, --help      this help\n\
        -v, --version   show version\n\
\n\
If you find bugs: %s\n\
%s home page <%s>\n",
               PROGRAM_NAME, PROGRAM_EMAIL, PROGRAM_NAME, PROGRAM_PAGE);
}

void version_opt()
{
        printf("\
%s (%s) %s\n\
Copyright (c) 2021 %s (%s)\n\
License MIT: <https://opensource.org/licenses/MIT>\n\
\n\
Written by %s (%s).\n\
Github: <%s>\n",
               PROGRAM_NAME, PROGRAM_NAME_FULL, VERSION,
               AUTHOR, AUTHOR_NICKNAME,
               AUTHOR, AUTHOR_NICKNAME, AUTHOR_PAGE);
}

int handle_opt(char **argv)
{
        argv++;
        for (; *argv; argv++)
                if (str_equal(*argv, OPTION_HELP_SHORT) ||
                    str_equal(*argv, OPTION_HELP_FULL)) {
                        help_opt();
                        return 0;
                } else if (str_equal(*argv, OPTION_VERSION_FULL) ||
                           str_equal(*argv, OPTION_VERSION_SHORT)) {
                        version_opt();
                        return 0;
                }
        return 1;
}
