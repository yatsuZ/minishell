# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/11 03:10:21 by yzaoui            #+#    #+#              #
#    Updated: 2024/01/30 23:03:59 by yzaoui           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############### OBJ de Minishell

ILHAM_GESTION_PATH =	ilham/
ILHAM_GESTION_FILES =	exec_parsing.c		\
						free_data.c			\
						redirect.c			\
						shell_execution.c	\
						utils.c				\
						utils2.c

BULTINS_PATH =	builtins/
BULTINS_FILES =	cd.c			\
				echo.c			\
				env.c			\
				exit.c			\
				export.c		\
				find_builtin.c	\
				pwd.c			\
				unset.c

RD_GESTION_PATH = redirection_gestion/
RD_GESTION_FILES = get_all_rinlimit.c

EXECUTION_PATH = execution/
EXECUTION_FILES =	prompte_to_execute.c	\
					execute.c				\
					find_cmd.c				\
					${addprefix ${RD_GESTION_PATH}, ${RD_GESTION_FILES}}	\
					${addprefix ${ILHAM_GESTION_PATH}, ${ILHAM_GESTION_FILES}}

STR_MANIP_PATH = str_manip/
STR_MANIP_FILES = 	ft_strcpm.c		\
					ft_strlen.c		\
					ft_strcpy.c		\
					ft_strjoin.c	\
					ft_strchr.c

FT_UTILE_PATH = fonction_utile/
FT_UTILE_FILES =	ft_calloc.c		\
					va_env1.c		\
					manip_node.c	\
					manip_node2.c	\
					type_of_str.c	\
					int_to_str.c	\
					${addprefix ${STR_MANIP_PATH}, ${STR_MANIP_FILES}}

INUTILE_PATH = inutile/
INUTILE_FILES = color.c			\
				show_struct.c	\
				show_struct2.c	\
				show_struct3.c

FIND_TYPE_PATH =	find_type_input/
FIND_TYPE_FILES =	cote_and_va_env.c		\
					find_all_rd_and_pip.c	\
					find_cmd_and_arg.c
FUSION_TYPE_PATH =	fusion_node/
FUSION_TYPE_FILES =	fusion_cote.c	\
					fusion_cote2.c	\
					fusion_va.c
PARSING_PATH = parsing/
PARSING_FILES =	parsing.c					\
				error_parsing.c				\
				${addprefix ${FIND_TYPE_PATH}, ${FIND_TYPE_FILES}}	\
				${addprefix ${FUSION_TYPE_PATH}, ${FUSION_TYPE_FILES}}


STRUCT_PATH = struct/
STRUCT_FILES = 	free_env.c			\
				initfree_all.c		\
				initfree_node.c		\
				initfree_execute.c	\
				initfree_all_va.c	\
				initfree_prompt.c	\
				initfree_redirection.c

MINISHELL_PATH = Source/
MINISHELL_FILES =	main.c 												\
					error.c												\
					${addprefix ${FT_UTILE_PATH}, ${FT_UTILE_FILES}}	\
					${addprefix ${INUTILE_PATH}, ${INUTILE_FILES}}		\
					${addprefix ${PARSING_PATH}, ${PARSING_FILES}}		\
					${addprefix ${STRUCT_PATH}, ${STRUCT_FILES}}		\
					${addprefix ${EXECUTION_PATH}, ${EXECUTION_FILES}}	\
					${addprefix ${BULTINS_PATH}, ${BULTINS_FILES}}

OBJ_PATH = obj/
MINISHELL_OBJ = ${addprefix ${OBJ_PATH}, ${MINISHELL_FILES:.c=.o}}

############### ligne de commande

HEADER = ./Header

RM = rm -rf
CC = cc
C_FLAGS = -g3 -Wall -Wextra -Werror -g -I ${HEADER}

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