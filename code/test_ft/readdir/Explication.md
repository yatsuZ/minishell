# readdir

La fonction readdir en C est utilisée pour lire le contenu d'un répertoire ouvert à l'aide de la fonction opendir. Elle renvoie un pointeur vers une structure dirent qui représente une entrée dans ce répertoire.

## Syntaxe

```h
struct dirent *readdir(DIR *dir_stream);
```

- dir_stream : Pointeur vers le flux de répertoire ouvert avec opendir.

## Description

- readdir() lit l'entrée suivante du répertoire spécifié par le flux de répertoire dir_stream.
- La structure dirent retournée contient des informations sur l'entrée du répertoire, telles que le nom du fichier.
- Chaque appel successif à readdir() sur le même flux de répertoire renverra l'entrée suivante du répertoire.
- Lorsqu'il n'y a plus d'entrées à lire ou en cas d'erreur, readdir() renvoie NULL.

### Retour

- Un pointeur vers une structure dirent représentant l'entrée lue du répertoire.
- NULL est renvoyé lorsqu'il n'y a plus d'entrées à lire ou en cas d'erreur.

## Code exemple

Voire dans [opendir](./../opendir/main.c).