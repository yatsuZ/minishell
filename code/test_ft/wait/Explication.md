# wait

La fonction wait est utilisée en langage C pour attendre la terminaison d'un processus enfant. Elle fait partie de la bibliothèque <sys/wait.h>.

## Syntaxe

```h
pid_t wait(int *status);
```

- status : Un pointeur vers une zone mémoire où les informations sur la terminaison du processus enfant seront stockées.

## Description

La fonction wait est utilisée par le processus parent pour attendre la terminaison d'un processus enfant. Si aucun enfant n'est actuellement en cours d'exécution, wait met le processus appelant en attente jusqu'à ce qu'un enfant se termine ou qu'un signal soit reçu.

Elle retourne le PID du processus enfant qui s'est terminé ou -1 en cas d'erreur.

## Statut du processus enfant

Le statut de terminaison du processus enfant peut être obtenu en inspectant la valeur pointée par status. Cette valeur peut contenir des informations sur la manière dont le processus enfant s'est terminé (par exemple, son code de sortie).

