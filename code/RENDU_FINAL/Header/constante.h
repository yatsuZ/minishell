/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constante.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:20:26 by yzaoui            #+#    #+#             */
/*   Updated: 2024/02/09 09:57:08 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTE_H
# define CONSTANTE_H

# define MAXLINE 1024
# define SHE 10
# define HER 11
# define IGN 12

typedef enum e_boolean
{
	FALSE,
	TRUE
}	t_boolean;

// COLOR CONSTANTE
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

////// TYPE INPUT
// si je nai pas encore categoriser les string
// \\ si seul ou suis un caractere speciaux
// char * si il fais partie d'un ensemble de string
// Espace tab ou autre
// *char fichier executable = un chemin = Premier text
// **char Tout ce qui suit un cmd
// $ voir la syntaxe autorise des variable d'env
// $? retourne la valeur retour (le signal)
// ' les VA d'ENV de ne marche pas doit etre fermé
// " les VA d'ENV marche doit etre fermé contenue = string
// < Redirection d'entre
// > Redirection de sortie
// << fais un heardock (le plus dur)
// > Redirection de sortie
// *char ce aui suit une R
// *char qui suit un R_IN_LIMIT
// | doit faire une redirection de sortie principal quoi qu'il arrive
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