/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:10:12 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/12 22:56:27 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./struct.h"

void	get_invite_de_comande(void);

// Fonction utile

int		ft_strcpm(char *s1, char *s2);
int		ft_calloc_verif(size_t nmemb, size_t size, void **pt);

// Structure

int		init_all(t_all_struct **res);

// Fonction Inutile

void	show_color(void);

#endif