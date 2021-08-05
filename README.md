# List Manager
**Program that give you access to manage dynamic data structures**

## Usage
```bash
lm [OPTION]
```

### Options:
```
-h, --help      show help
-v, --version   show version
```

### Modes:
- Single-linked list
- Doubly-linked list
- Binary tree

### Commands:
```
[M/m] - change mode
[C/c] - change current pointer
[A/a] - add item
[D]   - dispose all
[d]   - dispose current
[S]   - show all
[s]   - show current
[?]   - search item
[H/h] - this help
[Q/q] - quit
```

## Install
```bash
git clone https://github.com/17sean/list-manager.git
cd list-manager/src
gcc -c lm_string.c option.c mode.c cmd.c value.c help.c single.c doubly.c bintree.c dsp_all.c
gcc main.c lm_string.o option.o mode.o cmd.o value.c help.o single.o doubly.o bintree.o dsp_all.o -o lm
```
