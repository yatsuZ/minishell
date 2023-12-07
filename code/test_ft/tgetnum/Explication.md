# tgetnum

La fonction tgetnum est utilisée pour obtenir des informations numériques spécifiques sur les capacités du terminal. Elle prend en paramètre le nom de la capacité recherchée et renvoie la valeur numérique correspondante, ou -1 si la capacité n'est pas trouvée.

## Syntax

```h
int tgetnum(const char *capname);
```

- capname: Nom de la capacité pour laquelle récupérer la valeur numérique.

## Description

La fonction tgetnum est utilisée pour obtenir des informations numériques relatives aux fonctionnalités du terminal. Elle retourne la valeur numérique associée à la capacité spécifiée dans capname.

Lorsque la capacité est trouvée, tgetnum renvoie sa valeur numérique. Si la capacité n'est pas trouvée ou si elle n'est pas numérique, la fonction renvoie -1 pour indiquer une erreur ou une capacité non numérique.

Cette fonction est souvent utilisée pour obtenir des informations telles que la largeur ou la hauteur du terminal (tgetnum("cols") pour le nombre de colonnes, tgetnum("lines") pour le nombre de lignes, etc.).

