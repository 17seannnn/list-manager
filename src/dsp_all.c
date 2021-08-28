/* dsp_all.c */

#include "single.h"
#include "doubly.h"
#include "bintree.h"

#include "dsp_all.h"

void dsp_all(struct pointer p)
{
        dsp_single(p.s_first);
        dsp_doubly(p.d_first);
        dsp_node(p.root);
}
