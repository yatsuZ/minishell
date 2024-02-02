# write

La fonction `write` est une fonction utilisée en langage C pour écrire des données vers un descripteur de fichier donné. Elle est souvent utilisée pour écrire dans des fichiers ou des flux de données. La fonction `write` fait partie de la bibliothèque `<unistd.h>`.

## Syntax

La syntaxe générale de write est la suivante :

```h
ssize_t write(int descripteur_fichier, const void *buf, size_t count);
```

- `descripteur_fichier` : Le descripteur du fichier vers lequel écrire les données.
- `buf` : Le pointeur vers les données à écrire.
- `counte` : Le nombre d'octets à écrire.

## Description

La fonction `write` prend trois arguments : le descripteur du fichier (`descripteur_fichier`), un pointeur vers les données à écrire (`buf`), et le nombre d'octets à écrire (`count`). Elle tente d'écrire jusqu'à `count` octets depuis le tampon (buf) vers le fichier spécifié par `descripteur_fichier`.

Elle retourne le nombre d'octets effectivement écrits s'il réussit, ou -1 s'il y a une erreur. En cas d'erreur, le code d'erreur spécifique est mis dans la variable `errno`.

### Différence et avantage comparée à [`printf`](./../printf/)

La fonction `write` et `printf` sont toutes deux utilisées pour afficher des données. Cependant, elles diffèrent dans leur fonctionnement et leurs utilisations :

Principales différences :

|`write` | `printf`|
|--------|---------|
|Utilisé pour écrire des données dans un descripteur de fichier spécifique. | Utilisé pour formater et afficher des données sur la sortie standard (généralement le terminal). |
| Nécessite le descripteur de fichier où écrire les données et le nombre d'octets à écrire. | Accepte un nombre variable d'arguments et permet un formattage plus avancé (par exemple %d pour les entiers, %s pour les chaînes de caractères, etc.).|
| Peut être utilisé pour écrire dans n'importe quel descripteur de fichier, pas seulement la sortie standard.| Gère automatiquement le flux de sortie. |

> Pourquoi `Write` >>>> `Printf` :
- **Contrôle du descripteur de fichier** : Avec `write`, tu peux écrire dans n'importe quel descripteur de fichier, ce qui inclut les fichiers, les sockets réseau, etc. `printf` est limité à l'affichage sur la sortie standard.
- **Performance** : `write` peut être plus performant dans certaines situations car il n'effectue pas de formatage complexe comme `printf`, ce qui peut être avantageux lors de l'écriture brute de données dans des fichiers ou des sockets.

> Pourquoi `Write` <<<< `Printf` :

- **Facilité d'utilisation** : printf offre un formatage pratique et convivial pour l'affichage des données, facilitant la manipulation des chaînes de caractères et des types de données.
- **Gestion du flux de sortie** : printf gère automatiquement la sortie vers le terminal, offrant des fonctionnalités telles que le formatage et le passage à la ligne sans nécessiter de descripteur de fichier explicite.

## Exemple code

Jessaie de fair tout les exemple possible que peut avoir la fonction `write`.