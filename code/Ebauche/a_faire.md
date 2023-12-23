# Ce que je dois faire

| Ce que je dois faire                           |Fais |
|-----------------------------------------------|----------------------------|
| 1. Un invité de commande                       |OUI|
| 2. Quand j'écris quelque chose, il réécrit en dessous |OUI|
| 3. Pouvoir quitter quand j'appuie sur Ctrl+D ou "exit" |OUI|
| Le rendre esthethique  |OUI|
| Faire un get next line qui retourne tout ce que le read à | OUI |
| INterpreter chaque node pour precise le type d'input | NON |
| GERER les siganux | NON |

## Conseil

utuilise 
```bash
bash --posix
```
comme reference d'exemple

## Comment marche un terminal cmd

[CMD ARGUEMENT redirection] PIP.

- CMD : verifier si il existe + qu'il peut etre executer.
- ARGUEMENT : tout ce qui suit apres un executable à noter qu'il peut etre en desordre avec un redirection. (attention aux "' et aux varieble denviroenemnt)
- redirection : ce qui suit un <<, >> ou <, > redirige lentre ou la sortie d'un fichier.
- si cela suit un pip alors reirgier la sortie principal et rebolote.

si une string na pas de sparateur alors on fusion les string

## Update 

Je dois faire la fonction : fusion_str_and_env(all->prompte->all_cmd_line)

Qui va permetre de fusione les string et le va denv et verifier si il y a une erreru de parsing