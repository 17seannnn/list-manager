#include <stdio.h>
#include "gtmd.h"

#include "mode.h"

enum mode parse_mode()
{
        enum mode m = mode_single;
        int c;
        printf(_("mode [S/d/b]: "));
        fflush(stdout);
        while ((c = getchar()) != '\n' && c != EOF) {
                switch (c) {
                case 'S': case 's': m = mode_single;  break;
                case 'D': case 'd': m = mode_doubly;  break;
                case 'B': case 'b': m = mode_bintree; break;
                default:                              break;
                }
        }
        if (c == EOF) {
                fprintf(stderr,
                        _("error: return expected but end of file found\n"));
                return -1;
        }
        return m;
}
