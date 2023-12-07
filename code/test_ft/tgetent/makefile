# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 23:01:29 by yzaoui            #+#    #+#              #
#    Updated: 2023/12/07 23:14:03 by yzaoui           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### OBJ de TGETENT

TGETENT_FILES = main.c

OBJ_PATH = obj/
TGETENT_OBJ = ${addprefix ${OBJ_PATH}, ${TGETENT_FILES:.c=.o}}

############### ligne de commande

RM = rm -rf
CC = cc
C_FLAGS = -g3 -Wall -Wextra -Werror

FLAGS_READLINE = -lreadline
FLAGS_TGETENT = -lncurses

PROGRAM_NAME = TGETENT_Test_Programme

############### COMMANDE OBLIGATOIRE

all: $(OBJ_PATH) ${PROGRAM_NAME}

${PROGRAM_NAME}: ${TGETENT_OBJ}
	$(CC) $(C_FLAGS) ${TGETENT_OBJ} ${FLAGS_READLINE} ${FLAGS_TGETENT} -o ${PROGRAM_NAME}

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
