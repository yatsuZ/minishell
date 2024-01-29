/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:25:28 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/29 16:08:56 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*cast;

	if (!s)
		return (NULL);
	cast = (unsigned char *)s;
	while (n--)
		cast[n] = c;
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pt;
	size_t	totalsize;

	if (!nmemb && !size)
		return (NULL);
	else if (!nmemb || !size)
		return (malloc(0));
	totalsize = size * nmemb;
	if (totalsize / size != nmemb)
		return (NULL);
	pt = malloc(totalsize);
	if (!pt)
		return (NULL);
	ft_memset(pt, 0, totalsize);
	return (pt);
}
