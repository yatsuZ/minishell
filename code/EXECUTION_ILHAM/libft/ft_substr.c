/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ouachani <ilouacha@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 22:35:09 by ilouacha          #+#    #+#             */
/*   Updated: 2022/12/16 15:34:07 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	len_s;
	unsigned int	i;
	char			*z;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if ((start > len_s) || (len_s == 0))
		return (ft_strdup(""));
	i = 0;
	while ((i < len) && (i < (len_s - start)))
		i++;
	z = malloc(sizeof(*z) * (i + 1));
	if (!z)
		return (NULL);
	i = 0;
	while ((i < len) && (i < (len_s - start)))
	{
		z[i] = s[start + i];
		i++;
	}
	z[i] = '\0';
	return (z);
}
