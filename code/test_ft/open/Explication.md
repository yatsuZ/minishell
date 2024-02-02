# `open`

La fonction `open` est utilisée en langage C pour ouvrir un fichier existant ou en créer un nouveau. Elle fait partie de la bibliothèque <fcntl.h>.

## Syntax

La syntaxe générale de `open` est la suivante :

```h
int open(const char *chemin, int drapeaux, mode_t mode);
```

- `chemin` : Le chemin vers le fichier à ouvrir.
- `drapeaux` : Les options de l'ouverture du fichier (lecture, écriture, création, etc.).
- `mode` : Les permissions du fichier à créer si celui-ci n'existe pas.

## Description

La fonction `open` permet d'ouvrir un fichier existant ou de créer un nouveau fichier s'il n'existe pas. Elle retourne un descripteur de fichier (un entier) qui sera utilisé pour accéder au fichier dans d'autres opérations telles que `read`, `write` et `close`.

### Drapeaux couramment utilisés

- `O_RDONLY` : Ouvrir en mode lecture seulement.
- `O_WRONLY` : Ouvrir en mode écriture seulement.
- `O_RDWR` : Ouvrir en mode lecture et écriture.
- `O_CREAT` : Créer le fichier s'il n'existe pas.
- `O_TRUNC `: Tronquer le fichier à zéro s'il existe déjà.
- `O_APPEND` : Écrire à la fin du fichier.

### Mode de création de fichier (mode)

Si le drapeau `O_CREAT` est utilisé, le mode de création du fichier est spécifié avec le paramètre `mode`. Par exemple, `S_IRUSR` | `S_IWUSR` donne des permissions en lecture et en écriture à l'utilisateur.

Voire cette documentation pour plus dinformation : [doc](https://www.gladir.com/CODER/CLINUX/`open`.htm)

