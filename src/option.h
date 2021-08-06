#ifndef OPTION_H
#define OPTION_H

#define PROGRAM_NAME "lm"
#define PROGRAM_NAME_LONG "list manager"
#define PROGRAM_EMAIL "17seannnn@gmail.com"
#define PROGRAM_PAGE "https://github.com/17sean/list-manager"

#define VERSION "1.15"

#define AUTHOR "Sergey Nikonov"
#define AUTHOR_NICKNAME "17sean"
#define AUTHOR_PAGE "https://github.com/17sean"

#define OPTION_HELP_SHORT "-h"
#define OPTION_HELP_LONG "--help"
#define OPTION_VERSION_SHORT "-v"
#define OPTION_VERSION_LONG "--version"

int handle_opt(char **argv);

#endif
