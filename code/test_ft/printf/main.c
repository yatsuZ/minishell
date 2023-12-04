/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 23:27:11 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/04 23:41:34 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define DEFAUT 0
#define VERT 1
#define BLEU 2
#define ROUGE 3

void put_color(int index) {
	if (index == 1)
		printf("\033[1;32m"); // Vert
	else if (index == 2)
		printf("\033[1;34m"); // Bleu
	else if (index == 3)
		printf("\033[1;31m"); // Rouge
	else if (index == 4)
		printf("\033[1;33m"); // Jaune
	else if (index == 5)
		printf("\033[1;35m"); // Viollet
	else if (index == 6)
		printf("\033[1;36m"); // Cyan
	else if (index == 0)
		printf("\033[0m"); // Default
}

int main() {
	int entier = 42;
	float flottant = 3.14159;
	char caractere = 'A';
	char chaine[] = "Bonjour";
	long long long_entier = 1234567890LL;
	// 3.2. Chaîne de format
	put_color(1);
	printf("3.2. Chaîne de format :\n");
	printf("Entier en décimal : %d\n", entier);
	printf("Entier en Exadcimal : %X\n", entier);
	printf("Flottant en notation scientifique : %e\n", flottant);
	printf("Caractère : %c\n", caractere);
	printf("Chaine de caractères : %s\n", chaine);
	printf("Entier long : %lld\n", long_entier);
	printf("Pointeur = %p\n", chaine);
	// 3.3. Caractère d'attribut
	put_color(2);
	printf("\n3.3. Caractère d'attribut :\n");
	printf("Entier avec signe : %+d\n", entier);
	printf("Entier positif avec espace : % d\n", entier);
	printf("Caractère en octal : %o\n", caractere);
	// 3.4. Largeur de champ
	put_color(3);
	printf("\n3.4. Largeur de champ :\n");
	printf("Entier sur 20 caractères : %20d.\n", entier);
	printf("Chaine sur 25 caractères : %25s.\n", chaine);
	// 3.5. Précision
	put_color(0);
	printf("\n3.5. Précision :\n");
	printf("Flottant avec 2 décimales : %.2f\n", flottant);
	// 3.6. Modificateur de longueur
	put_color(4);
	printf("\n3.6. Modificateur de longueur :\n");
	printf("Entier long : %ld\n", (long)entier);
	printf("Entier long long : %lld\n", long_entier);
	// 3.7. Indicateur de conversion
	put_color(5);
	printf("\n3.7. Indicateur de conversion :\n");
	printf("Entier en hexadécimal : %x\n", entier);
	// 4. Conformité
	put_color(6);
	printf("\n4. Conformité :\n");
	entier = printf("Le programme est conforme aux spécifications.\n");
	printf("La derniere ligne à %d caractere affiche.\n", entier);
	return (put_color(0), 0);
}
