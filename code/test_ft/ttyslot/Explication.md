# ttyslot

La fonction ttyslot en C est utilisée pour obtenir l'index dans la table des terminaux (/etc/ttys) du terminal associé au processus.

## Syntaxe

```h
int ttyslot(void);
```

## Description

- ttyslot renvoie l'index dans la table des terminaux (/etc/ttys) du terminal associé au processus appelant. Cette fonction est utilisée pour déterminer la position du terminal dans la table des terminaux du système.

- L'index retourné est généralement utilisé pour identifier les informations spécifiques au terminal dans le fichier /etc/ttys, où les paramètres de configuration des terminaux sont stockés.

la fonction retourne : 
L'index de l'entrée dans la table des terminaux pour le terminal associé au processus appelant.
Sinon -1 en cas derreur.

[documentation](http://manpagesfr.free.fr/man/man3/ttyslot.3.html)