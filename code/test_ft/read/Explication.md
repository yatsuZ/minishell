# `read`

La fonction `read` est utilisée en langage C pour lire des données depuis un descripteur de fichier spécifié. Elle fait partie de la bibliothèque <unistd.h>.

## Syntaxe

La syntaxe générale de ``read`` est la suivante :

```h
ssize_t read(int descripteur_fichier, void *buf, size_t count);
```

- `descripteur_fichier` : Le descripteur du fichier à partir duquel lire les données.
- `buf` : Le tampon où stocker les données lues.
- `count` : Le nombre maximal d'octets à lire.

## Description

La fonction `read` lit jusqu'à `count` octets de données depuis le descripteur de fichier spécifié dans le tampon `buf`. Elle retourne le nombre d'octets lus. Si la fin de fichier est atteinte, `read` renvoie 0. En cas d'erreur, elle renvoie -1.

## Exemple

je vais lire la le fichier makefile.