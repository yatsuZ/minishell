/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constante.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:20:26 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/19 16:37:07 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTE_H
# define CONSTANTE_H

// BOOLEAN CONSTANTE
# define FALSE 0
# define TRUE 1

// COLOR CONSTANTE
# define EMPTY_COLOR 0
# define ROUGE 1
# define VERT 2
# define JAUNE 3
# define BLEU 4
# define MAGENTA 5
# define CYAN 6
# define BLANC 7

////// TYPE INPUT

# define SEPERATOR 0 // Espace tab ou autre
# define CMD 1 // Si c'est un fichier executable
# define ARGUMENT 2 // Tout ce qui suit un cmd
// ENVIROENEMNT
# define VA_ENV 3 // $[texte]
# define VA_RETOUR 4// $?
//Guillmet
# define SINGLE_COTE 5 // '
# define DOUBLE_COTE 6// "
// REDIRECTION
# define R_IN 7 // <
# define R_OUT 8 // >
# define R_IN_LIMIT 9 // <<
# define R_OUT_ADD 10 // >>
# define F_RD 11 // fichier de redirevtion (sortie ou entre)
// PIP
# define PIP 12 // |

#endif