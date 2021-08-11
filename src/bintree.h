#ifndef BINTREE_H
#define BINTREE_H

struct node {
        int val;
        char exist;
        struct node *left, *right;
};

void chcur_node(struct node *r, struct node **pcur, int n);
void add_node(struct node **r, struct node **pcur, int n);
void dsp_node(struct node *r);
void dsp_cur_node(struct node **pcur);
void show_node(struct node *r, struct node *cur);
void show_cur_node(struct node *cur);
void search_node(struct node *r, struct node **pcur, int n);

#endif
