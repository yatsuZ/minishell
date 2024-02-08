/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:10:12 by yzaoui            #+#    #+#             */
/*   Updated: 2024/02/08 01:56:11 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./struct.h"

extern int	g_signal;

// Fonctions pour l'execution du shell
char		*get_path_var(t_env *env);
char		**get_paths_from_environment(char *path);
int			ft_strncmp(const char *s1, const char *s2, const size_t n);
void		free_table(char **table);
void		free_all_data(t_all_struct *all, int code2);
int			fd_open(t_redirecte *tmp);
void		redirect_pipe(t_all_struct *all, t_execute *exe, int i);
int			redirect(t_execute *exe, int i);
void		close_fd_child(t_execute *exe);
void		close_fd(int *fd);
void		get_here_doc_fd(t_redirecte *rd);
int			child_process(t_all_struct **all, t_execute *exe, int i);
int			init_data(t_all_struct *all);
int			execute(t_all_struct **all);

// Parsing
char		*get_all_input(t_prompt *promp);
int			parsing(t_all_struct *all);
int			first_parsing(t_all_struct *all);
int			fusion_str_and_env(t_node *tete_str);
void		error_parsing(int iderr);
int			del_cote(t_node *av, t_node *entre, int option);
int			cmd_or_arg(t_node *n, t_node *p, int o);
t_node		*only_str(t_node *n, t_type_input type);
// find
int			find_cote_and_va(t_node *n, int previous_type);
int			find_all_rd_and_pip(t_prompt *p);
void		find_cmd_and_arg(t_node *n, t_node *prev, int option);
// fusion
void		fusion_cote(t_node *all);
void		fusion_va(t_env *all_va, t_node *present, \
t_node *previous, int status);

// Execution
void		prompte_to_execute(t_all_struct *all);

// builtin
t_builtin	find_builtin(char *str);
int			exec_builtin(t_execute *exe, t_all_struct **all, \
t_builtin built);
int			exec_unset(t_execute *exe, t_all_struct **all);
int			exec_pwd(t_execute *exe, t_all_struct **all);
int			exec_export(t_execute *exe, t_all_struct **all);
int			exec_exit(t_execute *exe, t_all_struct **all);
int			exec_env(t_execute *exe, t_all_struct **all);
int			exec_echo(t_execute *exe, t_all_struct **all);
int			exec_cd(t_execute *exe, t_all_struct **all);

// HEREDOC
void		get_all_rinlimit(t_execute *all_exe, t_all_struct *all);

// Fonction de fin
void		end(t_all_struct *all);

// Fonction utile

int			ft_strcpm(char *s1, char *s2);
size_t		ft_strlen(const char *cha);
char		*ft_strdup(const char *s, int *err);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strcut(const char *s, size_t start, size_t end, int *err);
int			is_a_legit_va_env(char *str);
int			type_of_str(char c);
void		fusion_node(t_node *n, int new_type, int *err);
char		*ft_strjoin(char const *s1, char const *s2, int *err);
size_t		is_separator(char *str, size_t i);
int			str_to_node(char *str, t_node **res, int *err);
char		*get_value(t_env *all_va, char *key, int status);
t_node		*no_define_to_node(t_node **nodef, t_node **prev, int *err);
size_t		is_space(char *str, size_t i);
t_boolean	have_space(char *s, size_t i);
void		index_update(t_node *n);
t_node		*no_define_to_node2(char *str, size_t i_start, \
size_t i_end, int *err);
int			remplace_node(t_node **old, t_node *new, \
t_node **previous, t_node *next);
void		del_next_node(t_node *n);
void		free_2str(char **s1, char **s2);
void		str_add(char **s, char *s2, int free);
void		str_change_env(char **str, t_env *all_env, int status);
t_boolean	have_nwl(char *s, size_t i);
void		str_to_node_nwl(char *str, t_node **res, int *err);
char		*int_to_str(int nbr);
void		change_or_add_va(t_env **all_env, char *key, char *value, int show);
int			print_fd(char *str, int fd);
long long	is_numeric2(char *str, size_t i, int *err);
t_boolean	key_exist(t_env *env, char *str);
char		*get_first_arg_no_null(char **argv, size_t argc, size_t i);
void		free_tab(char ***tableau);
char		**ft_split(const char *s, char c);
char		*ft_strchr(const char *s, int c);
char		*find_cmd2(char **all_path, char *cmd, t_all_struct **all);
void		change_va_undescore(t_execute *exe, t_env **env);
void		update_shlvl(t_env *tete, int err, long long shlvl);
int			good_condition_fusion_rd_with_pip(t_node *n, t_node *next, \
int *nbr_pip);

// Structure
int			init_all(t_all_struct **res, char **env);
int			init_prompt(t_prompt **promp);
int			init_node(t_node **n, char *str);
void		free_all(t_all_struct *all);
void		free_prompt(t_prompt *promp);
void		free_node(t_node *n);
void		free_all_node(t_node *tete);
int			add_node(t_node *previous_n, char *str);
int			add_last_node(t_node **tete, char *str, int *err);
int			init_all_va(t_env **all_va, char **arg_env);
void		free_all_va(t_env *all_va);
t_execute	*init_execute(char *cmd, char **arg, t_redirecte *rd, int *err);
void		free_execute(t_execute *exe);
t_redirecte	*init_redirecte(t_node *f_n, t_type_input t_rd, int *err);
void		free_redirection(t_redirecte *rd);
int			add_rd(t_redirecte **all_rd, t_type_input t_rd, t_node *f_n);
void		free_env(t_env **env);
void		update_env(t_all_struct **all);

// Fonction Inutile

void		show_color(void);
void		put_color_txt(int color);
void		show_prompt(t_prompt *promp);
void		show_type_input(t_type_input ti);
void		show_all_va(t_env *env);
void		show_node(t_node *tmp);
void		show_execute(t_execute *exe, size_t i);
void		show_tab(char **t);

#endif