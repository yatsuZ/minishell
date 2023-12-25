/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:10:12 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/25 23:06:00 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./struct.h"

// Parsing
int		get_all_input(t_prompt *promp);
int		parsing(t_all_struct *all);
int		first_parsing(t_all_struct *all);
int		fusion_str_and_env(t_node *tete_str);

// Fonction de fin

void	end(t_all_struct *all);

// Fonction utile

int		ft_strcpm(char *s1, char *s2);
int		ft_calloc_verif(size_t nmemb, size_t size, void **pt);
size_t	ft_strlen(const char *cha);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strcut(const char *s, size_t start, size_t end);
int		is_a_legit_va_env(char *str);
int		type_of_str(char *s);
int		is_str_or_cote(int type);
void	fusion_node(t_node *n, int new_type);
char	*ft_strjoin(char const *s1, char const *s2);

// Structure

int		init_all(t_all_struct **res);
int		init_prompt(t_prompt **promp);
int		init_node(t_node **n, char *str);
void	free_all(t_all_struct *all);
void	free_prompt(t_prompt *promp);
void	free_node(t_node *n);
void	free_all_node(t_node *tete);
int		add_node(t_node *previous_n, char *str);
int		add_last_node(t_node **tete, char *str);

// Fonction Inutile

void	show_color(void);
void	put_color_txt(int color);
void	show_prompt(t_prompt *promp);

#endif