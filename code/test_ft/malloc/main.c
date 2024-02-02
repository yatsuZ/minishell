/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:55:29 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/12 22:55:35 by yzaoui           ###   ########.fr       */
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

int	ft_calloc_verif(size_t nmemb, size_t size, void **pt)
{
	*pt = ft_calloc(nmemb, size);
	if (!*pt)
		return (1);
	return (0);
}

int	main(void)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	tmp = ft_calloc(4, sizeof(char));
	tmp[0] = 'O';
	tmp[1] = 'K';
	tmp[2] = '\n';
	tmp2 = ft_calloc(18446744073709551615UL, 18446744073709551615UL);
	printf("str(tmp) = %spointeur(tmp) = %p\ntmp2 = %p\n", tmp, tmp, tmp2);
	if (ft_calloc_verif(18446744073709551615UL, sizeof(char), (void **)&tmp3))
		printf("ERREUR de malloc tmp3\n");
	printf("TMP3 = %p\n", tmp3);
	return (free(tmp), free(tmp2), free(tmp3), 0);
}