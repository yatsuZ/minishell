/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:59:51 by ilouacha          #+#    #+#             */
/*   Updated: 2022/12/09 17:04:12 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_t;
	unsigned char	*src_t;
	size_t			i;

	dest_t = (unsigned char *) dest;
	src_t = (unsigned char *) src;
	if (n == 0)
		return (dest);
	if (!dest && !src)
		return (NULL);
	i = 0;
	while (n--)
	{
		dest_t[i] = src_t[i];
		i++;
	}
	return (dest);
}
