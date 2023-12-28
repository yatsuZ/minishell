/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fusion_va.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 21:06:41 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/28 21:16:33 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Header/Minishell.h"

void	fusion_va(t_all_struct *all)
{
	printf("Je dois fusionais les vapour cela verifier si la key est legit sinon je transfomre les VA en str ou arg ou la fusion avec le noeud precedent\nsi la key est legit je dois la trouver dans len si il nexiste pas je remplace par rien et si il existe je dois remplacerpar la string qui lui corespond et je ne prend en compte que les seprateur je dois tout retramsfromer en node");
	show_all_va(all->all_va);
}
