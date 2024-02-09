/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fusion_cote2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 23:28:32 by yzaoui            #+#    #+#             */
/*   Updated: 2024/02/09 14:33:30 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Header/Minishell.h"

static int	pas_davant(t_node *av, t_node *entre, t_type_input t_cote, int opt)
{
	char	*buff;
	int		err;

	err = 0;
	t_cote = entre->next_node->type_input;
	while (t_cote != DOUBLE_COTE && t_cote != SINGLE_COTE)
	{
		fusion_node(entre, -1, &err);
		if (err)
			return (-1);
		t_cote = entre->next_node->type_input;
	}
	del_next_node(entre);
	buff = ft_strdup(entre->str, &err);
	if (err)
		return (-1);
	free_2str(&(entre->str), NULL);
	if (ft_strcpm(buff, "\"") == TRUE)
		entre->str = ft_strdup("", &err);
	else
		entre->str = ft_strcut(buff, 1, ft_strlen(buff), &err);
	free_2str(&buff, NULL);
	if (err)
		return (-1);
	return (cmd_or_arg(entre, av, opt, &err), err);
}

int	no_legit_fusion_str(t_node *av)
{
	t_type_input	t_av_n;

	if (!av)
		return (1);
	t_av_n = av->next_node->type_input;
	if (t_av_n == ARG || t_av_n == F_RD || \
	t_av_n == CMD || t_av_n == NON_DEFINI)
		return (0);
	return (1);
}

int	is_legitfusion(t_node *av, int option)
{
	if (!av)
		return (1);
	if (av->type_input == NON_DEFINI || av->type_input == CMD || \
	av->type_input == ARG || av->type_input == F_RD || av->type_input == F_RD2)
	{
		if (option == 0 && av->next_node->type_input != SEPARATOR)
			return (0);
		else if (option)
			return (0);
	}
	return (1);
}

void	del_colte2(int *err, t_node *av, t_type_input t_cote)
{
	del_next_node(av);
	while (t_cote != DOUBLE_COTE && t_cote != SINGLE_COTE)
	{
		fusion_node(av, -1, err);
		t_cote = av->next_node->type_input;
	}
	del_next_node(av);
	if (av->type_input == F_RD2)
		av->type_input = F_RD;
}

int	del_cote(t_node *av, t_node *entre, int option, int *err)
{
	t_type_input	t_cote;

	if (*err)
		return (*err);
	t_cote = entre->next_node->type_input;
	if (is_legitfusion(av, 0))
		option = pas_davant(av, entre, t_cote, option);
	else
		del_colte2(err, av, t_cote);
	if (option == -1 || *err)
		return (*err = 1, *err);
	while (*err == 0 && is_legitfusion(entre->next_node, 1) == 0)
		fusion_node(entre, -1, err);
	if (*err)
		return (option);
	find_cmd_and_arg(entre->next_node, entre, option, err);
	return (option);
}
