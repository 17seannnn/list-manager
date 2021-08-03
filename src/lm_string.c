#include "lm_string.h"

#ifndef EOF
#define EOF -1
#endif

int str_equal(const char *s1, const char *s2)
{
        for (; *s1 || *s2; s1++, s2++)
                if (*s1 != *s2)
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
        int i = 0, sign = 0;
        if (*s == '-') {
                sign = 1;
                s++;
        }
        for (; *s && *s != EOF && *s != '\n' && *s != ' '; s++)
                i = i * 10 + *s - '0';
        return sign ? i * -1 : i;
}
