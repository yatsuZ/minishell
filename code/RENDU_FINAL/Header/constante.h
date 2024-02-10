/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constante.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:20:26 by yzaoui            #+#    #+#             */
/*   Updated: 2024/02/10 16:56:53 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTE_H
# define CONSTANTE_H

# define MAXLINE 1024
# define SHE 10
# define HER 11
# define IGN 12
# define HERDOC 13

typedef enum e_boolean
{
	FALSE,
	TRUE
}	t_boolean;

typedef enum e_color
{
	EMPTY_COLOR ,
	ROUGE ,
	VERT ,
	JAUNE ,
	BLEU ,
	MAGENTA ,
	CYAN ,
	BLANC
}	t_color;

typedef enum e_type_input
{
	NON_DEFINI,
	STR,
	SINGLE_COTE ,
	DOUBLE_COTE ,
	SEPARATOR ,
	CMD ,
	ARG ,
	VA_ENV ,
	VA_RETOUR ,
	R_IN ,
	R_OUT ,
	R_IN_LIMIT ,
	R_OUT_ADD ,
	F_RD ,
	F_RD2 ,
	PIP
}	t_type_input;

typedef enum e_builtin
{
	NON_BUILTIN,
	CD,
	ECHO,
	ENV,
	EXIT,
	EXPORT,
	PWD,
	UNSET
}	t_builtin;

#endif