# malloc

La fonction malloc est une fonction importante en langage C utilisée pour allouer de la mémoire dynamiquement pendant l'exécution d'un programme. Elle appartient à la bibliothèque `<stdlib.h>`.


## Syntaxe

La syntaxe générale de malloc est la suivante :

```h
void *malloc(size_t taille_en_octets);
```

- `taille_en_octets` : C'est le nombre d'octets que vous souhaitez allouer dans la mémoire.

## Description

Lorsqu'un programme C est compilé, certaines variables sont déclarées et leur espace mémoire est réservé à l'avance. Cependant, il arrive que vous ayez besoin d'allouer de la mémoire de manière dynamique pendant l'exécution, par exemple, pour stocker des données dont la taille est inconnue à la compilation.

La fonction `malloc` est utilisée dans de tels cas. Elle recherche un bloc de mémoire libre de la taille spécifiée par `taille_en_octets` dans le tas (une zone de mémoire gérée dynamiquement), puis la réserve. Elle retourne un pointeur vers le début de cette mémoire allouée.

Si `malloc` réussit, elle renvoie un pointeur vers le début de la mémoire allouée. Sinon, elle renvoie NULL.

### Bonus

Si on utilise malloc pour ne pas crée de leak il faut utilise la fonction [free](./../free/).

D'aillieur pour avoir une meillieur fonction pour allouer de la memoire il est mieux de faire notre propre fonction `calloc` qui est pareil que malloc mais qui prend 2 parametre nombre d'ellement et la taille du type et return NULL si il y a une erreur lors de lalocation de memoir.

## Exemple

Creation de la fonction calloc + Alocation de la memoir d'une chaine de caractaire puis la free.