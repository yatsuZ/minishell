# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/08 00:18:42 by yzaoui            #+#    #+#              #
#    Updated: 2023/12/08 00:20:09 by yzaoui           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### OBJ de TGETSTR

TGETSTR_FILES = main.c

OBJ_PATH = obj/
TGETSTR_OBJ = ${addprefix ${OBJ_PATH}, ${TGETSTR_FILES:.c=.o}}

############### ligne de commande

RM = rm -rf
CC = cc
C_FLAGS = -g3 -Wall -Wextra -Werror

FLAGS_READLINE = -lreadline
FLAGS_TGETSTR = -lncurses

PROGRAM_NAME = TGETSTR_Test_Programme

############### COMMANDE OBLIGATOIRE

all: $(OBJ_PATH) ${PROGRAM_NAME}

${PROGRAM_NAME}: ${TGETSTR_OBJ}
	$(CC) $(C_FLAGS) ${TGETSTR_OBJ} ${FLAGS_READLINE} ${FLAGS_TGETSTR} -o ${PROGRAM_NAME}

$(OBJ_PATH)%.o: %.c
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
