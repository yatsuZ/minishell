/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:34:55 by ilouacha          #+#    #+#             */
/*   Updated: 2022/12/22 18:29:09 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			i;
	int			len_s1;
	char		*ret;

	if (!s1 || !s2)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	len_s1 = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	len_s1 = i;
	while (s2[i - len_s1])
	{
		ret[i] = s2[i - len_s1];
		i++;
	}
	ret[i] = '\0';
	return ((char *)ret);
}

/*#include <stdio.h>
int	main(int ac, char **av)
{
	//void ac;

	//printf("%d\n", total_size(ac, av, "tt"));
	if (ac != 0)
		printf("%s\n", ft_strjoin(av[0], av[1]));
}*/
