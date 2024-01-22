/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ouachani <ilouacha@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 05:11:49 by Ouachani          #+#    #+#             */
/*   Updated: 2022/11/29 19:14:51 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_in(char s1, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*dst;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	while (len >= i + 1 && ft_is_in(s1[len - i - 1], set))
		i++;
	len -= i * (len > 0) + 0;
	i = 0;
	while (s1[i] && ft_is_in(s1[i], set))
		i++;
	len -= i * (len > 0) + 0;
	dst = malloc(sizeof(*dst) * ((len > 0) * len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (s1[i] && ft_is_in(s1[i], set))
		i++;
	dst[len++] = 0;
	while (--len > 0)
		dst[len - 1] = s1[i + len - 1];
	return (dst);
}

/*int	main(void)
{
	char	set[40] = "voila enfin le travail compile !v";
	char	s1[40] = "v";

	printf("%s", s1);
	printf("res = %s\n", ft_strtrim("v", "voila enfin le travail compile !v"));
	return (0);
}*/
