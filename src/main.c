#include "option.h"
#include "pointer.h"
#include "mode.h"
#include "cmd.h"
#include "value.h"
#include "dsp_all.h"
#include "error.h"

int main(int argc, char **argv)
{
        struct pointer p = { NULL, NULL, NULL, NULL, NULL, NULL };
        enum mode m;
        enum command cmd;
        int val;
        int res;
        if (!handle_opt(argv))
                return 0;
        m = parse_mode();
        if (!m)
                return ERR_EOF;
        for (;;) {
                cmd = parse_cmd();
                if (cmd == -1)
                        return ERR_EOF;
                val = parse_val(cmd);
                res = handle_cmd(cmd, val, &p, &m);
                if (!res)
                        break;
        }
        dsp_all(p);
        return 0;
}
