#ifndef MODE_H
#define MODE_H

enum mode {
        mode_single = 1,
        mode_doubly,
        mode_bintree
};

void change_mode(enum mode *m, int val);
enum mode parse_mode();

#endif
