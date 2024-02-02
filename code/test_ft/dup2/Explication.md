# dup2

La fonction dup2 est utilisée pour dupliquer un descripteur de fichier existant vers un autre descripteur spécifié.

## Syntaxe

```h
int dup2(int oldfd, int newfd);
```

- oldfd : Descripteur de fichier à dupliquer.
- newfd : Descripteur de fichier vers lequel oldfd doit être dupliqué.

## Description

La fonction dup2 crée une copie du descripteur de fichier oldfd et l'assigne à newfd. Si newfd est déjà ouvert, il est fermé avant que dup2 ne lui associe oldfd, sauf si oldfd est égal à newfd.

Si oldfd est invalide ou si dup2 rencontre une erreur, dup2 renvoie -1. En cas de succès, elle renvoie le descripteur newfd.

