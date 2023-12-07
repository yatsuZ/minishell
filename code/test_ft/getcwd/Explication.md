# getcwd

La fonction getcwd est utilisée pour obtenir le chemin absolu du répertoire de travail actuel.

## Syntax

```h
char *getcwd(char *buf, size_t size);
```

- buf : Pointeur vers un tampon où sera stocké le chemin absolu du répertoire de travail.
- size : Taille du tampon buf.

## Description

La fonction getcwd permet de récupérer le chemin absolu du répertoire de travail actuel du processus. Elle stocke ce chemin dans le tampon buf passé en argument.

en gros elle est tres utile pour faire la commande pwd.