# add_history

La fonction add_history permet d'ajouter une ligne à l'historique des commandes saisies dans un programme interactif.

```h
void add_history (const char *string)
```

## Utilisation de la fonction `add_history`

Pour utiliser la fonction add_history, se trouve dans la même bibliothèque que [readline](./../readline/Explication.md#utilisation-de-la-fonction-readline) il faut les meme prerequi.

## Description de la fonction `add_history`

```h
void add_history (const char *string)
```

La fonction add_history prend en paramètre une chaîne de caractères string représentant la commande à ajouter à l'historique.

Pour en savoir plus, consultez les liens suivants :

- [Man history](https://linux.die.net/man/3/history)

## Tester la fonction `add_history`

Pour tester la fonction `add_history` je fais readline tant que je n'ai pas ecrit exit, donc j'ai tuilise quelque fonction externe comme [readline](./../readline/Explication.md#utilisation-de-la-fonction-readline) qui peut provoquer des leak.
Et add_history me permet que lorsque je fais ⬆️ (fleche de navigation haut) ou ⬇️ (fleche de navigation haut). Je peux naviguer dans un historique.