# tcsetattr

La fonction tcsetattr est utilisée en langage C pour définir les attributs du terminal. Elle fait partie des fonctions fournies par la bibliothèque <termios.h>.

## Syntaxe

```h
int tcsetattr(int fd, int optional_actions, const struct termios *termios_p);
```

- fd : Descripteur de fichier représentant le terminal.
- optional_actions : Spécifie quand le changement doit avoir lieu. Il peut prendre l'une des valeurs suivantes :
	- TCSANOW : Les changements ont lieu immédiatement.
	- TCSADRAIN : Les changements ont lieu après que tous les écrits en attente sur le descripteur de fichier fd ont été envoyés.
	- TCSAFLUSH : Les changements ont lieu après que tous les écrits en attente sur le descripteur de fichier fd ont été envoyés, et le terminal est vidé.
- termios_p : Pointeur vers une structure termios qui spécifie les nouveaux attributs du terminal.

## Description

La fonction tcsetattr permet de définir les attributs du terminal spécifiés par la structure termios. La structure termios contient divers paramètres tels que la vitesse de transmission, le mode de traitement de l'entrée, le mode de traitement de la sortie, etc.

Les changements définis par tcsetattr prennent effet immédiatement ou après une écriture ou après une écriture suivie d'un vidage du terminal, en fonction de la valeur de optional_actions.

Retourne :

En cas de succès, la fonction renvoie 0. En cas d'échec, elle renvoie -1, et la variable errno est définie pour indiquer l'erreur.
