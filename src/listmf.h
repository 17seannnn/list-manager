#ifndef LISTMF_H
#define LISTMF_H

#include "gtmd.h"

#define MAKE_DISPOSE_LIST_FUNCTION(MODE) \
        void dsp_ ## MODE(struct MODE ## _item *first) \
        { \
                struct MODE ## _item *tmp; \
                while (first) { \
                        tmp = first; \
                        first = first->next; \
                        free(tmp); \
                } \
        }

#define MAKE_SHOW_LIST_FUNCTION(MODE) \
        void show_ ## MODE(struct MODE ## _item *first, \
                           struct MODE ## _item *cur) \
        { \
                for (; first; first = first->next) \
                        printf(_("%d %c\n"), \
                               first->data, first == cur ? '*' : 0); \
        }

#define MAKE_SHOW_CURRENT_LIST_FUNCTION(MODE) \
        void show_cur_ ## MODE(struct MODE ## _item *cur) \
        { \
                if (!cur) \
                        return; \
                printf(_("%d *\n"), cur->data); \
        }

#define MAKE_SEARCH_LIST_FUNCTION(MODE) \
        void search_ ## MODE(struct MODE ## _item *first, \
                             struct MODE ## _item **pcur, \
                             int n) \
        { \
                for (; first; first = first->next) { \
                        if (n == first->data) { \
                                printf(_("Found.\n")); \
                                *pcur = first; \
                                return; \
                        } \
                } \
                printf(_("Not found.\n")); \
        }

#endif
