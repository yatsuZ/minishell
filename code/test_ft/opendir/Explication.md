# opendir

La fonction opendir en C est utilisée pour ouvrir un répertoire spécifique et obtenir un pointeur de type DIR pour accéder aux entrées de ce répertoire.

## Syntaxe

```h
DIR *opendir(const char *pathname);
```
- dirname : Chemin du répertoire à ouvrir.

## Description

- opendir() ouvre le répertoire spécifié par dirname et retourne un pointeur de type DIR qui peut être utilisé pour lire le contenu de ce répertoire.
- Si la fonction réussit, elle renvoie un pointeur non nul. En cas d'erreur, elle renvoie NULL et définit errno pour indiquer l'erreur.

## Retour

- En cas de succès, un pointeur de type DIR vers le flux de répertoire ouvert.
- En cas d'échec, NULL est renvoyé et errno est défini pour indiquer l'erreur.

