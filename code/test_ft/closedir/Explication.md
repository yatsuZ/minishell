# colsedir

La fonction closedir en C est utilisée pour fermer un flux de répertoire qui a été ouvert précédemment avec la fonction opendir. Cela libère les ressources associées au flux de répertoire.

## Syntaxe

```h
int closedir(DIR *dir_stream);
```

- dir_stream : Pointeur vers le flux de répertoire à fermer.

## Description

- closedir() ferme le flux de répertoire spécifié par dir_stream et libère les ressources associées à ce flux.
- Après avoir appelé closedir(), le pointeur dir_stream ne doit pas être utilisé, car il ne sera plus valide.
- Si dir_stream est NULL ou s'il ne s'agit pas d'un flux de répertoire valide, un comportement indéfini peut survenir.

### Retour

- La fonction renvoie 0 en cas de succès.
- En cas d'erreur, elle retourne -1 et définit errno pour indiquer le type d'erreur survenu.

## Code exemple

Voire dans [opendir](./../opendir/main.c).