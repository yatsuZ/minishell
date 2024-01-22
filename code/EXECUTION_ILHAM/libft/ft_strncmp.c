/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:17:23 by ilouacha          #+#    #+#             */
/*   Updated: 2022/12/22 18:49:38 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*z1;
	unsigned char	*z2;

	z1 = (unsigned char *) s1;
	z2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	i = 0;
	while ((i < (n - 1)) && (z1[i] || z2[i]))
	{
		if (z1[i] != z2[i])
		{
			break ;
		}
		i++;
	}
	return (z1[i] - z2[i]);
}
