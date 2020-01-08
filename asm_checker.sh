#!/bin/bash
name_s=$1
name=${name_s%??}
name_c="${name}.cor"

clear
echo "*********************************************"
if [ -f "$name_s" ]
then
	echo "   We found a file named $name_s"
else
	echo "   No file named $name_s >:("
	echo "*********************************************"
	exit 0
fi
echo "*********************************************"
rm -rf mine
rm -rf your

./asm $name_s > /dev/null

if [ -f "$name_c" ]
then
	hexdump $name_c > mine
else
	echo "Couldn't create .cor file because of errors"
	exit 0
fi

./res/asm $name_s > /dev/null

if [ -f "$name_c" ]
then
	hexdump $name_c > your
else
	echo "Couldn't create .cor file because of errors"
	exit 0
fi

diff mine your > diff

echo "Let's see the diff"
if [ -s diff ]
then
	echo "KO"
	cat diff
else
	echo "OK"
fi

rm -rf mine
rm -rf  your
rm -rf diff
