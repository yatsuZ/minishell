# tgoto

La fonction tgoto est utilisée pour construire une séquence de contrôle en insérant des paramètres dans un modèle de capacité du terminal. Voici une explication de sa syntaxe et un exemple d'utilisation :

## Syntaxe

```h
char *tgoto(const char *cap, int col, int row);
```

- cap : Chaîne de caractères représentant la capacité du terminal à utiliser.
- col : Colonne à spécifier dans le modèle de capacité.
- row : Ligne à spécifier dans le modèle de capacité.

## Description

La fonction tgoto est utilisée pour construire une séquence de caractères en remplaçant les paramètres col et row dans le modèle spécifié par cap de la base de données terminfo. Cette séquence générée peut être utilisée pour contrôler le curseur du terminal ou effectuer d'autres actions spécifiques.