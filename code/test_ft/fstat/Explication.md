# fstat

La fonction fstat est utilisée pour obtenir des informations sur un fichier en utilisant un descripteur de fichier déjà ouvert.

## Syntaxe

```h
int fstat(int file_descriptor, struct stat *file_info);
```

- file_descriptor : Descripteur de fichier pour lequel on souhaite obtenir des informations.
- file_info : Pointeur vers une structure struct stat où seront stockées les informations.

## Description

La fonction fstat est utilisée pour obtenir des informations sur le fichier référencé par le descripteur de fichier file_descriptor, qui doit être déjà ouvert à l'aide d'appels système comme open.

Elle remplit une structure struct stat pointée par file_info avec les informations du fichier correspondant au descripteur de fichier.