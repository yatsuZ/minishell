# execve

La fonction execve est utilisée pour exécuter un programme à partir d'un processus. Elle remplace l'image mémoire du processus en cours par un nouveau programme spécifié par le chemin d'accès.

## Syntaxe

```h
int execve(const char *pathname, char *const argv[], char *const envp[]);
```

- pathname : Chemin d'accès du programme à exécuter.
- argv : Tableau d'arguments passés au programme. Le premier élément (argv[0]) est conventionnellement le nom du programme.
- envp : Tableau de chaînes de caractères représentant l'environnement du nouveau programme.

## Description

La fonction execve charge et exécute un nouveau programme dans le processus appelant. Elle remplace l'espace mémoire du processus par le programme spécifié par pathname. Les arguments du programme sont fournis via argv, et l'environnement est défini par envp.

Si execve réussit, elle ne retourne pas à moins d'une erreur. En cas d'erreur, elle retourne -1 et définit la variable errno pour indiquer l'erreur spécifique.
(le main principal sera remplacer par le nouveaux).