# Rl_clear_history

La fonction rl_clear_history permet de vider complètement l'historique des commandes en supprimant toutes les entrées, de la même manière que la fonction clear_history() de la bibliothèque History. Cependant, cette fonction rl_clear_history diffère de clear_history car elle libère également les données privées que Readline enregistre dans la liste d'historique.

```h
void rl_clear_history (void)
```

## Utilisation de la fonction `rl_clear_history`

Pour utiliser la fonction Rl_clear_history, se trouve dans la même bibliothèque que [readline](./../readline/Explication.md#utilisation-de-la-fonction-readline) il faut les meme prerequi.

## Description de la fonction `rl_clear_history`

```h
void rl_clear_history (void)
```

La fonction `rl_clear_history` permet de vider entièrement la liste d'historique des commandes tout en libérant les données privées associées à cette liste dans Readline.

> De ce que j'ai compris c'est un free pour la structure history de readline

Pour en savoir plus, consultez les liens suivants :
- [la Bibliothèque GNU Readline](https://tiswww.case.edu/php/chet/readline/readline.html)
- [Man Readline](https://codepal.ai/code-generator/query/r7w2xxLn/c-code-that-clears-history-of-readline-library)

## Tester la fonction `rl_clear_history`

Pour tester la fonction `rl_clear_history`, J'ai utilise 3 ft externe.
1. [`add_history`](./../add_history/) qui est une fonction autoriser pour minishell qui ajoute des ligne dans l'history cliquer sur le lien pour + de precision.
2. ` history_list()` qui est une fonction interdite pour le projet minishell mais me permet de recupere la structure historique et de la free pour ne pas avoir de leak (Verifier si y a dautre moyen de free sans utilise la ft).
3. [`printf`](./../printf/) qui est une fonction autoriser pour minishell permet decrire dans le terminal.

J'ai ajouter des commande et recuperer la structure historique si il y a plus de 1 paremtre alords j'utilise la ft rl_clear_history sinon je ne lutilise pas.
Utilise avec vamgrind pour voir la difference.

voici le [code](./main.c) et voici les commande à faire pour tester le programme : 
```bash
$> make
$> ./rl_clear_history_Test_Programme
```