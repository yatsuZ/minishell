# fork

La fonction fork est utilisée en langage C pour créer un nouveau processus appelé processus enfant. Elle fait partie de la bibliothèque <unistd.h>.

## Syntax

La syntaxe de fork est la suivante :

```h
pid_t fork(void);
```

## Description

Lorsque la fonction fork est appelée, elle crée un nouveau processus, appelé processus enfant, qui est une copie exacte du processus appelant, appelé processus parent. Le processus enfant démarre à la ligne suivant l'appel à fork, avec les mêmes variables, le même code, et le même état que le processus parent au moment de l'appel.

### Valeur retour

- Dans le processus parent, fork retourne le PID (identifiant de processus) du processus enfant.
- Dans le processus enfant, fork retourne 0.
- En cas d'échec, fork retourne -1.


## Exemple

Jessaie de faire un fork.