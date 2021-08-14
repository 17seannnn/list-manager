#include <stdio.h>
#include "gtmd.h"
#include "help.h"
#include "single.h"
#include "doubly.h"
#include "bintree.h"

#include "cmd.h"

enum command parse_cmd()
{
        enum command cmd = cmd_nothing;
        int c;
        printf(N_("(lm) %% "));
        fflush(stdout);
        while ((c = getchar()) != '\n' && c != EOF) {
                switch (c) {
                case 'H': case 'h': cmd = cmd_help;     break;
                case 'Q': case 'q': cmd = cmd_quit;     break;
                case 'M': case 'm': cmd = cmd_chmod;    break;
                case 'C': case 'c': cmd = cmd_chcur;    break;
                case 'A': case 'a': cmd = cmd_add;      break;
                case 'D':           cmd = cmd_dsp;      break;
                case 'd':           cmd = cmd_dsp_cur;  break;
                case 'S':           cmd = cmd_show;     break;
                case 's':           cmd = cmd_show_cur; break;
                case '?':           cmd = cmd_search;   break;
                default:                                break;
                }
        }
        if (c == EOF) {
                fprintf(stderr,
                        _("error: return expected but end of file found\n"));
                return -1;
        }
        return cmd;
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
                *m = parse_mode();
                if (*m == -1)
                        return -1;
                break;
        case cmd_chcur:
                switch (*m) {
                case mode_single:
                        chcur_single(p->s_first, &p->s_cur, val);
                        break;
                case mode_doubly:
                        chcur_doubly(&p->d_cur, val);
                        break;
                case mode_bintree:
                        chcur_node(p->root, &p->b_cur, val);
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
                        add_node(&p->root, &p->b_cur, val);
                        break;
                default:
                        break;
                }
                break;
        case cmd_dsp:
                switch (*m) {
                case mode_single:
                        dsp_single(p->s_first);
                        p->s_first = NULL;
                        p->s_cur = NULL;
                        break;
                case mode_doubly:
                        dsp_doubly(p->d_first);
                        p->d_first = NULL;
                        p->d_last = NULL;
                        p->d_cur = NULL;
                        break;
                case mode_bintree:
                        dsp_node(p->root);
                        p->root = NULL;
                        p->b_cur = NULL;
                        break;
                default:
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
                case mode_bintree:
                        dsp_cur_node(&p->b_cur);
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
                        show_node(p->root, p->b_cur);
                        break;
                default:
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
                        show_cur_node(p->b_cur);
                        break;
                default:
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
                        search_node(p->root, &p->b_cur, val);
                        break;
                default:
                        break;
                }
                break;
        default:
                break;
        }
        return 1;
}
