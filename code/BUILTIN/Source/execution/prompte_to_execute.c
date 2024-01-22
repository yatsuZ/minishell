/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompte_to_execute.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:00:12 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/22 15:29:23 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

char	**init_tab(t_node *n)
{
	size_t	nbr_of_arg;

	if (!n)
		return (NULL);
	nbr_of_arg = 0;
	while (n && n->type_input != PIP)
	{
		if (n->type_input == ARG)
			nbr_of_arg++;
		n = n->next_node;
	}
	if (!nbr_of_arg)
		return (NULL);
	return (ft_calloc(nbr_of_arg + 1, sizeof(char *)));
}

int	get_all_exe2(t_node *n, size_t *i, t_execute **res, t_redirecte **all_rd)
{
	int	err;

	err = 0;
	if (n->type_input == CMD)
		(*res)->cmd = ft_strdup(n->str);
	else if (n->type_input == ARG)
	{
		(*res)->arg[*i] = ft_strdup(n->str);
		*i = *i + 1;
	}
	else if (n->type_input == R_IN || n->type_input == R_OUT || \
	n->type_input == R_OUT_ADD || n->type_input == R_IN_LIMIT)
	{
		if (n->next_node->type_input == SEPARATOR)
			err = add_rd(all_rd, n->type_input, n->next_node->next_node);
		else
			err = add_rd(all_rd, n->type_input, n->next_node);
	}
	return (err);
}

t_execute	*get_all_exe(t_prompt *p, t_node *n, size_t i, int *err)
{
	t_execute		*res;
	t_redirecte		*all_rd;

	if (!n)
		return (NULL);
	res = init_execute(NULL, NULL, NULL, err);
	res->arg = init_tab(n);
	all_rd = NULL;
	if (*err)
		return (res);
	while (n && n->type_input != PIP && *err == 0)
	{
		(*err) = get_all_exe2(n, &i, &res, &all_rd);
		n = n->next_node;
	}
	res->all_rd = all_rd;
	if (!n || *err)
		return (res);
	res->pip = get_all_exe(p, n->next_node, 0, err);
	return (res);
}

void	prompte_to_execute(t_all_struct *all)
{
	int	err;

	err = 0;
	all->exe = get_all_exe(all->prompte, all->prompte->all_cmd_line, 0, &err);
	if (err)
		printf("ERROR D'ALLOC DANS PROMPTE TO EXECUTE.\n\n");
	get_all_rinlimit(all->exe, &(all->prompte->brut), all->all_va);
}
