#!/bin/sh
set -eu
SRC="Task08/task08_build_demo.c"
gcc -E "$SRC" -o Task08/task08.i
gcc -S "$SRC" -o Task08/task08.s
gcc -c "$SRC" -o Task08/task08.o
gcc Task08/task08.o -o Task08/task08_demo
./Task08/task08_demo
printf '\\nGenerated files:\\n'
ls -l Task08/task08.i Task08/task08.s Task08/task08.o Task08/task08_demo
