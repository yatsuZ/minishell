/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:15:55 by ilouacha          #+#    #+#             */
/*   Updated: 2022/11/25 11:33:32 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (src[i] != '\0')
		i++;
	len = i;
	if (size == 0)
		return (len);
	else if (size == 1)
	{
		dest[0] = '\0';
		return (len);
	}
	i = 0;
	while ((src[i] != '\0') && (i < (size - 1)))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}
/*#include <stdio.h>
#include <bsd/string.h>

int	main (void)
{
	char src[50] = "Bonjour demain l'evaluation";
	char 	dest[50] = "";//"Je vais bien";
	unsigned int	size = 0;
	printf("%d", ft_strlcpy(dest, src, size));
	printf("%s\n", dest);

	char src1[50] ="Bonjour demain l'evaluation";
	char 	dest1[50] = "";//"Je vais bien";
	printf("%ld", strlcpy(dest1, src1, size));
	printf("%s\n", dest1);
}*/
