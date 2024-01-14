/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpm_last_nwl.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:12:16 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/14 14:22:29 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

// doit verifier aue tout est bon prendre en compte juste le dernier \n et remplace le va par leur val si va on
int	ft_strcpm_last_nwl(char *lmt, char **str, char *history, int va_on)
{
	(void)	history;

	printf("doit faire un seperator de chaque \\n et $ pour chaque str je dois comparer avec lmt puis si est bn je surpimer le reste sinon je remplace par sa va\n");
	if (ft_strcpm(lmt, *str))
		return (1);
	if (va_on)
		printf("transforme to va\n");
	return (0);
}