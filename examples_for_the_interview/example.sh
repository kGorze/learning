#!/bin/bash

strace -f -o trace.log ./app


cat /proc/$$/status
cat /proc/$$/maps

lscpu
ls -l /sys/class | head

qemu-aarch64 -L /usr/aarch64-linux-gnu ./hello.arm64

set -Eeuo pipefail
trap 'echo "Error: $BASH_SOURCE:$LINENO Aborting..." >&2' ERR

trap 'echo "error: $BASH_SOURCE:$LINENO Aborting..." >&2'
ERR

trap 'handler $? $LINENO' ERR
trap 'rm -rf $TMPDIR"' EXIT


find . -type f -name '*.exe' -print0 | xargs -0 -r rm -f
find src -type f \( -name '*.c' -o -name '*.h'\) -print0 |
xargs -0 -r -n 20 -P "$(nproc)" clang-format -i
