/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constante.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:20:26 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/18 19:14:47 by yzaoui           ###   ########.fr       */
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

// SPECIAL
# define NOTHING 0 // RIEN
# define IDK 1 // Si je ne sais pas ce que c'est
# define SIGNAUX 2 // Si c'est un signal
// SEPERATOR
# define SEPERATOR 3 // Espace tab ou autre
# define NEW_LINE 4 // saut de ligne
//Guillmet
# define SINGLE_COTE 5 // '
# define DOUBLE_COTE 6// "
// REDIRECTION
# define R_IN 7 // <
# define R_OUT 8 // >
# define F_IN 9 // fichier apres < ou <<
# define F_OUT 10 // fichier apres > ou >>
# define R_IN_LIMIT 11 // <<
# define R_OUT_ADD 12 // >>
// PIP
# define PIP 13 // |
// ENVIROENEMNT
# define VA_ENV 14 // $[texte]
# define VA_SIGNAUX 15 // $?
// EXECUTABLE
# define EXECUTABLE 16 // Si c'est un fichier executable
// BUILTIN
# define ECHO 17
# define CD 18
# define PWD 19
# define EXPORT 20
# define UNSET 21
# define ENV 22
# define EXIT 23
# define OPTION 24 // option pares commande

#endif