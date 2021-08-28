/* error.c */

#include <stdio.h>

#include "error.h"

void printerr(int err)
{
        switch (err) {
        case ERR_EOF:
                fprintf(stderr, ERR_EOF_TEXT);
                break;
        default:
                break;
        }
}
