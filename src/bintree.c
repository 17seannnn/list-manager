#include <stdio.h>
#include <stdlib.h>

#include "bintree.h"

void add_node(struct node **r, struct node **pcur, int n)
{
        if (!*r) {
                *r = malloc(sizeof(*r));
                (*r)->val   = n;
                (*r)->left  = NULL;
                (*r)->right = NULL;
                *pcur = *r;
                return;
        }
        if ((*r)->val == n)
                return;
        if (n < (*r)->val)
                add_node(&(*r)->left, pcur, n);
        else
                add_node(&(*r)->right, pcur, n);
}

void dsp_node(struct node *r)
{
        if (!r)
                return;
        dsp_node(r->left);
        dsp_node(r->right);
        free(r);
}

void show_node(struct node *r, struct node *cur)
{
        if (!r)
                return;
        show_node(r->left, cur);
        printf("%d %c\n", r->val, r == cur ? '*' : 0);
        show_node(r->right, cur);
}

void show_cur_node(struct node *b_cur)
{
        if (!b_cur)
                return;
        printf("%d\n", b_cur->val);
}

void search_node(struct node *r, struct node **pcur, int n)
{
        if (!r) {
                printf("Not found.\n");
                return;
        }
        if (r->val == n) {
                printf("Found.\n");
                *pcur = r;
                return;
        }
        if (n < r->val)
                search_node(r->left, pcur, n);
        else
                search_node(r->right, pcur, n);
}
