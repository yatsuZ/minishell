# rl_replace_line

La fonction rl_replace_line permet de remplacer la ligne actuellement affichée dans l'interface de ligne de commande par une nouvelle ligne spécifiée.

```h
void rl_replace_line(const char *text, int clear_undo)
```

## Utilisation de la fonction `rl_replace_line`

Pour utiliser la fonction rl_replace_line, se trouve dans la même bibliothèque que [readline](./../readline/Explication.md#utilisation-de-la-fonction-readline) il faut les meme prerequi.

## Description de la fonction `rl_replace_line`

```h
void rl_replace_line(const char *text, int clear_undo)
```

La fonction rl_replace_line prend deux arguments :

text : Une chaîne de caractères (const char *) représentant la nouvelle ligne à afficher.

clear_undo : Un entier (int) spécifiant s'il faut effacer l'historique des actions effectuées. Si clear_undo est différent de zéro, l'historique est effacé ; sinon, il est conservé.

Cette fonction remplace la ligne actuelle affichée dans l'interface de ligne de commande par la chaîne de caractères text.

Pour en savoir plus, consultez les liens suivants :
- [la Bibliothèque GNU Readline](https://tiswww.case.edu/php/chet/readline/readline.html)
- [Guide complet de minishelle et montre comment utilise la fonction rl_replace_line](https://chrtophe.developpez.com/tutoriels/minisysteme/#L23-5-2)

## Tester la fonction `rl_replace_line`

Pour tester la fonction `rl_replace_line` j'ai utilise de focntion exeterne:
- [`readline`](./../readline/Explication.md#utilisation-de-la-fonction-readline)
- `rl_forced_update_display` fonction interdite pour le projet minishell et qui permet de re afficher avec le changement de `rl_replace_line`.

Mon code teste effectue la fonction readline puis fais la fonction `rl_replace_line` et reafiche avec `rl_forced_update_display`.

Je n'ai pas encore trouvée d'utilité pour le projet minishell.