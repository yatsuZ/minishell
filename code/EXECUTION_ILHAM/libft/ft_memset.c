/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:46:17 by ilouacha          #+#    #+#             */
/*   Updated: 2022/12/22 18:46:17 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*z;

	z = (unsigned char *) s;
	while (n--)
		z[n] = c;
	return (s);
}

/*#include <strings.h>
#include <stdio.h>
int    main(void)
	{
	    char ptr[21] = "Hello world";

	    ft_memset(ptr,104,15);
	    printf("%s", ptr);
	}*/
