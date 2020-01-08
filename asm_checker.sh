#!/bin/bash
name_s=$1
name=${name_s%??}
name_c="${name}.cor"

RED='\033[0;31m'
B_RED='\033[1;31m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
B_GREEN='\033[1;32m'
NC='\033[0m'

clear

echo -e "${CYAN}************************************************************************${NC}"
echo -e "			    ${PURPLE}ASM CHECKER${NC}"
echo -e "${PURPLE}			chrhuang & lgaultie${NC}"
echo -e "${CYAN}************************************************************************${NC}"
echo ""
if [ -f "$name_s" ]
then
	echo -e "You want to check ${PURPLE}$name_s${NC}"
	echo ""
else
	echo "We couldn't find a file named $name_s..."
	echo ""
	exit 0
fi
rm -rf mine
rm -rf your

./asm -ec $name_s > /dev/null
echo ""

if [ -f "$name_c" ]
then
	hexdump $name_c > mine
else
	echo -e "${B_RED}ERROR in .s file: your asm couldn't create .cor.${NC}"
fi

./res/asm $name_s > /dev/null

if [ -f "$name_c" ]
then
	hexdump $name_c > your
else
	echo -e "${B_RED}ERROR in .s file: their asm couldn't create .cor.${NC}"
	exit 0
fi

diff mine your > diff

if [ -s diff ]
then
	echo ""
	echo "${B_RED}We found differences ! :(${NC}"
	echo ""
	cat diff
else
	echo ""
	echo -e "${PURPLE}Your .cor file:${NC}"
	echo ""
	echo -en "${CYAN}"
	cat mine
	echo -en "${NC}"
	echo ""
	echo -e "${PURPLE}Their .cor file:${NC}"
	echo ""
	echo -en "${CYAN}"
	cat your
	echo -en "${NC}"
	echo ""
	echo -e "${B_GREEN}OK - no differences between the two .cor files !${NC}"
	echo ""
fi

rm -rf mine
rm -rf your
rm -rf diff
