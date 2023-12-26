/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 21:32:59 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/26 09:30:25 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

// Le premier parsing cherche :
// 1. Les single cote ou double.
// 2. Les variable d'environement.
// 3. Les seperateur entre chaque arguement.
// Puis fusion les string et la VA_ENV et retourne 1 si une cote
// n'est pas fermée Dois fusione tout les str donc modifier
// node + verifier si l'input ferme ces
// cote et fusion la va_d'envirnement si elle est legit.
int	first_parsing(t_all_struct *all)
{
	if (all->prompte->all_cmd_line == NULL)
		return (0);
	return (fusion_str_and_env(all->prompte->all_cmd_line));
}
