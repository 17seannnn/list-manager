#include <stdio.h>
#include <stdlib.h>
#include "gtmd.h"

#include "bintree.h"

void chcur_node(struct node *r, struct node **pcur, int n)
{
        if (!r || !*pcur)
                return;
        switch (n) {
        case 'P':
        case 'p':
                if (r == *pcur)
                        return;
                while (r && (r->left != *pcur && r->right != *pcur))
                        if ((*pcur)->val < r->val)
                                r = r->left;
                        else
                                r = r->right;
                if (r)
                        *pcur = r;
                break;
        case 'L':
        case 'l':
                if ((*pcur)->left)
                        *pcur = (*pcur)->left;
                break;
        case 'R':
        case 'r':
                if ((*pcur)->right)
                        *pcur = (*pcur)->right;
                break;
        default:
                break;
        }
}

void add_node(struct node **r, struct node **pcur, int n)
{
        if (!*r) {
                *r = malloc(sizeof(**r));
                (*r)->val = n;
                (*r)->exist = 1;
                (*r)->left = NULL;
                (*r)->right = NULL;
                *pcur = *r;
                return;
        }
        if ((*r)->val == n) {
                if ((*r)->exist) {
                        *pcur = *r;
                        return;
                } else {
                        (*r)->exist = 1;
                        *pcur = *r;
                        return;
                }
        }
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

void dsp_cur_node(struct node **pcur)
{
        if (!*pcur)
                return;
        (*pcur)->exist = 0;
        if ((*pcur)->right)
                *pcur = (*pcur)->right;
        else
                *pcur = (*pcur)->left;
}

void show_node(struct node *r, struct node *cur)
{
        if (!r)
                return;
        show_node(r->left, cur);
        if (r->exist)
                printf(_("%d %c\n"), r->val, r == cur ? '*' : 0);
        show_node(r->right, cur);
}

void show_cur_node(struct node *b_cur)
{
        if (!b_cur || !b_cur->exist)
                return;
        printf(_("%d *\n"), b_cur->val);
}

void search_node(struct node *r, struct node **pcur, int n)
{
        if (!r) {
                printf(_("Not found.\n"));
                return;
        }
        if (r->val == n && r->exist) {
                printf(_("Found.\n"));
                *pcur = r;
                return;
        }
        if (n < r->val)
                search_node(r->left, pcur, n);
        else
                search_node(r->right, pcur, n);
}
