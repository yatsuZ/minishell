# ttyname

La fonction ttyname en C est utilisée pour obtenir le nom du fichier du terminal associé à un descripteur de fichier donné.

## Syntaxe

```h
char *ttyname(int file_descriptor);
```

- file_descriptor : Le descripteur de fichier pour lequel vous souhaitez obtenir le nom du terminal.

## Description

- ttyname renvoie un pointeur vers une chaîne de caractères contenant le nom du fichier du terminal associé au descripteur de fichier spécifié par file_descriptor. Si le descripteur de fichier n'est pas lié à un terminal, la fonction renvoie NULL.
- Elle est utilisée pour déterminer le nom du fichier du terminal associé à un descripteur de fichier donné, ce qui peut être utile pour effectuer des opérations spécifiques sur ce terminal.
- Return NULL en cas derreur sinon une chaine de charactere.

