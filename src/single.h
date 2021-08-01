#ifndef SINGLE_H
#define SINGLE_H

struct single_item {
        int data;
        struct single_item *next;
};

int  chcur_single(struct single_item *first, struct single_item **pcur, int n);
void add_single(struct single_item **pfirst, struct single_item **pcur, int n);
void dsp_single(struct single_item *first);
void dsp_cur_single(struct single_item **pfirst, struct single_item **pcur);
void show_single(struct single_item *first, struct single_item *cur);
void search_single(struct single_item *first, struct single_item **pcur, int n);

#endif
