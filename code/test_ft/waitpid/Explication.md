# waitpid

La fonction waitpid est utilisée en langage C pour attendre la terminaison spécifique d'un processus enfant. Elle fait partie de la bibliothèque <sys/wait.h>.

## Syntax

```h
pid_t waitpid(pid_t pid, int *status, int options);
```

- pid : Le PID du processus enfant à attendre.
- status : Un pointeur vers une zone mémoire où les informations sur la terminaison du processus enfant seront stockées.
- options : Des options supplémentaires pour contrôler le comportement de waitpid.

## Description

La fonction waitpid est similaire à wait, mais elle offre plus de contrôle sur le processus enfant à attendre et son comportement. Elle permet d'attendre un processus enfant spécifique, identifié par son PID.

Elle retourne le PID du processus enfant qui s'est terminé ou -1 en cas d'erreur. Si aucun processus enfant correspondant n'est trouvé, waitpid peut se comporter différemment selon les options fournies.

## Options de `waitpid`

- WNOHANG : Retourne immédiatement si aucun enfant spécifié par pid n'est encore terminé.
- WUNTRACED : Comprend également les processus arrêtés, en plus des processus terminés normalement.
