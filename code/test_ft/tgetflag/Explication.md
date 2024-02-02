# tgetflag

La fonction tgetflag fait partie de la bibliothèque ncurses en langage C. Elle permet de vérifier si une fonctionnalité spécifique du terminal est activée.

## Syntax

```h
int tgetflag(const char *capability);
```

## Description

La fonction tgetflag prend en paramètre une chaîne de caractères représentant une capacité ou une fonctionnalité du terminal. Elle renvoie 1 si la fonctionnalité est activée et 0 si elle est désactivée ou non disponible.

Par exemple, pour vérifier si la fonctionnalité "auto margin" ("am") est activée, vous pouvez utiliser tgetflag("am"). Remplacez "am" par d'autres abréviations pour vérifier différentes fonctionnalités du terminal.

Tgetflag vérifie si une capacité spécifique du terminal est activée. Si la capacité est active, la fonction renvoie 1, sinon elle retourne 0. Par exemple, tgetflag("am") vérifie si la fonctionnalité "auto margin" est activée.