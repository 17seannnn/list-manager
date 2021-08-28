/* doubly.c */

#include <stdio.h>
#include <stdlib.h>
#include "listmf.h"

#include "doubly.h"

void chcur_doubly(struct doubly_item **pcur, int n)
{
        if (!*pcur)
                return;
        switch (n) {
        case 'P': case 'p':
                if ((*pcur)->prev)
                        *pcur = (*pcur)->prev;
                break;
        case 'N': case 'n':
                if ((*pcur)->next)
                        *pcur = (*pcur)->next;
                break;
        default:
                break;
        }
}

void add_doubly(struct doubly_item **pfirst,
                struct doubly_item **plast,
                struct doubly_item **pcur,
                int n)
{
        struct doubly_item *tmp;
        tmp = malloc(sizeof(*tmp));
        tmp->data = n;
        tmp->prev = *plast;
        tmp->next = NULL;
        if (*plast)
                (*plast)->next = tmp;
        else
                *pfirst = tmp;
        *plast = tmp;
        *pcur = tmp;
}

MAKE_DISPOSE_LIST_FUNCTION(doubly)

void dsp_cur_doubly(struct doubly_item **pfirst,
                    struct doubly_item **plast,
                    struct doubly_item **pcur)
{
        struct doubly_item *tmp = *pcur;
        if (!*pcur)
                return;
        if ((*pcur)->next)
                chcur_doubly(pcur, 'n');
        else if ((*pcur)->prev)
                chcur_doubly(pcur, 'p');
        else
                *pcur = NULL;
        if (tmp->prev)
                tmp->prev->next = tmp->next;
        else
                *pfirst = tmp->next;
        if (tmp->next)
                tmp->next->prev = tmp->prev;
        else
                *plast = tmp->prev;
        free(tmp);
}

MAKE_SHOW_LIST_FUNCTION(doubly)

MAKE_SHOW_CURRENT_LIST_FUNCTION(doubly)

MAKE_SEARCH_LIST_FUNCTION(doubly)
