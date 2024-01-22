/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:04:41 by ilouacha          #+#    #+#             */
/*   Updated: 2022/12/09 17:15:45 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*des;
	const unsigned char	*sr;
	size_t				i;

	des = (unsigned char *) dest;
	sr = (unsigned char *) src;
	i = 0;
	if (!sr && !des)
		return (NULL);
	if (des <= sr)
	{
		while (i < n)
		{
			des[i] = sr[i];
			i++;
		}
	}
	else
	{
		while (n--)
			des[n] = sr[n];
	}
	return (dest);
}
