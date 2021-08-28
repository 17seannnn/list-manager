/* mode.h */

#ifndef MODE_H
#define MODE_H

enum mode {
        mode_single = 0,
        mode_doubly,
        mode_bintree
};

enum mode parse_mode();

#endif
