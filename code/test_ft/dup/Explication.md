# dup

La fonction dup est utilisée pour dupliquer un descripteur de fichier existant vers un autre descripteur disponible.

## Syntaxe

```h
int dup(int oldfd);
```

- oldfd : Descripteur de fichier à dupliquer.

## Description

La fonction dup crée une copie du descripteur de fichier oldfd. Elle retourne un nouveau descripteur de fichier qui est le plus petit descripteur non utilisé dans le processus. Par conséquent, le descripteur retourné est généralement le résultat de dup plus petit que tous les descripteurs actuellement ouverts.

La copie du descripteur de fichier pointe vers le même fichier que le descripteur d'origine. Cela permet, par exemple, d'utiliser différents descripteurs pour lire ou écrire dans le même fichier sans interférer les uns avec les autres.