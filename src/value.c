#include <stdio.h>

#include "value.h"

int parse_val(enum command cmd, enum mode m)
{
        int val = 0, sign = 0, c;
        switch (cmd) {
        case cmd_chcur:
                switch (m) {
                case mode_single:
                case mode_doubly:
                        printf("val [p/n]: ");
                        break;
                case mode_bintree:
                        printf("val [p/l/r]: ");
                        break;
                }
                break;
        case cmd_add:
        case cmd_search:
                printf("val: ");
                break;
        default:
                break;
        }
        fflush(stdout);
        switch (cmd) {
        case cmd_chcur:
        case cmd_add:
        case cmd_search:
                while ((c = getchar()) != '\n' && c != EOF) {
                        switch (c) {
                        case '-':
                                sign = 1;
                                break;
                        case '0': case '1': case '2': case '3': case '4':
                        case '5': case '6': case '7': case '8': case '9':
                                val = val * 10 + c - '0';
                                break;
                        case 'P': case 'p':
                        case 'N': case 'n':
                        case 'L': case 'l':
                        case 'R': case 'r':
                                val = c;
                                break;
                        }
                }
                break;
        default:
                break;
        }
        return sign ? val * -1 : val;
}
