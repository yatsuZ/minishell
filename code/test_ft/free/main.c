/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:06:43 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/05 15:00:46 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	(void)	argv;
	(void)	argc;
	void	*ptr_dynamique;
	// char	*ptr_fix = "Memoire Fix\n";

	// Allocation de mémoire pour un entier
	ptr_dynamique = malloc(50);
	free(ptr_dynamique);
	// if (argc)
	// 	free(ptr_fix);
	return (0);
}
