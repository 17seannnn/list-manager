/* error.h */

#ifndef ERROR_H
#define ERROR_H

#include "gtmd.h"

#define ERR_EOF 1

#define ERR_EOF_TEXT _("error: return expected but end of file found\n")

void printerr(int err);

#endif
