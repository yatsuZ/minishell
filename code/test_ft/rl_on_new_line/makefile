# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/02 14:46:03 by yzaoui            #+#    #+#              #
#    Updated: 2023/12/02 14:48:29 by yzaoui           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### OBJ de rl_on_new_line

RL_ON_NEW_LINE_FILES = main.c

OBJ_PATH = obj/
RL_ON_NEW_LINE_OBJ = ${addprefix ${OBJ_PATH}, ${RL_ON_NEW_LINE_FILES:.c=.o}}

############### ligne de commande

RM = rm -rf
CC = cc
C_FLAGS = -g3 -Wall -Wextra -Werror

FLAGS_READLINE = -lreadline

PROGRAM_NAME = rl_on_new_line_Test_Programme

############### COMMANDE OBLIGATOIRE

all: $(OBJ_PATH) ${PROGRAM_NAME}

${PROGRAM_NAME}: ${RL_ON_NEW_LINE_OBJ}
	$(CC) $(C_FLAGS) ${RL_ON_NEW_LINE_OBJ} $(FLAGS_READLINE) -o ${PROGRAM_NAME}

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
