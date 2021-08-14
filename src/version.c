#include <stdio.h>
#include "gtmd.h"

#include "version.h"

void version_opt()
{
        printf(_("\
%s (%s) %s\n\
Copyright (c) %s %s (%s)\n\
License %s: <%s>\n\
\n\
Written by %s (%s).\n\
Github: <%s>\n"),
               PROGRAM_NAME, PROGRAM_NAME_LONG, VERSION,
               COPYRIGHT_YEAR, AUTHOR, AUTHOR_NICKNAME,
               LICENSE, LICENSE_PAGE,
               AUTHOR, AUTHOR_NICKNAME, AUTHOR_PAGE);
}
