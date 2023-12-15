# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/11 03:10:21 by yzaoui            #+#    #+#              #
#    Updated: 2023/12/15 11:19:53 by yzaoui           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############### OBJ de Minishell

FT_UTILE_PATH = fonction_utile/
FT_UTILE_FILES =	ft_strcpm.c	\
					ft_strlen.c	\
					ft_calloc.c	\
					ft_strcpy.c

INUTILE_PATH = inutile/
INUTILE_FILES = color.c

STRUCT_PATH = struct/
STRUCT_FILES = 	initfree_all.c	\
				initfree_node.c	\
				initfree_prompt.c

MINISHELL_PATH = Source/
MINISHELL_FILES =	main.c 				\
					invite_de_comande.c	\
					${addprefix ${FT_UTILE_PATH}, ${FT_UTILE_FILES}}	\
					${addprefix ${INUTILE_PATH}, ${INUTILE_FILES}}		\
					${addprefix ${STRUCT_PATH}, ${STRUCT_FILES}}

OBJ_PATH = obj/
MINISHELL_OBJ = ${addprefix ${OBJ_PATH}, ${MINISHELL_FILES:.c=.o}}

############### ligne de commande

RM = rm -rf
CC = cc
C_FLAGS = -g3 -Wall -Wextra -Werror

READLINE = -lreadline

PROGRAM_NAME = minishell

############### COMMANDE OBLIGATOIRE

all: $(OBJ_PATH) ${PROGRAM_NAME}

${PROGRAM_NAME}: ${MINISHELL_OBJ}
	$(CC) $(C_FLAGS) ${MINISHELL_OBJ} $(READLINE) -o ${PROGRAM_NAME}

$(OBJ_PATH)%.o: $(MINISHELL_PATH)%.c
	@mkdir -p $(@D)
	$(CC) $(C_FLAGS) -c $< -o $@

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

clean:
	$(RM) $(OBJ_PATH)

fclean: clean
	$(RM) ${PROGRAM_NAME}

norme:
	clear
	@ if ! norminette | grep "Error"; then echo "\033[32mOK!\033[0m"; fi

re: fclean all