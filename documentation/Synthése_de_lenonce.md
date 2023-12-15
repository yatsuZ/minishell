# Synthése de l'énoncé du projet Minishell

## Sommaire

- [Synthése de l'énoncé du projet Minishell](#synthése-de-lénoncé-du-projet-minishell)
	- [Sommaire](#sommaire)
	- [Introduction](#introduction)
	- [Instructions Communes](#instructions-communes)
	- [Partie Obligatoire](#partie-obligatoire)
		- [Rendu, Fonctions Externes Autorisées et Description](#rendu-fonctions-externes-autorisées-et-description)
		- [Ce que le programme Minishell doit être capable de faire](#ce-que-le-programme-minishell-doit-être-capable-de-faire)
		- [Partie Bonus](#partie-bonus)
	- [Conclusion](#conclusion)
		- [Autre document](#autre-document)
		- [La cohésion d'équipe est cruciale.](#la-cohésion-déquipe-est-cruciale)

## Introduction

Dans ce préambule, nous sommes transportés à une époque où les informaticiens, confrontés à la nécessité de communiquer avec les machines, utilisaient le langage binaire.

Bien que cette méthode fût efficace, elle demeurait complexe. C'est dans ce contexte qu'émergèrent les logiciels, agissant comme des intermédiaires entre l'humain et la machine, communément appelés systèmes d'exploitation.

Aujourd'hui, notre défi résonne avec cette histoire. Nous sommes appelés à créer notre propre programme,
**un mini-shell simplifié** qui servira d'interface entre l'humain et la machine.

Il s'agit là de l'un des projets les plus complexes de l'école 42, à réaliser en duo. Découvrons ensemble les consignes pour mener à bien ce projet. 🚀

## Instructions Communes

Les projet de 42 suit des règles strictes et communes, qui constituent les bases fondamentales des projets.
Appliquer ces directives avec précision pour assurer la réussite du projet :

1. **Langage de Programmation :** Le projet doit être codé en langage C.

2. **Norme de Codage :** Le code doit être conforme à la norme 42.

3. **Stabilité du Code :** Les fonctions ne doivent pas s'arrêter de manière inattendue, excluant les erreurs telles que la segmentation, les erreurs de bus, les doubles free, etc. Évitez les comportements non définis.

4. **Gestion de la Mémoire :** Évitez les fuites de mémoire. Veillez à une gestion appropriée des allocations et des désallocations.

5. **Compilation avec Makefile :** Si un Makefile est utilisé, compilez avec la commande/compilateur "cc" et les flags "-Wall, -Wextra, -Werror". Assurez-vous de ne pas avoir de relink.

6. **Makefile Complet :** Le Makefile doit inclure au moins les règles $(NAME), all, clean, fclean, et re.

7. **Bonus (le cas échéant) :** Si des fonctionnalités bonus sont ajoutées, créez une règle spécifique dans le Makefile pour leur compilation. Utilisez des fichiers distincts si nécessaire.

8. **Libft (si utilisée) :** Si la libft est utilisée, assurez-vous de la compiler avec votre propre Makefile.

9. **Tests Recommandés :** Il est fortement conseillé d'utiliser un programme de test pour valider le bon fonctionnement de votre minishell.

Ces instructions sont cruciales pour garantir la qualité et la stabilité du projet. Suivez-les attentivement pour assurer le succès et la validation du projet.

## Partie Obligatoire

### Rendu, Fonctions Externes Autorisées et Description

| Règle               |                                |
|---------------------|--------------------------------|
| Nom du programme    | minishell                      |
| Fichiers à rendre   | Makefile, *.c, *.h             |
| Arguments           | AUCUN                          |
| [LIBFT](https://github.com/yatsuZ/LIBFT) | Autorisée              |
| Description         | Écrire un shell                |
| Fonctions Externes Autorisées | [Fichier contenant la liste des Fonction Externe autorisées](./Documentation.md#liste-de-toute-les-fonction-externe-autorisé) |

### Ce que le programme Minishell doit être capable de faire

1. **Afficher une invite :** Le shell doit afficher une invite lorsqu'il attend une nouvelle commande.

2. **Historique de travail :** Le shell doit maintenir un historique des commandes précédemment exécutées.

3. **Recherche et exécution d'exécutables :** Le programme doit rechercher et lancer le bon exécutable, en fonction de la variable PATH ou en utilisant un chemin relatif ou absolu. (Verifier si on a aussi les droit d'exécution).

4. **Gestion des signaux :** Limiter l'utilisation d'une seule variable globale pour indiquer un signal reçu, sans accéder aux principales structures de données.

5. **Interprétation des guillemets :** Ne pas interpréter les guillemets non fermés ou les caractères spéciaux qui ne sont pas requis par le sujet. Les guillemets simples ('') empêchent l'interprétation des métacaractères, tandis que les guillemets doubles ("") empêchent l'interprétation des métacaractères à l'exception de $.

6. **Implémentation des redirections :** 
   - `<` : Redirection de l'entrée.
   - `>` : Redirection de la sortie.
   - `<<` : Lecture de l'entrée jusqu'à un délimiteur.
   - `>>` : Redirection de la sortie en mode ajout.

7. **Implémentation du PIPE :** Utilisation du caractère `|` pour connecter la sortie de chaque commande dans le pipeline à l'entrée de la commande suivante.

8. **Gestion des variables d'environnement :** Prise en charge des variables d'environnement ($ suivi d'une séquence de caractères) avec extension de leur valeur.

9. **Gestion de `$?` :** Prise en charge de `$?` qui s'étend au statut de sortie du dernier pipeline de premier plan.

10. **Gestion des signaux Ctrl-C, Ctrl-D, et Ctrl-\ :**
    - En mode interactif :
      - Ctrl-C affiche une nouvelle invite sur une nouvelle ligne.
      - Ctrl-D quitte le shell.
      - Ctrl-\ ne fait rien.

11. **Éléments intégrés :** Notre programme minishell doit implémenter les éléments suivants :
    - `echo` avec l'option -n.
    - `cd` avec seulement un chemin relatif ou absolu.
    - `pwd` sans options.
    - `export` sans options.
    - `unset` sans options.
    - `env` sans options ni arguments.
    - `exit` sans options.

12. **Fuites de mémoire :** Il ,ne doit pas avoir de fuite de memoir à l'exception de la fonction readline() peut provoquer des fuites de mémoire. Vous n’êtes pas obligé de les réparer.

13. **Limites :** Vous devez vous limiter à la description du sujet. Tout ce qui n’est pas demandé n’est pas obligatoire. En cas de doute, [bash](https://www.gnu.org/savannah-checkouts/gnu/bash/manual/) peut être utilisé comme référence.

### Partie Bonus

1. **Opérateurs && et || avec des parenthèses :** Implémentation des opérateurs logiques && et || avec prise en charge des parenthèses pour définir les priorités.

2. **Caractères génériques * pour le répertoire de travail actuel :** Les caractères génériques * devraient fonctionner pour le répertoire de travail actuel, permettant des sélections de fichiers basées sur des modèles.

Assurez-vous que ces fonctionnalités bonus sont ajoutées avec soin, en prenant en compte les exigences de la partie obligatoire. Si la partie obligatoire n'est pas parfaite, la partie bonus ne sera pas évaluée.

La partie bonus ne sera évaluée que si la partie obligatoire n'est
pas validé.

## Conclusion

Dans cette conclusion, je réfléchis à la meilleure approche pour mener à bien ce projet Minishell.

Je pense que la meilleure façon d'aborder ce projet est de suivre une approche empirique avec un cahier des charges détaillé et une progression étape par étape. Voici le plan que je compte suivre :

**Important :** Il est crucial de noter que d'autres étudiants nous ont prévenus qu'à chaque résolution de bug, d'erreur ou de nouvelle implémentation, de nouvelles erreurs peuvent apparaître. Il faudra être particulièrement vigilant à ce sujet !

1. **Étape initiale :** Créer un dossier dédié pour chaque implémentation au fur et à mesure du développement.

2. **Phase d'apprentissage :** Identifier le besoin, essayer de répondre aux besoins en faisant preuve de RÉFLEXION et DOCUMENTATION. La réflexion nécessitera que je connecte mes neurones (hahaha). La documentation comprendra la compréhension du fonctionnement des fonctions externes que je compte utiliser.

3. **Phase de création :** Élaborer quelque chose qui fonctionne et qui répond aux besoins.

4. **Test et correction :** Identifier et corriger les failles éventuelles. En cas de problème ou d'impasse, retourner à l'étape 3.

5. **Optimisation :** Nettoyer le code pour le rendre plus compréhensible et modifiable ou optimiser les performances.

6. **Vérification finale :** S'assurer de l'absence de failles. Si nécessaire, répéter l'étape 5.

7. **Implémentation des fonctionnalités suivantes :** Avancer en implémentant les fonctionnalités suivantes du projet.


### Autre document

Dans le fichier README principal, je vais élaborer **un cahier des charges** complet et le mettre à jour à chaque validation d'une nouvelle implémentation.

De plus, je prévois de créer un fichier **Norme_Minishell.md** qui détaillera la structure des dossiers, le rangement des fichiers .c, .h, du Makefile, etc.

Au vu des conseils sa serais raisonable de faire un fichier .md énumerant toute les fails qui pourais avoir. Son nom serais **TEST.md**.

### La cohésion d'équipe est cruciale.

Pour garantir une bonne compréhension et communication au sein de l'équipe, il est essentiel d'encourager une communication ouverte. La disponibilité pour discuter des besoins et des difficultés de chaque membre est une clé pour le succès du projet. Et que chaque membre soit fier de son travail accompli.

Finalement, cette démarche sera guidée par un souci constant d'amélioration. J'aspire à ressentir un accomplissement personnel à chaque étape, en m'assurant que tous les membres de l'équipe peuvent s'impliquer pleinement et soient épanouis du travail accompli.

[Revenir aux sommaire](#sommaire).

Écrit par Yassine Zaoui, alias YatsuZ. 

Fin de la compréhension du sujet.
