#include <stdio.h>

#include "mode.h"

enum mode parse_mode()
{
        enum mode m = mode_single;
        int c;
        printf("mode [S/d/b]: ");
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
                fprintf(stderr, "error: used EOF instead of RETURN\n");
                return -1;
        }
        return m;
}
