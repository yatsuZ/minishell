/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_rinlimit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:21:40 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/12 17:47:27 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

static char	*add_nwl(char *str, int nbr_of_nwl)
{
	char	*new;
	char	*new2;

	new = ft_strjoin(str, "\n");
	free(str);
	str = NULL;
	if (nbr_of_nwl == 1)
	{
		new2 = ft_strjoin("\n", new);
		free(new);
		new = NULL;
		return (new2);
	}
	return (new);
}

static char	*get_rinlimit(char *limit, char *brut, int nbr_of_nwl, int va_on)
{
	char	*plus;
	char	*next;
	char	*fusion;
	(void)	va_on;

	next = readline("heredoc>>");
	if (ft_strcpm(limit, next) == TRUE)// doit verifier aue tout est bon prendre en compte juste le dernier \n_last_nwl
	{
		while (nbr_of_nwl--)
			rl_clear_history();
		return (ft_strdup(""));
	}
	// if (va_on)
	// 	input_with_va(&next);
	plus = add_nwl(next, nbr_of_nwl);
	fusion = ft_strjoin(brut, plus);
	add_history(fusion);
	++nbr_of_nwl;
	next = get_rinlimit(limit, fusion, nbr_of_nwl, va_on);
	free(plus);
	plus = NULL;
	plus = ft_strjoin(fusion, next);
	return (free(next), next = NULL, free(fusion), fusion = NULL, plus);
}

// Je dois refaire le parssing rconcernant 
// le heredoc et les Variable denvironement
void	get_all_rinlimit(t_execute *all_exe, char *brut)
{
	t_redirecte	*rd;
	char		*tmp;

	(void) brut;
	// printf("Je dois recuperer tout les heardoc !! et modifier en consequant \
	// le add history.\n");
	// printf("all->prompte->brut devra ajouter a chaque entre et tant que \
	// aue je ne suis pas arriver au resultat voulue ou aux EOL alors \
	// jajouejoute dans add history puis je free tout.\n");
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
