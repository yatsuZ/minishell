# Readline

La fonction readline permet de lire une ligne depuis le terminal. Elle est déclarée de la manière suivante :
```h
char *readline (const char *prompt)
```

## Utilisation de la fonction `readline`

Pour utiliser la fonction readline, suivez ces étapes :

### Prérequis à installer :

Avant d'utiliser readline, assurez-vous d'avoir installé la bibliothèque libreadline-dev. Vous pouvez l'installer avec la commande :
```bash
sudo apt-get install libreadline-dev
```
### Inclusion des bibliothèques nécessaires :

Dans votre code, incluez les en-têtes nécessaires pour utiliser readline :

```h
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
```

### Compilation du programme :

Lors de la compilation de votre programme, assurez-vous d'ajouter l'option -lreadline pour lier la bibliothèque readline. Par exemple :

```bash
cc -g3 -Wall -Wextra -Werror main.c -lreadline -o programme
```
Cela se résume comme suit :
```css
[Compilateur] [Flags] [SRC] -lreadline [Nomée_le_programme]
```
Ces étapes sont nécessaires pour utiliser correctement la fonction readline dans votre programme.

## Description de la fonction `readline`

```h
char *readline (const char *prompt)
```

La fonction `readline` permet de lire une ligne depuis le terminal et de la renvoyer en utilisant "prompt" comme invitation à l'utilisateur. 
Si "prompt" est NULL ou une chaîne vide, aucune invitation n'est affichée.

Il est crucial de noter que la ligne renvoyée est allouée dynamiquement avec `malloc(3)`, **et donc l'appelant est responsable de la libérer une fois qu'elle n'est plus nécessaire.**

La ligne renvoyée ne contient pas le saut de ligne final, ce qui signifie que seule la texte de la ligne saisie est retournée.

Cette fonction offre des capacités d'édition pendant que l'utilisateur entre la ligne. Par défaut, les commandes d'édition de ligne sont similaires à celles d'Emacs, mais une interface d'édition de ligne de style vi est également disponible.

En résumé, "prompt" est une invitation de commande pour l'utilisateur. Dès qu'il y a un "End Of File (EOF)", la fonction retourne tout ce qui a été saisi ou lu jusqu'à ce moment-là.

**La fonction readline peut laisser des blocs de mémoire accessibles ("still reachable") à la fin de l'exécution. Bien que provenant de la fonction readline ou de bibliothèques externes, ces blocs sont généralement tolérables et ne sont pas nécessairement des fuites de mémoire.**

Il existe de nombreuses autres fonctionnalités disponibles avec `readline`. Pour en savoir plus, consultez les liens suivants :
- [Man Readline](https://man7.org/linux/man-pages/man3/readline.3.html)
- [la Bibliothèque GNU Readline](https://tiswww.case.edu/php/chet/readline/rltop.html)
- [la Bibliothèque GNU History](https://tiswww.case.edu/php/chet/readline/history.html)

## Tester la fonction `readline`

Pour tester la fonction `readline`, voici une approche :
- Répéter 10 fois ce que l'utilisateur saisit, suivi d'un saut de ligne sans causer de fuite de mémoire et suivi d'un '\n'.
- Utiliser comme invite **"Je vais répéter ce que tu dis.\n"**.
- Afficher un message spécial si l'utilisateur renvoie juste un EOF ou que des EOF sont envoyés.

Puisque tu vas réafficher ce que l'utilisateur a saisi et que tu ne veux pas de fuite de mémoire, tu devras utiliser les fonctions `free()` et `printf()` de manière appropriée.