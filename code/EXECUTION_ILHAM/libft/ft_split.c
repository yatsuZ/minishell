/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:48:13 by ilouacha          #+#    #+#             */
/*   Updated: 2022/12/22 18:48:13 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	count_word(char const *s, char c)
{
	int				i;
	unsigned int	nbr_word;
	int				start_word;

	nbr_word = 0;
	i = -1;
	start_word = 0;
	while (s[++i])
	{
		if (s[i] != c && start_word == 0)
		{
			start_word = 1;
			nbr_word++;
		}
		else if (s[i] == c)
			start_word = 0;
	}
	return (nbr_word);
}

static char	**free_all(char **array, int k)
{
	int	i;

	i = -1;
	while (++i <= k)
		free(array[i]);
	free(array);
	return (NULL);
}

static char	**ft_under_split(char const *s, char c, char **splitted)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	j = -1;
	k = 0;
	while (++i <= (int)ft_strlen(s))
	{
		if ((s[i] != c) && (j < 0))
		{
			j = i;
		}
		else if (((s[i] == c) || (s[i] == '\0')) && (j >= 0))
		{
			splitted[k] = ft_substr(s, j, i - j);
			if (!splitted[k])
				free_all(splitted, k);
			k++;
			j = -1;
		}
	}
	splitted[k] = NULL;
	return (splitted);
}

char	**ft_split(char const *s, char c)
{
	char			**splitted;

	if (!s)
		return (NULL);
	splitted = (char **)malloc(((count_word(s, c)) + 1) * sizeof(char *));
	if (!splitted)
		return (NULL);
	splitted = ft_under_split(s, c, splitted);
	return (splitted);
}

/*int    main(void)
{
  char const *s4 = "llorem ipsum dolor sit amet, consectetur adipiscing elit.\
	Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing \
	nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula \
	massa, varius a, semper congue, euismod non, mi.orem ipsum dolor sit amet,\
	consectetur adipii.i";
  char    c4 = 'i';
  unsigned int    r;
  char    **tib;

  r = 0;
  tib = ft_split(s4, c4);    
  while (r < count_word(s4, c4))
  {
	printf("%s\n", tib[r]);
	r++;
  }
  return (0);
}*/
/*printf("%u\n", count_word(s, c));*/
