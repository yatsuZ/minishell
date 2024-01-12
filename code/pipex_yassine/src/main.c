/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:59:46 by yatsu             #+#    #+#             */
/*   Updated: 2024/01/09 10:22:37 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipex	*pipex;

	if (ac < 5 || !av[1] || !av[2] || !av[3] || !av[4])
		return (ft_printf("ERREUR\n\til faut 5 arg et non NULL!!!\n\n"), 0);
	pipex = ft_init_pipex(av, env);
	if (!pipex || pipex->error)
		return (error_gestion(pipex));
	exec(pipex);
	return (free_pipex(pipex), 0);
}
