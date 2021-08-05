#ifndef CMD_H
#define CMD_H

enum command {
        cmd_nothing,
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

int parse_cmd(enum command *cmd);
int handle_cmd(enum command cmd, int val, struct pointer *p, enum mode *m);

#endif
