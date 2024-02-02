/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:50:27 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/07 15:54:56 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>

int main() {
	FILE *file = fopen("non_existent_file.txt", "r");
	if (file == NULL)
		perror("Mais frero ta fais une conneire ?");
	return 0;
}
