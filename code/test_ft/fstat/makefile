# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 13:07:53 by yzaoui            #+#    #+#              #
#    Updated: 2023/12/07 13:08:03 by yzaoui           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### OBJ de FSTAT

FSTAT_FILES = main.c

OBJ_PATH = obj/
FSTAT_OBJ = ${addprefix ${OBJ_PATH}, ${FSTAT_FILES:.c=.o}}

############### ligne de commande

RM = rm -rf
CC = cc
C_FLAGS = -g3 -Wall -Wextra -Werror

FLAGS_READLINE = -lreadline

PROGRAM_NAME = FSTAT_Test_Programme

############### COMMANDE OBLIGATOIRE

all: $(OBJ_PATH) ${PROGRAM_NAME}

${PROGRAM_NAME}: ${FSTAT_OBJ}
	$(CC) $(C_FLAGS) ${FSTAT_OBJ} $(FLAGS_READLINE) -o ${PROGRAM_NAME}

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
