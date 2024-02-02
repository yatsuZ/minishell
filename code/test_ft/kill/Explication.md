# kill

La fonction kill est utilisée pour envoyer un signal à un processus ou à un groupe de processus. Elle est souvent utilisée pour envoyer des signaux à d'autres processus dans un système Unix.

## Syntax

```h
int kill(pid_t pid, int sig);
```

- pid : ID du processus auquel envoyer le signal.
- sig : Numéro du signal à envoyer.

## Description

La fonction kill envoie un signal spécifié par sig au processus identifié par pid. Le signal peut être un signal standard (comme SIGTERM pour terminer un processus) ou tout autre signal défini.

## Explication code

Enfaite kill envoie un signal à un precoessus dans ce code à lui meme et quand il recoit le signal il effectue une action precise je pensegrace au fonction signal et sigaction.