/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:10:12 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/03 01:19:53 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./struct.h"

// Parsing
char		*get_all_input(t_prompt *promp);
int			parsing(t_all_struct *all);
int			first_parsing(t_all_struct *all);
int			fusion_str_and_env(t_node *tete_str);
void		error_parsing(int iderr);
int			del_cote(t_node *av, t_node *entre, int option);
int			cmd_or_arg(t_node *n, t_node *p, int o);
// find
int			find_cote_and_va(t_node *n, int previous_type);
int			find_all_rd_and_pip(t_prompt *p);
void		find_cmd_and_arg(t_node *n, t_node *prev, int option);
// fusion
void		fusion_cote(t_node *all);
void		fusion_va(t_env *all_va, t_node *present, t_node *previous);

// Fonction de fin

void		end(t_all_struct *all);

// Fonction utile

int			ft_strcpm(char *s1, char *s2);
int			ft_calloc_verif(size_t nmemb, size_t size, void **pt);
size_t		ft_strlen(const char *cha);
char		*ft_strdup(const char *s);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strcut(const char *s, size_t start, size_t end);
int			is_a_legit_va_env(char *str);
int			type_of_str(char c);
void		fusion_node(t_node *n, int new_type);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		is_separator(char *str, size_t i);
void		str_to_node(char *str, t_node **res);
char		*get_value(t_env *all_va, char *key);
t_node		*no_define_to_node(t_node **nodef, t_node **prev);
size_t		is_space(char *str, size_t i);
t_boolean	have_space(char *s, size_t i);
void		index_update(t_node *n);
t_node		*no_define_to_node2(char *str, size_t i_start, size_t i_end);
void		remplace_node(t_node **old, t_node *new, \
t_node **previous, t_node *next);
void		del_next_node(t_node *n);

// Structure

int			init_all(t_all_struct **res, char **env);
int			init_prompt(t_prompt **promp);
int			init_node(t_node **n, char *str);
void		free_all(t_all_struct *all);
void		free_prompt(t_prompt *promp);
void		free_node(t_node *n);
void		free_all_node(t_node *tete);
int			add_node(t_node *previous_n, char *str);
int			add_last_node(t_node **tete, char *str);
int			init_all_va(t_env **all_va, char **arg_env);
void		free_all_va(t_env *all_va);

// Fonction Inutile

void		show_color(void);
void		put_color_txt(int color);
void		show_prompt(t_prompt *promp);
void		show_type_input(t_type_input ti);
void		show_all_va(t_env *env);
void		show_node(t_node *tmp);

#endif