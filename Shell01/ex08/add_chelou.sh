#!/bin/sh
echo "$FT_NBR1 + $FT_NBR2" | tr "mrdoc" "01234" | tr "'" "0" | tr '\\"?1' '1234' | xargs echo "obase=13;ibase=4;" | bc | tr "0123456789ABC" "gtaio luSnemf"