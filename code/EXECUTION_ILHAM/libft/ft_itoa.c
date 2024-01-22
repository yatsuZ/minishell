/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ouachani <ilouacha@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 05:33:15 by Ouachani          #+#    #+#             */
/*   Updated: 2022/12/17 18:10:35 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_nbr_len(long int m)
{
	size_t	len;

	len = 1;
	while (m >= 10)
	{
		m /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t			len;
	long int		m;
	char			*s;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	m = (long int)((-(n < 0) + (n >= 0)) * n);
	len = ft_nbr_len(m);
	s = (char *)malloc(sizeof(char) * (len + (n < 0) + 1));
	if (!s)
		return (NULL);
	s[len + (n < 0)] = '\0';
	if (n < 0)
		s[0] = '-';
	m = (-(n < 0) + (n >= 0)) * n;
	while (len > 0)
	{
		s[--len + (n < 0)] = '0' + (m % 10);
		m /= 10;
	}
	return (s);
}
