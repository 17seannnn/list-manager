#include <stdio.h>

#include "lmstring.h"

int str_eql(const char *c1, const char *c2)
{
        for (; *c1 || *c2; c1++, c2++)
                if (*c1 != *c2)
                        return 0;
        return 1;
}

int str_len(const char *s)
{
        const char *t;
        for (t = s; *t; t++)
                {}
        return t - s;
}

int a_to_i(const char *s)
{
        int i = 0;
        if (*s == '-')
                return -a_to_i(s+1);
        for (; *s && *s != ' ' && *s != '\n'; s++)
                i = i * 10 + *s - '0';
        return i;
}
