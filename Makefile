# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sregnard <sregnard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 14:51:18 by sregnard          #+#    #+#              #
#    Updated: 2020/01/08 11:36:30 by lgaultie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###### EXECUTABLES

ASM						:=	asm
COREWAR					:=	corewar

###### LIBFT

LIBDIR					:=	libft/
LIBFT					:=	$(LIBDIR)libft.a

###### DIRECTORIES

INCDIR					:=	includes/
SRCDIR					:=	srcs/
OBJDIR					:=	objs/

DIR_ASM					:=	asm/
DIR_WAR					:=	corewar/
DIR_COM					:=	common/

INCDIR_ASM				:=	$(INCDIR)$(DIR_ASM)
INCDIR_WAR				:=	$(INCDIR)$(DIR_WAR)
INCDIR_COM				:=	$(INCDIR)$(DIR_COM)

SRCDIR_ASM				:=	$(SRCDIR)$(DIR_ASM)
SRCDIR_WAR				:=	$(SRCDIR)$(DIR_WAR)
SRCDIR_COM				:=	$(SRCDIR)$(DIR_COM)

OBJDIR_ASM				:=	$(OBJDIR)$(DIR_ASM)
OBJDIR_WAR				:=	$(OBJDIR)$(DIR_WAR)
OBJDIR_COM				:=	$(OBJDIR)$(DIR_COM)

######	INCLUDES

INCLUDES				:=	-I $(INCDIR_COM)
INCLUDES				+=	-I $(LIBDIR)$(INCDIR)

INCLUDES_ASM			:=	$(INCLUDES)
INCLUDES_ASM			+=	-I $(INCDIR_ASM)

INCLUDES_WAR			:=	$(INCLUDES)
INCLUDES_WAR			+=	-I $(INCDIR_WAR)

INCNAME					:=	asm.h
INC_ASM					:=	$(addprefix $(INCDIR_ASM), $(INCNAME))

INCNAME					:=	corewar.h	\
							champ.h		\
							process.h	\
							arg.h
INC_WAR					:=	$(addprefix $(INCDIR_WAR), $(INCNAME))

INCNAME					:=	common.h	\
							op.h
INC_COM					:=	$(addprefix $(INCDIR_COM), $(INCNAME))

######	SOURCES
######	#######	ASM

SRCNAME					:=	asm.c
SRC_ASM					:=	$(addprefix $(SRCDIR_ASM), $(SRCNAME))

SUBDIR					:=	parsing/
SRCNAME					:=	parsing.c			\
							header.c			\
							stock_instruc.c		\
							labels.c			\
							init_asm.c			\
							param.c				\
							get_prog_size.c		\
							get_ocp.c			\
							check_instruc.c
SRC_ASM					+=	$(addprefix $(SRCDIR_ASM)$(SUBDIR), $(SRCNAME))

SUBDIR					:=	compiling/
SRCNAME					:=	header.c			\
							create_cor.c		\
							instruc.c
SRC_ASM					+=	$(addprefix $(SRCDIR_ASM)$(SUBDIR), $(SRCNAME))

SUBDIR					:=	utils/
SRCNAME					:=	free_asm.c			\
							print.c				\
							manage_error.c		\
							bonus.c				\
							debug.c
SRC_ASM					+=	$(addprefix $(SRCDIR_ASM)$(SUBDIR), $(SRCNAME))


######	#######	VM

SRCNAME					:=	corewar.c
SRC_WAR					:=	$(addprefix $(SRCDIR_WAR), $(SRCNAME))


SUBDIR					:=	champs/
SRCNAME					:=	champs.c	\
							champ.c		\
							sort.c		\
							free.c		\
							print.c
SRC_WAR					+=	$(addprefix $(SRCDIR_WAR)$(SUBDIR), $(SRCNAME))

SUBDIR					:=	processes/
SRCNAME					:=	processes.c	\
							process.c	\
							free.c		\
							print.c
SRC_WAR					+=	$(addprefix $(SRCDIR_WAR)$(SUBDIR), $(SRCNAME))

SUBDIR					:=	args/
SRCNAME					:=	args.c		\
							arg.c		\
							free.c		\
							print.c
SRC_WAR					+=	$(addprefix $(SRCDIR_WAR)$(SUBDIR), $(SRCNAME))

SUBDIR					:=	arena/
SRCNAME					:=	arena.c		\
							fight.c		\
							print.c
SRC_WAR					+=	$(addprefix $(SRCDIR_WAR)$(SUBDIR), $(SRCNAME))

SUBDIR					:=	parsing/
SRCNAME					:=	parsing.c	\
							options.c	\
							errors.c
SRC_WAR					+=	$(addprefix $(SRCDIR_WAR)$(SUBDIR), $(SRCNAME))

SUBDIR					:=	instructions/
SRCNAME					:=	ocp.c		\
							live.c      \
                            ld.c        \
                            st.c        \
                            logic.c     \
                            aff.c       \
                            fork.c      \
                            zjmp.c      \
                            calc.c
SRC_WAR					+=	$(addprefix $(SRCDIR_WAR)$(SUBDIR), $(SRCNAME))

SUBDIR					:=	visu/
SRCNAME					:=	visu.c
SRC_WAR					+=	$(addprefix $(SRCDIR_WAR)$(SUBDIR), $(SRCNAME))

SRCNAME					:=	common.c
SRC_COM					:=	$(addprefix $(SRCDIR_COM), $(SRCNAME))

######	OBJECTS

OBJ_ASM					:=	$(SRC_ASM:$(SRCDIR_ASM)%.c=$(OBJDIR_ASM)%.o)
OBJ_WAR					:=	$(SRC_WAR:$(SRCDIR_WAR)%.c=$(OBJDIR_WAR)%.o)
OBJ_COM					:=	$(SRC_COM:$(SRCDIR_COM)%.c=$(OBJDIR_COM)%.o)

######	FLAGS

CC						:=	gcc
CFLAGS					:=	-Wall -Wextra -Werror -g3
FLAGS_ASM				:=
FLAGS_WAR				:=	-lncurses

######	COLORS

# _GREEN=\e[32m
# _PURPLE=\e[35m
# _BLUE=\e[34m
# _YELLOW=\e[33m
# _CYAN=\e[36m
# _RED=\e[31m
# _END=\e[0m

_RED					:=	\033[1;31m
_GREEN					:=	\033[1;32m
_YELLOW					:=	\033[1;33m
_BLUE					:=	\033[1;34m
_MAGENTA				:=	\033[1;35m
_CYAN					:=	\033[1;36m
_BG_RED					:=	\033[1;41m
_BG_GREEN				:=	\033[1;42m
_BG_YELLOW				:=	\033[1;43m
_BG_BLUE				:=	\033[1;44m
_BG_MAGENTA				:=	\033[1;45m
_BG_CYAN				:=	\033[1;46m
_RESET					:=	\033[0m

######	RULES

all						:	$(LIBFT) $(ASM) $(COREWAR)
	@$(MAKE) art

$(LIBFT)				:
	@make -C $(LIBDIR)

$(ASM)					:	$(LIBFT) $(OBJ_ASM) $(OBJ_COM)
	@$(CC) $(CFLAGS) $(FLAGS_ASM) $(INCLUDES_ASM) -o $@ $(OBJ_COM) $(OBJ_ASM) $(LIBFT)
	@printf "\r" ; tput el
	@printf "$(_GREEN)%-10s : Executable\tbuilt.\n\a$(_RESET)" $(ASM)

$(COREWAR)				:	$(LIBFT) $(OBJ_WAR) $(OBJ_COM)
	@$(CC) $(CFLAGS) $(FLAGS_WAR) $(INCLUDES_WAR) -o $@ $(OBJ_COM) $(OBJ_WAR) $(LIBFT)
	@printf "\r" ; tput el
	@printf "$(_GREEN)%-10s : Executable\tbuilt.\n\a$(_RESET)" $(COREWAR)

$(OBJDIR_ASM)%.o		:	$(SRCDIR_ASM)%.c $(INC_ASM) $(INC_COM)
	@if [ ! -d $(dir $@) ]; \
	then \
		printf "\r"; \
		tput el; \
		printf "$(_YELLOW)%-10s : %s $(_RESET)\a" $(ASM) $(dir $<); \
	fi;
	@mkdir -p $(dir $@);
	@$(CC) $(CFLAGS) $(INCLUDES_ASM) -o $@ -c $<
	@printf "$(_BG_GREEN) $(_RESET)"

$(OBJDIR_WAR)%.o		:	$(SRCDIR_WAR)%.c $(INC_WAR) $(INC_COM)
	@if [ ! -d $(dir $@) ]; \
	then \
		printf "\r"; \
		tput el; \
		printf "$(_YELLOW)%-10s : %s $(_RESET)\a" $(COREWAR) $(dir $<); \
	fi;
	@mkdir -p $(dir $@);
	@$(CC) $(CFLAGS) $(INCLUDES_WAR) -o $@ -c $<
	@printf "$(_BG_GREEN) $(_RESET)"

$(OBJDIR_COM)%.o		:	$(SRCDIR_COM)%.c $(INC_COM)
	@if [ ! -d $(dir $@) ]; \
	then \
		printf "\r"; \
		tput el; \
		printf "$(_YELLOW)%-10s : %s $(_RESET)\a" "common" $(dir $<); \
	fi;
	@mkdir -p $(dir $@);
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<
	@printf "$(_BG_GREEN) $(_RESET)"

clean					:
	@rm -rf $(OBJDIR)
	@printf "$(_BLUE)%-10s : Objects\tcleaned.\n$(_RESET)" $(ASM)
	@printf "$(_BLUE)%-10s : Objects\tcleaned.\n$(_RESET)" $(COREWAR)
	@make clean -C $(LIBDIR)

fclean					:	clean
	@rm -rf $(ASM) $(COREWAR)
	@printf "$(_MAGENTA)%-10s : Executable\tcleaned.\n$(_RESET)" $(ASM)
	@printf "$(_MAGENTA)%-10s : Executable\tcleaned.\n$(_RESET)" $(COREWAR)
	@rm -rf $(LIBFT)
	@printf "$(_MAGENTA)%-10s : Library\tcleaned.\n$(_RESET)" $(notdir $(LIBFT))

re						:	fclean	all

war						:
	@rm -rf $(OBJDIR)
	@printf "$(_BLUE)%-10s : Objects\tcleaned.\n$(_RESET)" $(ASM)
	@printf "$(_BLUE)%-10s : Objects\tcleaned.\n$(_RESET)" $(COREWAR)
	@rm -rf $(ASM) $(COREWAR)
	@printf "$(_MAGENTA)%-10s : Executable\tcleaned.\n$(_RESET)" $(ASM)
	@printf "$(_MAGENTA)%-10s : Executable\tcleaned.\n$(_RESET)" $(COREWAR)
	@$(MAKE)

art						:
	@printf "$(_RED)٩(̾●̮̮̃̾•̃̾)۶ READY FOR WAR ٩(̾●̮̮̃̾•̃̾)۶\n$(_RESET)"
