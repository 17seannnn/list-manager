CC=gcc

cd src/
$CC -ansi -pedantic -Wall -Og -g -c option.c mode.c cmd.c help.c single.c doubly.c bintree.c dsp_all.c lm_string.c value.c version.c
$CC -ansi -pedantic -Wall -Og -g main.c option.o mode.o cmd.o help.o single.o doubly.o bintree.o dsp_all.o lm_string.o value.o version.o -o ../lm
