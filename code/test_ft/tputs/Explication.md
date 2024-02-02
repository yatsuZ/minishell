# tputs

La fonction tputs est utilisée pour envoyer des capacités de contrôle de terminal (telles que des séquences d'échappement) à un terminal. Elle prend en paramètre une chaîne de caractères représentant une capacité de contrôle terminale et effectue l'action correspondante sur le terminal.

## Syntaxe

```h
int tputs(const char *str, int affcnt, int (*putc)(int));
```

- str: Chaîne de caractères représentant la capacité de contrôle terminal à envoyer.
- affcnt: Nombre de lignes affectées (utilisé pour l'optimisation).
- putc: Pointeur de fonction pour une fonction équivalente à putc de la bibliothèque standard.

## Description

La fonction tputs prend une chaîne de caractères contenant une séquence d'échappement terminal en tant que paramètre. Elle envoie cette séquence au terminal associé. Cette séquence d'échappement peut inclure des commandes pour déplacer le curseur, changer les couleurs du texte, effacer l'écran, etc.

Elle utilise le pointeur de fonction putc pour écrire les caractères de la séquence sur le flux de sortie du terminal.

Utile pour faire la fonction clear.