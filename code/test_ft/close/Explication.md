# close

La fonction close est utilisée en langage C pour fermer un descripteur de fichier ouvert précédemment avec open ou obtenu via d'autres appels système. Elle fait partie de la bibliothèque <unistd.h>.

## Syntaxe

La syntaxe de close est la suivante :

```h
int close(int descripteur_fichier);
```

- descripteur_fichier : Le descripteur du fichier à fermer.

## Description

La fonction close ferme le descripteur de fichier spécifié. Après avoir utilisé open ou d'autres appels système pour ouvrir un fichier, il est important de le fermer avec close une fois que toutes les opérations sur ce fichier sont terminées.

Retourne 0 en cas de reussite - 1 sinon

## Exemple

vous pouvez voire ces code : 

[read test](../read/main.c) ou [open test](./../open/main.c) ou [write test](./../write/main.c).