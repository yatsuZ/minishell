# strerror

La fonction strerror en C est utilisée pour obtenir une chaîne de caractères décrivant un code d'erreur spécifique. Elle convertit un code d'erreur (généralement stocké dans la variable errno) en une description humainement lisible.

## Syntaxe

```h
char *strerror(int errnum);
```

- errnum : Code d'erreur (généralement errno) à décoder.

## Description

strerror prend en paramètre un code d'erreur (errnum) et renvoie un pointeur vers une chaîne de caractères statiquement allouée décrivant l'erreur correspondante.
Le message retourné décrit l'erreur associée au code errnum.
La chaîne de caractères retournée n'est pas modifiable.

### Retour

- La fonction renvoie un pointeur vers une chaîne de caractères contenant la description de l'erreur associée à errnum.
