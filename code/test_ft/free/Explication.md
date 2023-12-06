# free

La fonction `free` est une fonction importante en langage C utilisée pour libérer la mémoire qui a été allouée dynamiquement à l'aide de malloc. Elle appartient à la bibliothèque `<stdlib.h>`.

## Syntax

La syntaxe générale de free est la suivante :

```h
void free(void *ptr);
```

- ptr : C'est un pointeur vers la mémoire précédemment allouée à l'aide de malloc, calloc ou realloc que vous souhaitez libérer.

## Description

Lorsque vous allouez de la mémoire dynamiquement à l'aide de malloc, calloc ou realloc, il est impératif de libérer cette mémoire une fois que vous avez terminé de l'utiliser pour éviter les fuites de mémoire, c'est-à-dire des portions de mémoire qui ne sont plus accessibles mais qui ne sont pas libérées pour être réutilisées.

La fonction free est utilisée pour libérer la mémoire allouée dynamiquement. Elle prend en paramètre le pointeur vers cette mémoire et la rend disponible pour une réutilisation future.

Il est important de noter que free ne modifie pas la valeur du pointeur passé en argument. Après l'appel à free, il est une bonne pratique de définir explicitement le pointeur sur NULL pour éviter tout accès accidentel à une zone mémoire libérée.

## Utilisation

jajoue de la memoir de maniere d'ynamique et si il y a un argument jessayerais de free de la memoir statique mais le programme crasheras.
