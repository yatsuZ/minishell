/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:42:58 by ilouacha          #+#    #+#             */
/*   Updated: 2022/12/21 13:52:25 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	if ((!dst || !src) && (size == 0))
		return (0);
	while (dst[i] && (i < size))
		i++;
	j = i + ft_strlen(src);
	dst += i;
	if (size != i)
	{
		while (*src)
		{
			if (size > i + 1)
			{
				*dst++ = *src;
				size--;
			}
			src++;
		}
		*dst = 0;
	}
	return (j);
}

/*int	main(void)
{
	char	*dest1;
	char	*dest2;

	dest1 = (char *)malloc(sizeof(*dest1) * 15);
	dest2 = (char *)malloc(sizeof(*dest2) * 15);
	memset(dest1, 'r', 15);
	memset(dest2, 'r', 15);
	write(1, dest1, 15);
	printf("\nstrlcat : %lu\n\n", strlcat(dest1, \
	"lorem ipsum dolor sit amet", 5));
	write(1, dest2, 15);
	printf("\nft_strlcat : %lu\n\n", ft_strlcat(dest2, \
	"lorem ipsum dolor sit amet", 5));
}

#include <stdio.h>
#include <bsd/string.h>
int main (void)
{
	char	src[50] = "Bonjour !!";
	char	dest[50] = "enfin ! Bientot fini !";
	size_t size = 17;

	printf("%ld\n", ft_strlcat(dest, src, size));
	printf("%s\n", dest);

	char	dest1[50] = "enfin ! Bientot fini !";
	printf("%ld\n", strlcat(dest1, src, size));
	printf("%s\n", dest1);
}*/
