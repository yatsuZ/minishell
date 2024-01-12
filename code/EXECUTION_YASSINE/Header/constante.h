/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constante.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:20:26 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/11 20:14:13 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTE_H
# define CONSTANTE_H

// BOOLEAN CONSTANTE
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

#endif