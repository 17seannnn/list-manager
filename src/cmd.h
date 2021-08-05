#ifndef CMD_H
#define CMD_H

#include "pointer.h"
#include "mode.h"

enum command {
        cmd_nothing = 0,
        cmd_help,
        cmd_quit,
        cmd_chmod,
        cmd_chcur,
        cmd_add,
        cmd_dsp,
        cmd_dsp_cur,
        cmd_show,
        cmd_show_cur,
        cmd_search
};

enum command parse_cmd();
int  handle_cmd(enum command cmd, int val, struct pointer *p, enum mode *m);

#endif
