#!/bin/sh

CC=gcc

case $1 in
        install)
                cd src/;
                $CC -ansi -pedantic -Wall -Og -g -c error.c option.c mode.c \
                    cmd.c help.c single.c doubly.c bintree.c \
                    dsp_all.c lmstring.c value.c version.c;
                $CC -ansi -pedantic -Wall -Og -g main.c error.o option.o \
                    mode.o cmd.o help.o single.o doubly.o bintree.o \
                    dsp_all.o lmstring.o value.o version.o -o ../lm;
                mv -f ../lm /usr/local/bin/
                cd ../po/;
                mkdir -p /usr/share/locale/ru/LC_MESSAGES;
                msgfmt ru.po -o /usr/share/locale/ru/LC_MESSAGES/lm.mo;;
        pot) xgettext --keyword="_" --files-from="po/POTFILES.in" -o po/lm.pot;;
        mo)
                cd po/;
                mkdir -p /usr/share/locale/ru/LC_MESSAGES;
                msgfmt ru.po -o /usr/share/locale/ru/LC_MESSAGES/lm.mo;;
        * | --help)
                echo "\
Usage:
build.sh [COMMAND/--OPTION]

Options:
        --help     this help

Commands:
        install    install this package
        pot        generate .pot file in po/
        mo         compile and move .mo files from po/ to locale dirs";;
esac
