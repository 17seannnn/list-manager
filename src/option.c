/* option.c */

#include <stdio.h>
#include "lmstring.h"
#include "help.h"
#include "version.h"

#include "option.h"

int handle_opt(char **argv)
{
        argv++;
        for (; *argv; argv++) {
                if (str_eql(*argv, OPTION_HELP_SHORT) ||
                    str_eql(*argv, OPTION_HELP_LONG)) {
                        help_opt();
                        return 0;
                } else if (str_eql(*argv, OPTION_VERSION_LONG) ||
                           str_eql(*argv, OPTION_VERSION_SHORT)) {
                        version_opt();
                        return 0;
                }
        }
        return 1;
}
