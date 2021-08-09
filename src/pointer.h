#ifndef POINTER_H
#define POINTER_H

struct pointer {
        struct single_item *s_first, *s_cur;
        struct doubly_item *d_first, *d_last, *d_cur;
        struct node *root, *b_cur;
};

#endif
