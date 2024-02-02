# perror

La fonction perror en C est utilisée pour afficher un message décrivant la dernière erreur détectée lors d'une opération système. Elle prend en compte la valeur de la variable errno pour produire un message d'erreur humainement lisible.

## Syntaxe

```h
void perror(const char *prefix);
```

- prefix : Chaîne de caractères qui sera affichée avant le message d'erreur spécifique.

## Description

- perror affiche un message d'erreur sur la sortie standard (stderr). Ce message contient le contenu de la chaîne prefix (s'il est non NULL) suivi d'un : et du message associé à la dernière erreur détectée (stockée dans errno).
- La fonction perror est souvent utilisée pour afficher des messages d'erreur détaillés lorsqu'une fonction système renvoie une valeur d'erreur.

