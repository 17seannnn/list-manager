# List Manager
Program that give you access to manage dynamic data structures

## Usage
Three modes:
- Single-link list
- Doubly-link list
- Binary tree

For now you can add items to your structure, dispose them and show them.

Later, i want to add some additional features for doubly-linked list and
binary tree.

## Install
```bash
git clone https://github.com/17sean/list-manager.git
cd list-manager/src
gcc -c lm_string.c option.c mode.c cmd.c value.c help.c single.c doubly.c bintree.c dsp_all.c
gcc main.c lm_string.o option.o mode.o cmd.o value.c help.o single.o doubly.o bintree.o dsp_all.o -o lm
```
