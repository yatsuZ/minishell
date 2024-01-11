/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_rinlimit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:21:40 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/11 21:02:48 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

static char	*get_rinlimit(char *limit, char *brut, int nbr_of_nwl, int va_on)
{
	char	*plus;

	(void) brut;
	(void) va_on;
	(void) nbr_of_nwl;
	put_color_txt(VERT);
	plus = readline("heredoc >>\033[0m");
	put_color_txt(EMPTY_COLOR);
	if (ft_strcpm(limit, plus) == TRUE)
		return (ft_strdup(""));
	return (plus);
}

// Je dois refaire le parssing rconcernant 
// le heredoc et les Variable denvironement
void	get_all_rinlimit(t_execute *all_exe, char *brut)
{
	t_redirecte	*rd;
	char		*tmp;

	(void) brut;
	printf("Je dois recuperer tout les heardoc !! et modifier en consequant \
	le add history.\n");
	printf("all->prompte->brut devra ajouter a chaque entre et tant que \
	aue je ne suis pas arriver au resultat voulue ou aux EOL alors \
	jajouejoute dans add history puis je free tout.\n");
	while (all_exe)
	{
		rd = all_exe->all_rd;
		while (rd)
		{
			if (rd->type_rd == R_IN_LIMIT)
			{
				add_history(brut);
				tmp = get_rinlimit(rd->str_file, brut, 1, rd->va_activate);
				free(rd->str_file);
				rd->str_file = NULL;
				rd->str_file = tmp;
			}
			rd = rd->next;
		}
		all_exe = all_exe->pip;
	}
}
