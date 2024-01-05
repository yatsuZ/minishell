/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fusion_cote2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 23:28:32 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/05 17:12:53 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Header/Minishell.h"

// [AV]"[ENTRE]"[APRES] fusion AV ENTRE APRES
// SI AV present alors fusion tout ce qui suit en retirant les "" ou '' pas besoin de categoriser le type dinpute deja fais
// JE FUSION TOUT CE qui a entre les "" apres je change la string en retirant le dernier et premiere caractere et apres en fonction de previous je catgorise le type de str
// SI APRES et un NON defini alors je fusion ENTRE

static int	pas_davant(t_node *av, t_node *entre, t_type_input t_cote, int opt)
{
	char	*buff;

	t_cote = entre->next_node->type_input;
	while (t_cote != DOUBLE_COTE && t_cote != SINGLE_COTE)
	{
		fusion_node(entre, -1);
		t_cote = entre->next_node->type_input;
	}
	del_next_node(entre);
	buff = ft_strdup(entre->str);
	free(entre->str);
	entre->str = NULL;
	if (ft_strcpm(buff, "\"") == TRUE)
		entre->str = ft_strdup("");
	else
		entre->str = ft_strcut(buff, 1, ft_strlen(buff));
	free(buff);
	buff = NULL;
	return (cmd_or_arg(entre, av, opt));
}

int	no_legit_fusion_str(t_node *av)
{
	t_type_input	t_av_n;

	if (!av)
		return (1);
	t_av_n = av->next_node->type_input;
	if (t_av_n== ARG || t_av_n == F_RD || \
	t_av_n == CMD || t_av_n == NON_DEFINI)
		return (0);
	return (1);
}

int	is_legitfusion(t_node *av, int option)
{
	if (!av)
		return (1);
	if (av->type_input == NON_DEFINI || av->type_input == CMD || \
	av->type_input == ARG || av->type_input == F_RD)
	{
		if (option == 0 && av->next_node->type_input != SEPARATOR)
			return (0);
		else if (option)
			return (0);
	}
	return (1);
}

int	del_cote(t_node *av, t_node *entre, int option)
{
	t_type_input	t_cote;

	t_cote = entre->next_node->type_input;
	if (is_legitfusion(av, 0))
		option = pas_davant(av, entre, t_cote, option);
	else
	{
		entre = av;
		del_next_node(entre);
		while (t_cote != DOUBLE_COTE && t_cote != SINGLE_COTE)
		{
			fusion_node(entre, -1);
			t_cote = entre->next_node->type_input;
		}
		del_next_node(entre);
	}
	if (is_legitfusion(entre->next_node, 1) == 0)
		fusion_node(entre, -1);
	find_cmd_and_arg(entre->next_node, entre, option);
	return (option);
}
