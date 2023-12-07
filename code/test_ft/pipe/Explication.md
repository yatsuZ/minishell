# pipe

La fonction pipe en C est utilisée pour créer un tube (ou un canal) pour la communication entre processus. Ce tube est unidirectionnel, permettant la communication entre un processus parent et ses processus enfants. Voici un aperçu de son utilisation :

## Syntaxe

```h
int pipe(int filedes[2]);
```

- filedes: Tableau d'entiers de taille 2, où filedes[0] est l'extrémité de lecture du tube et filedes[1] est l'extrémité d'écriture du tube.

## Description

- pipe() crée un tube et place les descripteurs de fichiers correspondants dans le tableau filedes. filedes[0] est utilisé pour la lecture et filedes[1] pour l'écriture.
- Les données écrites dans filedes[1] peuvent être lues depuis filedes[0]. Ce mécanisme est souvent utilisé pour permettre la communication entre un processus parent et ses processus enfants, en établissant une communication de type « tube ».

### Retour

- En cas de succès, pipe() renvoie 0.
- En cas d'échec, il renvoie -1 et définit errno pour indiquer l'erreur.
