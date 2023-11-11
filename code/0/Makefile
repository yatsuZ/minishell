# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/11 03:10:21 by yzaoui            #+#    #+#              #
#    Updated: 2023/11/11 03:39:18 by yzaoui           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############### OBJ de Minishell

MINISHELL_PATH =	./Source/

MINISHELL_FILES =	main.c

MINISHELL_SRC =	${addprefix ${MINISHELL_PATH}, ${MINISHELL_FILES}}

OBJ_MINISHELL = ${MINISHELL_SRC:.c=.o}

############### ligne de commande

RM = rm -rf

CC = cc
C_FLAGS = -g3 -Wall -Wextra -Werror

PROGRAM_NAME = minishell

############### COMMANDE OBLIGATOIRE

${PROGRAM_NAME}: ${OBJ_MINISHELL}
	${CC} ${C_FLAGS} ${OBJ_MINISHELL} -o ${PROGRAM_NAME}

all : ${PROGRAM_NAME}

.c.o:
	${CC} ${C_FLAGS} -c $< -o ${<:.c=.o}

clean :
	${RM} ${OBJ_MINISHELL}

fclean : clean
	${RM} ${PROGRAM_NAME}

re : fclean all
