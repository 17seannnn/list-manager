/*
 *                                   TODO
 * Now:
 *
 * Divide code on parts *
 * Add info to Install in README
 *
 * Later:
 * Add show cur cmd, change search on '?'
 * Delete change_mode func and use parse_mode for when cmd_chmod
 * Use my functions for operations with strings
 *
 * Add in current prev or next pointer for single&doubly-linked lists
 * Add_cur, search current also change current pointer
 *
 * Remove value parsing from parse_cmd, add parse_value
 * Delete node: user enter the value and we delete node with this value
 * Improve README
 *
 * Much later:
 * Change chcur func:
 *      1) If cur is NULL then in case n is 'N'/'n' we set cur ptr on first ptr,
 *              in case n is 'P'/'p' we set cur ptr on last ptr.
 *      2) If next/prev ptr is NULL, then set cur on NULL.
 *      3) int -> void chcur_single(), remove res = chcur_single()
 */

#include <stdio.h>
#include <stdlib.h>

#include "option.h"
#include "pointer.h"
#include "mode.h"
#include "cmd.h"
#include "dsp_all.h"
#include "error.h"

int main(int argc, char **argv)
{
        struct pointer p = { NULL, NULL, NULL, NULL, NULL, NULL };
        enum mode m;
        enum command cmd;
        int val;
        int res;
        if (!handle_option(argv))
                return 0;
        m = parse_mode();
        if (!m)
                return ERR_EOF;
        for (;;) {
                res = parse_cmd(&cmd, &val);
                if (!res)
                        return ERR_EOF;
                res = handle_cmd(cmd, val, &p, &m);
                if (!res)
                        break;
        }
        dsp_all(p);
        return 0;
}
