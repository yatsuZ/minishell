# printf

La fonction `printf` est une fonction de sortie utilisée en langage C pour afficher des informations à l'écran ou dans un fichier. Elle est définie par la library `stdio.h` et est largement utilisée pour afficher des chaînes de caractères formatées.


## Utilisation de la fonction `printf`

```h
int  printf (const char *string, )
```

- retourne un int qui est le nombre de caractere affiché au terminal.
- format : C'est une chaîne de caractères qui spécifie la manière dont les données doivent être formatées lors de l'affichage.
- ... : Les points de suspension représentent les arguments variables pouvant être fournis à la fonction printf en fonction du format spécifié.

## Description de la fonction `printf`

```h
void printf (const char *string)
```

La fonction printf prend en paramètre une chaîne de caractères string représentant la commande à ajouter à l'historique.

### ANSI explication

En langage C, les séquences d'échappement ANSI permettent de manipuler les couleurs du texte dans la console. Ces séquences spéciales sont des codes échappement qui contrôlent le formatage du texte affiché dans le terminal. Donc peut etre tres utile.

Pour en savoir plus, consultez les liens suivants :

- [Man printf](https://man.developpez.com/man3/printf/)
- [Doc sur ANSI](https://www.lihaoyi.com/post/BuildyourownCommandLinewithANSIescapecodes.html)
## Tester la fonction `printf`

Pour tester la fonction `printf` j'ai utilise plein de type differente et j'ai montrer tout ce que cette fonction pouvais faire.
Pour faire la resortie du texte on peut faire ceci :
```bash
$> ./printf_Test_Programme 1> res.txt
```