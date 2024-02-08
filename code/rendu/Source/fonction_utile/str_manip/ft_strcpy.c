/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:13:08 by yzaoui            #+#    #+#             */
/*   Updated: 2024/02/08 01:31:08 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Header/Minishell.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (!dest || !src)
		return (0);
	i = 0;
	while (src[i] && (size > 0 && i < (size - 1)))
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size)
		dest[i++] = '\0';
	return (ft_strlen((char *)src));
}

char	*ft_strdup(const char *s, int *err)
{
	char	*ptr;
	size_t	len;
	char	*str;

	if (!s || *err)
		return (NULL);
	str = (char *) s;
	len = ft_strlen(str) + 1;
	ptr = ft_calloc(len, sizeof(char));
	if (!ptr)
		return (*err = 1, NULL);
	ft_strlcpy(ptr, str, len);
	return (ptr);
}

char	*ft_strcut(const char *s, size_t start, size_t end, int *err)
{
	char	*ptr;
	size_t	len;
	char	*str;

	if (!s || *err)
		return (NULL);
	str = (char *) s;
	len = end - start + 1;
	ptr = ft_calloc(len, sizeof(char));
	if (!ptr)
		return (*err = 1, NULL);
	ft_strlcpy(ptr, str + start, len);
	return (ptr);
}
