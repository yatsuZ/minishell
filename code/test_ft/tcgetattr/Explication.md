# tcgetattr

tcgetattr est une fonction de la bibliothèque <termios.h> utilisée pour obtenir les attributs actuels d'un terminal.

## Syntaxe

```h
int tcgetattr(int fd, struct termios *termios_p);
```

- fd : Descripteur de fichier associé au terminal.
- termios_p : Pointeur vers une structure termios pour stocker les attributs.

## Description

- tcgetattr récupère les attributs actuels du terminal spécifié par fd et les stocke dans la structure pointée par termios_p.
- Elle renvoie 0 en cas de succès, -1 en cas d'échec.