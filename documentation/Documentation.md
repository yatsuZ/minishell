# Documentation

Ce fichier contient toutes les sources utiles à la création du projet.

## un invité de commande

Un "invité de commande" est un programme informatique qui permet à l'utilisateur d'interagir avec un système d'exploitation en saisissant des commandes textuelles. C'est une interface en ligne de commande qui permet d'effectuer diverses tâches sans recourir à une interface graphique.

## Sources de documentation

- [Tutoriels Minishell](https://github.com/maxime-42/minishell/tree/master/tutorials)
- [Lexical Analysis - Wikipedia](https://en.wikipedia.org/wiki/Lexical_analysis)

## Liste de toutes les fonctions externes autorisées

Consultez le manuel de chaque fonction pour comprendre son fonctionnement.

| Compris | Nom de la fonction                                        | En-tête de la bibliothèque | Description brève                                                                                     |
|---------|-----------------------------------------------------------|----------------------------|-------------------------------------------------------------------------------------------------------|
|    ✔️  | [readline](./../code/test_ft/readline/)                   | `<readline/readline.h>`    | Lit une ligne à partir de l'entrée utilisateur avec des fonctionnalités d'édition de ligne.           |
|    🤔  | [rl_clear_history](./../code/test_ft/rl_clear_history)    | `<readline/history.h>`     | Efface l'historique des commandes dans GNU Readline.                                                  |
|    🤔  | [rl_on_new_line](./../code/test_ft/rl_on_new_line)        | `<readline/readline.h>`    | Signale le début d'une nouvelle ligne dans GNU Readline.                                              |
|    🤔  | [rl_replace_line](./../code/test_ft/rl_replace_line)      | `<readline/readline.h>`    | Remplace la ligne courante dans GNU Readline.                                                         |
|    🤔  | [rl_redisplay](./../code/test_ft/rl_redisplay)            | `<readline/readline.h>`    | Redisplays la ligne d'entrée courante dans GNU Readline.                                              |
|    ✔️  | [add_history](./../code/test_ft/add_history)              | `<readline/history.h>`     | Ajoute la ligne courante à l'historique dans GNU Readline.                                            |
|    ✔️  | [printf](./../code/test_ft/printf)                        | `<stdio.h>`                | Affiche une sortie formatée sur la console.                                                           |
|    ✔️  | [malloc](./../code/test_ft/malloc)                        | `<stdlib.h>`               | Alloue un nombre spécifié d'octets de mémoire0.                                                        |
|    ✔️  | [free](./../code/test_ft/free)                            | `<stdlib.h>`               | Désalloue la mémoire précédemment allouée par malloc.                                                 |
|    ✔️  | [write](./../code/test_ft/write)                          | `<unistd.h>`               | Écrit des données sur un descripteur de fichier.                                                      |
|    ✔️  | [access](./../code/test_ft/access)                        | `<unistd.h>`               | Vérifie si un fichier existe ou si le processus peut y accéder.                                       |
|    ✔️  | [open](./../code/test_ft/open)                            | `<fcntl.h>`                | Ouvre un fichier ou un périphérique.                                                                  |
|    ✔️  | [read](./../code/test_ft/read)                            | `<unistd.h>`               | Lit des données à partir d'un descripteur de fichier.                                                 |
|    ✔️  | [close](./../code/test_ft/close)                          | `<unistd.h>`               | Ferme un descripteur de fichier.                                                                      |
|    ✔️  | [fork](./../code/test_ft/fork)                            | `<unistd.h>`               | Crée un nouveau processus en dupliquant le processus existant.                                        |
|    ✔️  | [wait](./../code/test_ft/wait)                            | `<sys/wait.h>`             | Attend la fin d'un processus enfant et récupère son état.                                             |
|    ✔️  | [waitpid](./../code/test_ft/waitpid)                      | `<sys/wait.h>`             | Attend la fin d'un processus enfant spécifique et récupère son état.                                  |
|    ✔️  | [wait3](./../code/test_ft/wait3)                          | `<sys/wait.h>`             | Attend la fin d'un processus enfant et récupère son état avec des options supplémentaires.            |
|    ✔️  | [wait4](./../code/test_ft/wait4)                          | `<sys/wait.h>`             | Attend la fin d'un processus enfant spécifique et récupère son état avec des options supplémentaires. |
|    ✔️  | [signal](./../code/test_ft/signal)                        | `<signal.h>`               | Définit une fonction pour gérer un signal spécifique.                                                 |
|    ✔️  | [sigaction](./../code/test_ft/sigaction)                  | `<signal.h>`               | Examine et modifie l'action du signal.                                                                |
|    ✔️  | [sigemptyset](./../code/test_ft/sigemptyset)              | `<signal.h>`               | Initialise un ensemble de signaux vide.                                                               |
|    ✔️  | [sigaddset](./../code/test_ft/sigaddset)                  | `<signal.h>`               | Ajoute un signal à un ensemble de signaux.                                                            |
|    ✔️  | [kill](./../code/test_ft/kill)                            | `<signal.h>`               | Envoie un signal à un processus.                                                                      |
|    ✔️  | [exit](./../code/test_ft/exit)                            | `<stdlib.h>`               | Quitte le processus en cours.                                                                         |
|    ✔️  | [getcwd](./../code/test_ft/getcwd)                        | `<unistd.h>`               | Obtient le répertoire de travail actuel.                                                              |
|    ✔️  | [chdir](./../code/test_ft/chdir)                          | `<unistd.h>`               | Change le répertoire de travail actuel.                                                               |
|    ✔️  | [stat](./../code/test_ft/stat)                            | `<sys/stat.h>`             | Obtient des informations sur un fichier.                                                              |
|    ✔️  | [lstat](./../code/test_ft/lstat)                          | `<sys/stat.h>`             | Obtient des informations sur un lien symbolique.                                                      |
|    ✔️  | [fstat](./../code/test_ft/fstat)                          | `<sys/stat.h>`             | Obtient des informations sur un fichier à partir d'un descripteur de fichier.                         |
|    ✔️   | [unlink](./../code/test_ft/unlink)                        | `<unistd.h>`               | Supprime un nom du système de fichiers.                                                               |
|    ✔️  | [execve](./../code/test_ft/execve)                        | `<unistd.h>`               | Exécute un programme.                                                                                 |
|    ✔️  | [dup](./../code/test_ft/dup)                              | `<unistd.h>`               | Duplique un descripteur de fichier.                                                                   |
|    🤔  | [dup2](./../code/test_ft/dup2)                            | `<unistd.h>`               | Duplique un descripteur de fichier vers un descripteur de fichier spécifié.                           |
|    ✔️  | [pipe](./../code/test_ft/pipe)                            | `<unistd.h>`               | Crée un tube, un canal de communication unidirectionnel.                                              |
|    ✔️  | [opendir](./../code/test_ft/opendir)                      | `<dirent.h>`               | Ouvre un répertoire pour la lecture.                                                                  |
|    ✔️  | [readdir](./../code/test_ft/readdir)                      | `<dirent.h>`               | Lit une entrée de répertoire.                                                                         |
|    ✔️  | [closedir](./../code/test_ft/closedir)                    | `<dirent.h>`               | Ferme un flux de répertoire.                                                                          |
|    ✔️  | [strerror](./../code/test_ft/strerror)                    | `<string.h>`               | Retourne un pointeur vers la représentation textuelle de la valeur errno actuelle.                    |
|    ✔️  | [perror](./../code/test_ft/perror)                        | `<stdio.h>`                | Affiche une description de la dernière erreur survenue.                                               |
|    ✔️  | [isatty](./../code/test_ft/isatty)                        | `<unistd.h>`               | Vérifie si un descripteur de fichier fait référence à un terminal.                                    |
|    ✔️  | [ttyname](./../code/test_ft/ttyname)                      | `<unistd.h>`               | Retourne le nom du fichier terminal associé à un descripteur de fichier.                              |
|    ✔️  | [ttyslot](./../code/test_ft/ttyslot)                      | `<unistd.h>`               | Obtient l'index de l'entrée dans le fichier termcap correspondant au terminal.                        |
|    🤔  | [ioctl](./../code/test_ft/ioctl)                          | `<sys/ioctl.h>`            | Effectue des opérations spécifiques au périphérique.                                                  |
|    ✔️  | [getenv](./../code/test_ft/getenv)                        | `<stdlib.h>`               | Récupère la valeur d'une variable d'environnement.                                                    |
|    🤔  | [tcsetattr](./../code/test_ft/tcsetattr)                  | `<termios.h>`              | Définit les paramètres associés au terminal.                                                          |
|    🤔  | [tcgetattr](./../code/test_ft/tcgetattr)                  | `<termios.h>`              | Obtient les paramètres associés au terminal.                                                          |
|    🤔  | [tgetent](./../code/test_ft/tgetent)                      | `<term.h>`                 | Initialise la structure de données termcap.                                                           |
|    ✔️  | [tgetflag](./../code/test_ft/tgetflag)                    | `<term.h>`                 | Obtient la valeur booléenne d'une capacité termcap.                                                   |
|    🤔  | [tgetnum](./../code/test_ft/tgetnum)                      | `<term.h>`                 | Obtient la valeur numérique d'une capacité termcap.                                                   |
|    🤔  | [tgetstr](./../code/test_ft/tgetstr)                      | `<term.h>`                 | Obtient la valeur de chaîne d'une capacité termcap.                                                   |
|    🤔  | [tgoto](./../code/test_ft/tgoto)                          | `<term.h>`                 | Prépare une séquence d'adressage de curseur.                                                          |
|    🤔  | [tputs](./../code/test_ft/tputs)                          | `<term.h>`                 | Affiche une capacité termcap.                                                                         |

Légende : 
- 🤔 = pas compris l'utilite ou le fonctionement.
- ✔️ = compris.
- ❌ = pas enocre documenté.