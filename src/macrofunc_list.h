#ifndef MACROFUNC_LIST_H
#define MACROFUNC_LIST_H

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
                        printf("%d %c\n", \
                               first->data, first == cur ? '*' : 0); \
        }

#define MAKE_SHOW_CURRENT_LIST_FUNCTION(MODE) \
        void show_cur_ ## MODE(struct MODE ## _item *cur) \
        { \
                if (!cur) \
                        return; \
                printf("%d *\n", cur->data); \
        }

#define MAKE_SEARCH_LIST_FUNCTION(MODE) \
        void search_ ## MODE(struct MODE ## _item *first, \
                             struct MODE ## _item **pcur, \
                             int n) \
        { \
                for (; first; first = first->next) { \
                        if (n == first->data) { \
                                printf("Found.\n"); \
                                *pcur = first; \
                                return; \
                        } \
                } \
                printf("Not found.\n"); \
        }

#endif
