#!/bin/sh
# ./combine.sh 0 12 grenade_explosion grenade_explosion_b grenade_explosion_combined
# will combine grenade_explosion00.png with grenade_explosion_b00.png to grenade_explosion_combined00.png
# and so on for 0 - 12

myexec() {
	echo $@
	$@
}

DIR=$(dirname "$(readlink -f "$0")")
from=$1
to=$2
filenamea=$3
filenameb=$4
filenameout=$5

for i in $(seq $from $to) ; do
	j=$(printf "%.2d" $i)
	myexec $DIR/imgcombine.out $filenamea$j.png $filenameb$j.png $filenameout$j.png
done
