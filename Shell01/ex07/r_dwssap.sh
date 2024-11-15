#!/bin/sh
cat /etc/passwd | awk --field-separator ':' "( \$1 !~ /^#.*/ && NR % 2 == 0 && NR >= $FT_LINE1  && NR <= $FT_LINE2  ){print \$1}" | sort -r | awk 'BEGIN { ORS=", "} 1' | sed 's/, $/./'