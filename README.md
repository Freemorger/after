## Dumb program to run some command after specific time
Sure, there is `at` and `cron`, but I wanted to write my own one, briefly. 
and here it is.   
Works on POSIX systems.
## Build and run 
```bash
gcc src/main.c -o after 
# or: 
gcc -O2 src/main.c -o after 
# but do you really need optimizations here?..
```
anyways, then run it:
```bash
after time command 
```
example:
```bash 
after 10m pacman -Syu
```
supported time specifiers:
- s/S (seconds)
- m/M (minutes)
- h/H (hours)
- d/D (days, if you really gonna to)
