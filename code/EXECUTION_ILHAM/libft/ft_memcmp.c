/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:10:38 by ilouacha          #+#    #+#             */
/*   Updated: 2022/12/09 17:20:45 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*z1;
	unsigned char		*z2;

	z1 = (unsigned char *) s1;
	z2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (z1[i] != z2[i])
			return (z1[i] - z2[i]);
		i++;
	}
	return (0);
}
