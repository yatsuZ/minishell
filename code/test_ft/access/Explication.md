# `access`

La fonction `access` est utilisée en langage C pour vérifier l'existence ou les permissions d'accès à un fichier ou à un répertoire. Elle fait partie de la bibliothèque `<unistd.h>`.

## Syntax

La syntaxe générale de `access` est la suivante :

```h
int `access`(const char *chemin, int mode);
```

- `chemin` : Le chemin vers le fichier ou le répertoire à vérifier.
- `mode` : Les permissions à vérifier (par exemple **R_OK** pour la lecture, **W_OK** pour l'écriture, **X_OK** pour l'exécution).

## Description

La fonction `access` permet de vérifier si un processus a les autorisations spécifiées pour accéder à un fichier ou un répertoire. Elle retourne 0 si les permissions sont accordées selon le mode spécifié, ou -1 en cas d'échec (avec le code d'erreur mis dans la variable `errno`).

### Modes de permission

- **R_OK** : Vérifie si le fichier est lisible.
- **W_OK** : Vérifie si le fichier est accessible en écriture.
- **X_OK** : Vérifie si le fichier est exécutable.
- **F_OK** : Vérifie simplement l'existence du fichier.

## Exemple 

je vais utilise la fonction pour verifier si des fichier existe ou non cette fonction est assez simple à comprendre.