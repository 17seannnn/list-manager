#ifndef DOUBLY_H
#define DOUBLY_H

struct doubly_item {
        int data;
        struct doubly_item *prev, *next;
};

void chcur_doubly(struct doubly_item **pcur, int n);
void add_doubly(struct doubly_item **pfirst,
                struct doubly_item **plast,
                struct doubly_item **pcur,
                int n);
void dsp_doubly(struct doubly_item *first);
void dsp_cur_doubly(struct doubly_item **pfirst,
                    struct doubly_item **plast,
                    struct doubly_item **pcur);
void show_doubly(struct doubly_item *first, struct doubly_item *cur);
void search_doubly(struct doubly_item *first, struct doubly_item **pcur, int n);

#endif
