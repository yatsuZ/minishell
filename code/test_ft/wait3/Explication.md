# wait3

La fonction wait3 est un appel système disponible dans certaines implémentations UNIX. Elle fait partie de la bibliothèque <sys/wait.h>.

## Syntaxe

```h
pid_t wait3(int *status, int options, struct rusage *rusage);
```

- status : Un pointeur vers une zone mémoire où les informations sur la terminaison du processus enfant seront stockées.
- options : Des options pour contrôler le comportement de wait3.
- rusage : Une structure pour stocker des informations sur l'utilisation des ressources système par le processus enfant.

## Description

La fonction wait3 est similaire à waitpid(2), mais elle retourne également des informations sur l'utilisation des ressources par le processus enfant dans la structure pointée par rusage.

Un appel typique à wait3 ressemble à ceci :

```c
wait3(status, options, rusage);
```

Cet appel est équivalent à :

```c
waitpid(-1, status, options);
```

En d'autres termes, wait3() attend la terminaison de n'importe quel fils et fournit également des informations détaillées sur l'utilisation des ressources par le processus enfant si rusage n'est pas NULL.

[Source](https://www.man-linux-magique.net/man2/wait3.html)