/*
 * gtmd.h - gettext macro definitions
 * Header for every module with strings
 */

#ifndef GTMD_H
#define GTMD_H

#include <libintl.h>

#define _(STR) gettext(STR)
#define N_(STR) STR

#endif
