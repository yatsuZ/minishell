/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 09:30:18 by yzaoui            #+#    #+#             */
/*   Updated: 2024/02/10 16:38:17 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

void	error_parsing(int iderr)
{
	put_color_txt(ROUGE);
	printf("Error Parsing :\t");
	put_color_txt(JAUNE);
	if (iderr == 0)
		printf("No error.");
	else if (iderr == 1)
		printf("Unclosed SINGLE QUOTE.");
	else if (iderr == 2)
		printf("Unclosed DOUBLE QUOTE.");
	else if (iderr == 3)
		printf("PIP that follows.");
	else if (iderr == 4)
		printf("Ends with a PIPE.");
	else if (iderr == 5)
		printf("Starts with a PIPE.");
	else if (iderr == 6)
		printf("Ends with an EMPTY REDIRECTION.");
	else if (iderr == 7)
		printf("EMPTY REDIRECTION.");
	else if (iderr == 8)
		printf("New line not interpreted.");
	else if (iderr == 9)
		printf("Too many characters, the maximum is %d.", MAXLINE);
	printf("\n");
	put_color_txt(EMPTY_COLOR);
}
