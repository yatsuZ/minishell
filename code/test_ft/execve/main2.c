/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:54:36 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/07 14:02:38 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	printf("Je suis le fichier main2.c et je viens detre activer\n");
	while (i < argc)
	{
		printf("arg[%d] = %s\n", i, argv[i]);
		i++;
	}
	return (0);
}