/*
 * --------------------------------------------------------------------
 * Refactoring:
 * Change code style: simplify funcs` name *, change args name like cur -> pcur
 * Remove code repetitions by using macroses for list functions
 *
 *
 *
 *
 * --------------------------------------------------------------------
 * Later:
 * Change chcur func:
 *      1) If cur is NULL then in case n is 'N'/'n' we set cur ptr on first ptr,
 *              in case n is 'P'/'p' we set cur ptr on last ptr.
 *      2) If next/prev ptr is NULL, then set cur on NULL.
 *      3) Change prev and next by *cur, next change *cur and next free(tmp)
 *
 *
 *
 * Add version cmd
 * Add options
 * Add show cur cmd, change search on '?'
 * Add in current prev or next pointer for single&doubly-linked lists
 * Add_cur, search current also change current pointer
 * Delete change_mode func and use parse_mode for when cmd_chmod
 * Remove value parsing from parse_cmd, add parse_value get
 * Improve README
 * Delete node: user enter the value and we delete node with this value
 */

#include <stdio.h>
#include <stdlib.h>

#define ERR_EOF 1

enum mode {
        mode_single = 1,
        mode_doubly,
        mode_bintree
};

enum command {
        cmd_nothing,
        cmd_help,
        cmd_quit,
        cmd_chmod,
        cmd_chcur,
        cmd_add,
        cmd_dsp,
        cmd_dsp_cur,
        cmd_show,
        cmd_search
};

struct single_item {
        int data;
        struct single_item *next;
};

struct doubly_item {
        int data;
        struct doubly_item *prev, *next;
};

struct node {
        int val;
        struct node *left, *right; 
};

struct pointer {
        struct single_item *s_first, *s_cur;
        struct doubly_item *d_first, *d_last, *d_cur;
        struct node *root;
};

void help_short()
{
        printf("Invalid command, try 'h' for help\n");
}

void help_full()
{
        printf("\
Here 3 modes:\n\
        [S/s]ingle-linked list\n\
        [D/d]oubly-linked list\n\
        [B/b]inary tree\n\
You can manage dynamic data structures by these commands:\n\
        [M/m] - change mode\n\
        [C/c] - change current pointer\n\
        [A/a] - add item\n\
        [D]   - dispose all\n\
        [d]   - dispose current\n\
        [S]   - show all\n\
        [s]   - search item\n\
Also these commands can be useful too:\n\
        [H/h] - this help\n\
        [Q/q] - quit\n");
}

int chcur_single(struct single_item *first, struct single_item **cur, int n)
{
        if (!*cur)
                return 0;
        switch (n) {
        case 'P': case 'p':
                if (first == *cur)
                        return 0;
                while(first->next != *cur)
                        first = first->next;
                *cur = first;
                break;
        case 'N': case 'n':
                if ((*cur)->next)
                        *cur = (*cur)->next;
                else
                        return 0;
        }
        return 1;
}

void chcur_doubly(struct doubly_item **cur, int n)
{
        if (!*cur)
                return;
        switch (n) {
        case 'P': case 'p':
                if ((*cur)->prev)
                        *cur = (*cur)->prev;
                break;
        case 'N': case 'n':
                if ((*cur)->next)
                        *cur = (*cur)->next;
                break;
        }
}

void add_single(struct single_item **first, struct single_item **cur, int n)
{
        struct single_item *tmp;
        tmp = malloc(sizeof(*tmp));
        tmp->data = n;
        tmp->next = *first;
        *first = tmp;
        *cur = tmp;
}

void add_doubly(struct doubly_item **first,
                struct doubly_item **last,
                struct doubly_item **cur,
                int n)
{
        struct doubly_item *tmp;
        tmp = malloc(sizeof(*tmp));
        tmp->data = n;
        tmp->prev = *last;
        tmp->next = NULL;
        if (*last)
                (*last)->next = tmp;
        else
                *first = tmp;
        *last = tmp;
        *cur = tmp;
}

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

void dispose_single(struct single_item *first)
{
        struct single_item *tmp;
        while (first) {
                tmp = first;
                first = first->next;
                free(tmp);
        }
}

void dispose_doubly(struct doubly_item *first)
{
        struct doubly_item *tmp;
        while (first) {
                tmp = first;
                first = first->next;
                free(tmp);
        }
}

void dispose_node(struct node *r)
{
        if (!r)
                return;
        dispose_node(r->left);
        dispose_node(r->right);
        free(r);
}

void dispose_single_cur(struct single_item **first, struct single_item **cur)
{
        struct single_item *tmp = *cur;
        int res;
        if (!*cur)
                return;
        if ((*cur)->next) {
                chcur_single(*first, cur, 'n');
        } else {
                res = chcur_single(*first, cur, 'p');
                if (!res)
                        *cur = NULL;
        }
        while (*first != tmp)
                first = &(*first)->next;
        *first = (*first)->next;
        free(tmp);
}

void dispose_doubly_cur(struct doubly_item **first,
                        struct doubly_item **last,
                        struct doubly_item **cur)
{
        struct doubly_item *tmp = *cur;
        if (!*cur)
                return;
        if ((*cur)->next)
                chcur_doubly(cur, 'n');
        else if ((*cur)->prev)
                chcur_doubly(cur, 'p');
        else
                *cur = NULL;
        if (tmp->prev)
                tmp->prev->next = tmp->next;
        else
                *first = tmp->next;
        if (tmp->next)
                tmp->next->prev = tmp->prev;
        else
                *last = tmp->prev;
        free(tmp);
}

void dispose_all(struct pointer p)
{
        dispose_single(p.s_first);
        dispose_doubly(p.d_first);
        dispose_node(p.root);
}

void show_single(struct single_item *first, struct single_item *cur)
{
        for (; first; first = first->next)
                printf("%d %c\n", first->data, first == cur ? '*' : 0);
}

void show_doubly(struct doubly_item *first, struct doubly_item *cur)
{
        for (; first; first = first->next)
                printf("%d %c\n", first->data, first == cur ? '*' : 0);
}

void show_node(struct node *r)
{
        if (!r)
                return;
        show_node(r->left);
        printf("%d\n", r->val);
        show_node(r->right);
}

void search_single(struct single_item *first, struct single_item **cur, int n)
{
        for (; first; first = first->next) {
                if (n == first->data) {
                        printf("Found.\n");
                        *cur = first;
                        return;
                }
        }
        printf("Not found.\n");
}

void search_doubly(struct doubly_item *first, struct doubly_item **cur, int n)
{
        for (; first; first = first->next) {
                if (n == first->data) {
                        printf("Found.\n");
                        *cur = first;
                        return;
                }
        }
        printf("Not found.\n");
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

void change_mode(enum mode *m, int val)
{
        switch (val) {
        case 'S': case 's': *m = mode_single;  break;
        case 'D': case 'd': *m = mode_doubly;  break;
        case 'B': case 'b': *m = mode_bintree; break;
        }
}

enum mode parse_mode()
{
        enum mode m = mode_single;
        int c;
        printf("Enter mode [S/d/b]: ");
        while ((c = getchar()) != '\n' && c != EOF) {
                switch (c) {
                case 'S': case 's': m = mode_single;  break;
                case 'D': case 'd': m = mode_doubly;  break;
                case 'B': case 'b': m = mode_bintree; break;
                }
        }
        if (c == EOF) {
                fprintf(stderr, "error: used EOF instead of RETURN\n");
                return 0;
        }
        return m;
}

int parse_cmd(enum command *cmd, int *val)
{
        int c;
        int negative = 0;
        *cmd = cmd_nothing;
        *val = 0;
        printf("%% ");
        while ((c = getchar()) != '\n' && c != EOF) {
                switch (c) {
                case 'H': case 'h': *cmd = cmd_help;    break;
                case 'Q': case 'q': *cmd = cmd_quit;    break;
                case 'M': case 'm': *cmd = cmd_chmod;   break;
                case 'C': case 'c': *cmd = cmd_chcur;   break;
                case 'A': case 'a': *cmd = cmd_add;     break;
                case 'D':           *cmd = cmd_dsp;     break;
                case 'd':           *cmd = cmd_dsp_cur; break;
                case 'S':           *cmd = cmd_show;    break;
                case 's':           *cmd = cmd_search;  break;
                }
        }
        if (c == EOF) {
                fprintf(stderr, "error: used EOF instead of RETURN\n");
                return 0;
        }
        switch (*cmd) {
        case cmd_chmod:
        case cmd_chcur:
        case cmd_add:
        case cmd_search:
                printf("%s ",
                       *cmd == cmd_chmod ? "mode [S/d/b]" : "val:");
                while ((c = getchar()) != '\n' && c != EOF) {
                        switch (c) {
                        case '-':
                                negative = 1;
                                break;
                        case '0': case '1': case '2': case '3': case '4':
                        case '5': case '6': case '7': case '8': case '9':
                                *val = *val * 10 + c - '0';
                                break;
                        case 'S': case 's':
                        case 'D': case 'd':
                        case 'B': case 'b':
                        case 'P': case 'p':
                        case 'N': case 'n':
                                *val = c;
                                break;
                        }
                }
                if (negative)
                        *val *= -1;
                break;
        default:
                break;
        }
        if (c == EOF) {
                fprintf(stderr, "error: used EOF instead of RETURN\n");
                return 0;
        }
        return 1;
}

int handle_cmd(enum command cmd, int val, struct pointer *p, enum mode *m)
{
        switch (cmd) {
        case cmd_nothing:
                help_short();
                break;
        case cmd_help:
                help_full();
                break;
        case cmd_quit:
                return 0;
        case cmd_chmod:
                change_mode(m, val);
                break;
        case cmd_chcur:
                switch (*m) {
                case mode_single:
                        chcur_single(p->s_first, &p->s_cur, val);
                        break;
                case mode_doubly:
                        chcur_doubly(&p->d_cur, val);
                        break;
                default:
                        break;
                }
                break;
        case cmd_add:
                switch (*m) {
                case mode_single:
                        add_single(&p->s_first, &p->s_cur, val);
                        break;
                case mode_doubly:
                        add_doubly(&p->d_first, &p->d_last, &p->d_cur, val);
                        break;
                case mode_bintree:
                        add_node(&p->root, val);
                        break;
                }
                break;
        case cmd_dsp:
                switch (*m) {
                case mode_single:
                        dispose_single(p->s_first);
                        p->s_first = NULL;
                        break;
                case mode_doubly:
                        dispose_doubly(p->d_first);
                        p->d_first = p->d_last = NULL;
                        break;
                case mode_bintree:
                        dispose_node(p->root);
                        p->root = NULL;
                        break;
                }
                break;
        case cmd_dsp_cur:
                switch (*m) {
                case mode_single:
                        dispose_single_cur(&p->s_first, &p->s_cur);
                        break;
                case mode_doubly:
                        dispose_doubly_cur(&p->d_first, &p->d_last, &p->d_cur);
                        break;
                default:
                        break;
                }
                break;
        case cmd_show:
                switch (*m) {
                case mode_single:
                        show_single(p->s_first, p->s_cur);
                        break;
                case mode_doubly:
                        show_doubly(p->d_first, p->d_cur);
                        break;
                case mode_bintree:
                        show_node(p->root);
                        break;
                }
                break;
        case cmd_search:
                switch (*m) {
                case mode_single:
                        search_single(p->s_first, &p->s_cur, val);
                        break;
                case mode_doubly:
                        search_doubly(p->d_first, &p->d_cur, val);
                        break;
                case mode_bintree:
                        search_node(p->root, val);
                        break;
                }
                break;
        }
        return 1;
}

int main()
{
        struct pointer p = { NULL, NULL, NULL, NULL, NULL, NULL };
        enum mode m;
        enum command cmd;
        int val;
        int res;
        m = parse_mode();
        if (!m)
                return ERR_EOF;
        for (;;) {
                res = parse_cmd(&cmd, &val);
                if (!res)
                        return ERR_EOF;
                res = handle_cmd(cmd, val, &p, &m);
                if (!res)
                        break;
        }
        dispose_all(p);
        return 0;
}
