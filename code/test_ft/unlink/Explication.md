# unlink

La fonction unlink est utilisée pour supprimer un fichier existant du système de fichiers. Elle supprime l'entrée du répertoire associée au nom de fichier spécifié.

## Syntax

```h
int unlink(const char *pathname);
```

- pathname : Le chemin du fichier que vous souhaitez supprimer.

## Description

La fonction unlink supprime le fichier spécifié par pathname. Si le fichier est ouvert par un processus ou si les autorisations ne permettent pas la suppression du fichier, cette opération échoue.

### Retour

- En cas de succès, unlink retourne zéro.
- En cas d'échec, elle retourne -1 et met en place la variable errno pour indiquer l'erreur spécifique.

## Code exemple

cree une fichier :
```bash
touch a_suprimer
```

puis executer le code.

Utile pour crée la fonction rm.