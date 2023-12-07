# exit

La fonction exit est utilisée pour terminer immédiatement le programme en cours d'exécution et retourner un code de sortie à son appelant.

## Syntax

```h
void exit(int status);
```

- status : Code de sortie à retourner au système d'exploitation.

## Description

La fonction exit termine immédiatement l'exécution du programme en cours et retourne au système d'exploitation avec un code de sortie spécifié par status. Ce code est généralement utilisé pour indiquer le statut de sortie du programme à son appelant.

exit c'est le dernier return en gros.