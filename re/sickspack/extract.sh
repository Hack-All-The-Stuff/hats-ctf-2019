#!/bin/bash
objdump -d $1 | awk -F"\n" -v RS="\n\n" '$1 ~ /fun/' | tail -n +2 | cut -d$'\t' -f2 | tr -d ' \n' > $1.bytes