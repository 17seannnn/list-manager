#include <stdio.h>
#include <stdlib.h>

#include "bintree.h"

void add_node(struct node **r, int n)
{
        if (!*r) {
                *r = malloc(sizeof(*r));
                (*r)->val   = n;
                (*r)->left  = NULL;
                (*r)->right = NULL;
                return;
        }
        if ((*r)->val == n)
                return;
        if (n < (*r)->val)
                add_node(&(*r)->left, n);
        else
                add_node(&(*r)->right, n);
}

void dsp_node(struct node *r)
{
        if (!r)
                return;
        dsp_node(r->left);
        dsp_node(r->right);
        free(r);
}

void show_node(struct node *r)
{
        if (!r)
                return;
        show_node(r->left);
        printf("%d\n", r->val);
        show_node(r->right);
}

void search_node(struct node *r, int n)
{
        if (!r) {
                printf("Not found.\n");
                return;
        }
        if (r->val == n) {
                printf("Found.\n");
                return;
        }
        if (n < r->val)
                search_node(r->left, n);
        else
                search_node(r->right, n);
}
