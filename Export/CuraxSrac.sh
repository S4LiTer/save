#!/bin/sh
echo -ne '\033c\033]0;T1\a'
base_path="$(dirname "$(realpath "$0")")"
"$base_path/CuraxSrac.x86_64" "$@"
