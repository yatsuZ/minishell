# stat

La fonction stat est utilisée pour obtenir des informations sur un fichier spécifié.

## Syntax

```h
int stat(const char *path, struct stat *buf);
```

- path : Chemin du fichier dont on veut obtenir des informations.
- buf : Pointeur vers une structure struct stat où seront stockées les informations.

## Description

La fonction stat permet d'obtenir des informations détaillées sur le fichier spécifié par path en remplissant une structure struct stat pointée par buf.

