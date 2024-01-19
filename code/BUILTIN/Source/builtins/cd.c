/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:56:19 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/19 15:54:10 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

// ajouter la va denv HOME si cd a pas dargument si ya pas de homme se deplace pas
// Si le répertoire spécifié commence par un caractère <slash>, le chemin est directement défini comme répertoire cible.
// Si le premier composant du répertoire est un point (.) ou deux points (..), des actions spécifiques sont effectuées. (.) == reprend de la ou es qu'on est actuellemnt .. retourne dans le dossier parent
// 1 verifier que le dossier ou fichier existe return 1
// 2 verifier que c'est un dossier return 1
// 3 verifier le droit d'execution effectuer la commande. return 1
// return 0 si tout se passe bien.
// metre a jour la cmd PWD.
int	exec_cd(t_execute *exe, t_all_struct **all)
{
	// char	*chemin;

	(void) all;
	show_execute(exe, 0);
	if (exe->arg[0] == NULL)
		printf("Y a pas darguemnt !!\n");
	else
		printf("Chemin = %s\n", exe->arg[0]);
	printf("Je dois faire la commande cd\n");
	return (0);
}
