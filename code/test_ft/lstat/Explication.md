# lstat

La fonction lstat est similaire à stat, mais elle est utilisée spécifiquement pour obtenir des informations sur un fichier référencé par un lien symbolique.

## Syntaxe

```h
int lstat(const char *path, struct stat *buf);
```

- path : Chemin du fichier (y compris le lien symbolique) dont on veut obtenir des informations.
- buf : Pointeur vers une structure struct stat où seront stockées les informations.

## Description

La fonction lstat est utilisée pour obtenir des informations sur le fichier référencé par path, qu'il s'agisse d'un lien symbolique ou non. Elle remplit une structure struct stat pointée par buf avec les informations du fichier cible du lien symbolique.

La différence principale entre lstat et stat est que lstat ne suit pas le lien symbolique, mais obtient les informations sur le lien lui-même. Cela permet d'obtenir des détails sur le lien symbolique en tant que fichier, plutôt que sur sa cible.

### lien symbolique

lien symbolique est un fichier qui redirige vers un autre fichier.
```bash
ln -s [fichier cible] [Nom de fichier symbolique]
```
