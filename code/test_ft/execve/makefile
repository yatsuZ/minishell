# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 13:50:35 by yzaoui            #+#    #+#              #
#    Updated: 2023/12/07 14:01:52 by yzaoui           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### OBJ de EXECVE

EXECVE_FILES = main.c
EXECVE_FILES2 = main2.c
OBJ_PATH = obj/
EXECVE_OBJ = ${addprefix ${OBJ_PATH}, ${EXECVE_FILES:.c=.o}}
EXECVE_OBJ2 = ${addprefix ${OBJ_PATH}, ${EXECVE_FILES2:.c=.o}}

############### ligne de commande

RM = rm -rf
CC = cc
C_FLAGS = -g3 -Wall -Wextra -Werror

FLAGS_READLINE = -lreadline

PROGRAM_NAME = EXECVE_Test_Programme
PROGRAM_NAME2 = EXECVE2_Test_Programme

############### COMMANDE OBLIGATOIRE

all: $(OBJ_PATH) ${PROGRAM_NAME}

${PROGRAM_NAME}: ${EXECVE_OBJ} ${EXECVE_OBJ2}
	$(CC) $(C_FLAGS) ${EXECVE_OBJ} $(FLAGS_READLINE) -o ${PROGRAM_NAME}
	$(CC) $(C_FLAGS) ${EXECVE_OBJ2} $(FLAGS_READLINE) -o ${PROGRAM_NAME2}

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
