# sigaddset

La fonction sigaddset est utilisée pour ajouter un signal spécifique à un ensemble de signaux (sigset_t). Elle permet d'ajouter un signal donné à un ensemble de signaux déjà existant.

## Syntax

```h
int sigaddset(sigset_t *set, int signum);
```

- set : Pointeur vers l'ensemble de signaux (sigset_t) auquel ajouter le signal.
- signum : Numéro du signal à ajouter à l'ensemble.

## Description

La fonction sigaddset ajoute un signal spécifié par signum à l'ensemble de signaux spécifié par set. Cela permet de manipuler les ensembles de signaux pour bloquer, autoriser ou ignorer certains signaux dans différentes parties du code.

