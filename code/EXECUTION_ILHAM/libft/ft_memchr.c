/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:17:42 by ilouacha          #+#    #+#             */
/*   Updated: 2022/11/30 09:40:00 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*z;

	z = (unsigned char *) s;
	while (n--)
	{
		if (*z == (unsigned char)c)
			return (z);
		z++;
	}
	return (NULL);
}
