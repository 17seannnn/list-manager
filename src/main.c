/* main.c */

#include <stdio.h>
#include <locale.h>
#include <libintl.h>
#include "error.h"
#include "config.h"
#include "gtmd.h"
#include "option.h"
#include "pointer.h"
#include "mode.h"
#include "cmd.h"
#include "value.h"
#include "dsp_all.h"

int main(int argc, char **argv)
{
        int exit_status = 0;
        struct pointer p = { NULL, NULL, NULL, NULL, NULL, NULL, NULL };
        enum mode m;
        enum command cmd;
        int val;
        int res;
        setlocale(LC_CTYPE, "");
        setlocale(LC_MESSAGES, "");
        bindtextdomain(PACKAGE, LOCALEDIR);
        textdomain(PACKAGE);
        res = handle_opt(argv);
        if (!res)
                goto quit;
        m = parse_mode();
        if (m == -1) {
                exit_status = ERR_EOF;
                goto quit;
        }
        for (;;) {
                cmd = parse_cmd();
                if (cmd == -1) {
                        exit_status = ERR_EOF;
                        goto quit;
                }
                val = parse_val(cmd, m);
                res = handle_cmd(cmd, val, &p, &m);
                if (!res) {
                        goto quit;
                } else if (res == -1) {
                        exit_status = ERR_EOF;
                        goto quit;
                }
        }
quit:
        dsp_all(p);
        return exit_status;
}
