CC=gcc

cd src/
$CC -ansi -pedantic -Wall -Og -g -c error.c option.c mode.c cmd.c help.c single.c doubly.c bintree.c dsp_all.c lmstring.c value.c version.c
$CC -ansi -pedantic -Wall -Og -g main.c error.o option.o mode.o cmd.o help.o single.o doubly.o bintree.o dsp_all.o lmstring.o value.o version.o -o ../lm
mv -f ../lm /usr/bin
