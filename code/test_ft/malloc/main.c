/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:55:29 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/05 14:03:56 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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

int	main(void)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_calloc(4, sizeof(char));
	tmp[0] = 'O';
	tmp[1] = 'K';
	tmp[2] = '\n';
	tmp2 = ft_calloc(18446744073709551615UL, 18446744073709551615UL);
	printf("str(tmp) = %spointeur(tmp) = %p\ntmp2 = %p\n", tmp, tmp, tmp2);
	return (free(tmp), free(tmp2), 0);
}