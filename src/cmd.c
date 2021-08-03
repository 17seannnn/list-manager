#include <stdio.h>

#include "mode.h"
#include "pointer.h"
#include "help.h"
#include "single.h"
#include "doubly.h"
#include "bintree.h"

#include "cmd.h"

int parse_cmd(enum command *cmd, int *val)
{
        int c;
        int negative = 0;
        *cmd = cmd_nothing;
        *val = 0;
        printf("(lm) %% ");
        while ((c = getchar()) != '\n' && c != EOF) {
                switch (c) {
                case 'H': case 'h': *cmd = cmd_help;     break;
                case 'Q': case 'q': *cmd = cmd_quit;     break;
                case 'M': case 'm': *cmd = cmd_chmod;    break;
                case 'C': case 'c': *cmd = cmd_chcur;    break;
                case 'A': case 'a': *cmd = cmd_add;      break;
                case 'D':           *cmd = cmd_dsp;      break;
                case 'd':           *cmd = cmd_dsp_cur;  break;
                case 'S':           *cmd = cmd_show;     break;
                case 's':           *cmd = cmd_show_cur; break;
                case '?':           *cmd = cmd_search;   break;
                }
        }
        if (c == EOF) {
                fprintf(stderr, "error: used EOF instead of RETURN\n");
                return 0;
        }
        switch (*cmd) {
        case cmd_chmod:
        case cmd_chcur:
        case cmd_add:
        case cmd_search:
                printf("%s ",
                       *cmd == cmd_chmod ? "mode [S/d/b]" : "val:");
                while ((c = getchar()) != '\n' && c != EOF) {
                        switch (c) {
                        case '-':
                                negative = 1;
                                break;
                        case '0': case '1': case '2': case '3': case '4':
                        case '5': case '6': case '7': case '8': case '9':
                                *val = *val * 10 + c - '0';
                                break;
                        case 'S': case 's':
                        case 'D': case 'd':
                        case 'B': case 'b':
                        case 'P': case 'p':
                        case 'N': case 'n':
                                *val = c;
                                break;
                        }
                }
                if (negative)
                        *val *= -1;
                break;
        default:
                break;
        }
        if (c == EOF) {
                fprintf(stderr, "error: used EOF instead of RETURN\n");
                return 0;
        }
        return 1;
}

int handle_cmd(enum command cmd, int val, struct pointer *p, enum mode *m)
{
        switch (cmd) {
        case cmd_nothing:
                help_short();
                break;
        case cmd_help:
                help_full();
                break;
        case cmd_quit:
                return 0;
        case cmd_chmod:
                change_mode(m, val);
                break;
        case cmd_chcur:
                switch (*m) {
                case mode_single:
                        chcur_single(p->s_first, &p->s_cur, val);
                        break;
                case mode_doubly:
                        chcur_doubly(&p->d_cur, val);
                        break;
                default:
                        break;
                }
                break;
        case cmd_add:
                switch (*m) {
                case mode_single:
                        add_single(&p->s_first, &p->s_cur, val);
                        break;
                case mode_doubly:
                        add_doubly(&p->d_first, &p->d_last, &p->d_cur, val);
                        break;
                case mode_bintree:
                        add_node(&p->root, val);
                        break;
                }
                break;
        case cmd_dsp:
                switch (*m) {
                case mode_single:
                        dsp_single(p->s_first);
                        p->s_first = NULL;
                        break;
                case mode_doubly:
                        dsp_doubly(p->d_first);
                        p->d_first = p->d_last = NULL;
                        break;
                case mode_bintree:
                        dsp_node(p->root);
                        p->root = NULL;
                        break;
                }
                break;
        case cmd_dsp_cur:
                switch (*m) {
                case mode_single:
                        dsp_cur_single(&p->s_first, &p->s_cur);
                        break;
                case mode_doubly:
                        dsp_cur_doubly(&p->d_first, &p->d_last, &p->d_cur);
                        break;
                default:
                        break;
                }
                break;
        case cmd_show:
                switch (*m) {
                case mode_single:
                        show_single(p->s_first, p->s_cur);
                        break;
                case mode_doubly:
                        show_doubly(p->d_first, p->d_cur);
                        break;
                case mode_bintree:
                        show_node(p->root);
                        break;
                }
                break;
        case cmd_show_cur:
                switch (*m) {
                case mode_single:
                        show_cur_single(p->s_cur);
                        break;
                case mode_doubly:
                        show_cur_doubly(p->d_cur);
                        break;
                case mode_bintree:
                        break;
                }
                break;
        case cmd_search:
                switch (*m) {
                case mode_single:
                        search_single(p->s_first, &p->s_cur, val);
                        break;
                case mode_doubly:
                        search_doubly(p->d_first, &p->d_cur, val);
                        break;
                case mode_bintree:
                        search_node(p->root, val);
                        break;
                }
                break;
        }
        return 1;
}
