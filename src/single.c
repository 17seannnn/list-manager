#include <stdio.h>
#include <stdlib.h>
#include "macrofunc_list.h"

#include "single.h"

void chcur_single(struct single_item *first, struct single_item **pcur, int n)
{
        if (!first || !*pcur)
                return;
        switch (n) {
        case 'P': case 'p':
                if (first == *pcur)
                        return;
                while(first && first->next != *pcur)
                        first = first->next;
                if (first)
                        *pcur = first;
                break;
        case 'N': case 'n':
                if ((*pcur)->next)
                        *pcur = (*pcur)->next;
        }
}

void add_single(struct single_item **pfirst, struct single_item **pcur, int n)
{
        struct single_item *tmp;
        tmp = malloc(sizeof(*tmp));
        tmp->data = n;
        tmp->next = *pfirst;
        *pfirst = tmp;
        *pcur = tmp;
}

MAKE_DISPOSE_LIST_FUNCTION(single)

void dsp_cur_single(struct single_item **pfirst, struct single_item **pcur)
{
        struct single_item *tmp = *pcur;
        if (!*pfirst || !*pcur)
                return;
        if ((*pcur)->next) {
                chcur_single(*pfirst, pcur, 'n');
        } else {
                chcur_single(*pfirst, pcur, 'p');
                if (*pcur == tmp) 
                        *pcur = NULL;
        }
        while (*pfirst != tmp)
                pfirst = &(*pfirst)->next;
        *pfirst = (*pfirst)->next;
        free(tmp);
}

MAKE_SHOW_LIST_FUNCTION(single)

MAKE_SHOW_CURRENT_LIST_FUNCTION(single)

MAKE_SEARCH_LIST_FUNCTION(single)
