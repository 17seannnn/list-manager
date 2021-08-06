#include <stdio.h>

#include "version.h"

void version_opt()
{
        printf("\
%s (%s) %s\n\
Copyright (c) 2021 %s (%s)\n\
License MIT: <https://opensource.org/licenses/MIT>\n\
\n\
Written by %s (%s).\n\
Github: <%s>\n",
               PROGRAM_NAME, PROGRAM_NAME_LONG, VERSION,
               AUTHOR, AUTHOR_NICKNAME,
               AUTHOR, AUTHOR_NICKNAME, AUTHOR_PAGE);
}
