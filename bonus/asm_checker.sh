#!/bin/bash

RED='\033[0;31m'
B_RED='\033[1;31m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
B_GREEN='\033[1;32m'
NC='\033[0m'

clear

echo -e "${CYAN}************************************************************************${NC}"
echo -e "			    ${PURPLE}ASM CHECKER${NC}"
echo -e "		    ${PURPLE}chrhuang, cmouele & lgaultie${NC}"
echo -e "${CYAN}************************************************************************${NC}"

if [ "$#" -lt 1 ]
then
    # if no arguments are provided
    echo "Please provide an argument"
    echo ""
    exit 0
else
    # for every file provided in arguments
    for name_s in "$@"
    do
        if [ -f "$name_s" ]
        then
            # if the .s file exists, we register its name
            name=${name_s%??}
            name_c="${name}.cor"

            echo -e "You want to check ${PURPLE}$name_s${NC}"

            # we delete the .cor file if necessary and launch our asm
            rm -rf $name_c
            ../asm $name_s
            if [ -s $name_c ]
            then
                # if ./asm is successful, we store the hexdump of it in 'our'
                hexdump $name_c > our
            else
                # else, we display an error message and quit
                echo ""
                echo -e "${B_RED}ERROR in .s file: our asm couldn't create .cor.${NC}"
                exit 0
            fi

            # we delete the previous .cor file to avoid any problem and launch the school's asm
            rm -rf $name_c
            ./asm_zaz $name_s
            if [ -s $name_c ]
            then
                # if asm_zaz is successful, we store the hexdump of it in 'their'
                hexdump $name_c > their
            else
                # else, we display an error message and quit
                echo ""
                echo -e "${B_RED}ERROR in .s file: asm_zaz couldn't create .cor.${NC}"
                exit 0
            fi

            # we compare 'our' and 'their' and store the diff in 'diff'
            diff our their > diff

            if [ -s diff ]
            then
                # if 'diff' is not empty, we display an error message and quit
                echo ""
                echo -e "${B_RED}We found differences ! :(${NC}"
                cat diff
            else
                # if 'diff' is empty, that means that 'our' and 'their' are identical, so it's a success
                echo ""
                echo -e "${PURPLE}Your .cor file:${NC}"
                echo ""
                echo -en "${CYAN}"
                cat our
                echo -en "${NC}"
                echo ""
                echo -e "${PURPLE}Their .cor file:${NC}"
                echo ""
                echo -en "${CYAN}"
                cat their
                echo -en "${NC}"
                echo ""
                echo -e "${B_GREEN}OK - no differences between the two .cor files !${NC}"
            fi
        else
            # if the .s file doesn't exist, we display an error message
            echo ""
            echo -e "${B_RED}ERROR:${NC} We couldn't find a file named ${B_RED}$name_s${NC}"
        fi
    done
fi

rm -rf our
rm -rf their
rm -rf diff
