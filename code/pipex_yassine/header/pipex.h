/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:02:50 by yatsu             #+#    #+#             */
/*   Updated: 2024/01/19 23:28:06 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "./struct.h"

// La ou j'apelle mes fonction

// Init structure

t_cmd	*ft_init_cmd(char *argv, char **env, int *error);
t_pipex	*ft_init_pipex(char **argv, char **env);
void	free_cmd(t_cmd *cmd);
void	free_tab(char **table);
char	*get_path_cmd(char **env, char *cmd, int *error);
void	free_pipex(t_pipex *pipex);

// PIP

char	*local_path(char *cmd, int *error, int param);
void	exec(t_pipex *p);

// ERREUR GESTION

int		error_gestion(t_pipex *p);
void	erreur_dans_fork(t_pipex *p, int error);

#endif