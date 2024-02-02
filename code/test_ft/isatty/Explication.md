# isatty

La fonction isatty en C est utilisée pour déterminer si un descripteur de fichier correspond à un terminal.

## Syntax

```h
int isatty(int file_descriptor);
```

- file_descriptor : Le descripteur de fichier que vous souhaitez vérifier s'il correspond à un terminal.

## Description

- isatty vérifie si le descripteur de fichier spécifié par file_descriptor est associé à un terminal. Elle renvoie 1 si c'est le cas (le descripteur est celui d'un terminal), sinon elle renvoie 0.

- Cette fonction est utile pour déterminer si le programme est en interaction directe avec un utilisateur via un terminal ou si la sortie est redirigée vers un fichier ou un autre descripteur de fichier.

- retourne 1 si c'est un terminal sinon 0.

