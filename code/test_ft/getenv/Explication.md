# getenv

La fonction getenv en C permet de récupérer la valeur d'une variable d'environnement. Les variables d'environnement stockent des informations système telles que les chemins d'accès, les paramètres de configuration, etc. Cette fonction est définie dans la bibliothèque standard <stdlib.h>.

## Syntaxe

```h
char *getenv(const char *name);
```

- name : Le nom de la variable d'environnement que vous souhaitez récupérer.

## Description

La fonction getenv prend en argument le nom d'une variable d'environnement et renvoie un pointeur vers une chaîne de caractères représentant la valeur de cette variable. Si la variable n'existe pas, la fonction renvoie un pointeur NULL.

