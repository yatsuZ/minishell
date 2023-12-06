# wait4

La fonction wait4 est un appel système disponible dans certaines implémentations UNIX. Elle fait partie de la bibliothèque <sys/wait.h>.

## Syntax

```h
pid_t wait4(pid_t pid, int *status, int options, struct rusage *rusage);
```

- pid : Le PID du processus enfant à attendre.
- status : Un pointeur vers une zone mémoire où les informations sur la terminaison du processus enfant seront stockées.
- options : Des options pour contrôler le comportement de wait4.
- rusage : Une structure pour stocker des informations sur l'utilisation des ressources système par le processus enfant.

## Description

La fonction wait4 est similaire à waitpid(2), mais elle retourne également des informations sur l'utilisation des ressources par le processus enfant dans la structure pointée par rusage.

Un appel typique à wait4 ressemble à ceci :
```c
wait4(pid, status, options, rusage);
```

Cet appel attend la terminaison du processus enfant spécifié par pid et fournit également des informations détaillées sur l'utilisation des ressources par le processus enfant si rusage n'est pas NULL.

[Source](https://www.man-linux-magique.net/man2/wait3.html)