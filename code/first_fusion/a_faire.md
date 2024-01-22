# Builtin de Yassine

Voici les builtin que je dois faire :

| nom des commande | Option pris en compte | ARGUMENT | Ce que sa fais | particularitée |
|------------------|-----------------------|----------|----------------|----------------|
| `echo`		   | -n (ne pas afficher de saut de ligne final) | TOUT | Afficher la(les) CHANE(s) en écho sur la sortie standard. | |
| `cd` 			   | NON 				   | prend en compte que le premier arguement chemin relatif ou absolut | se deplace et modifie le PWD | mets a jouer ou cree la VA_d'env PWD|
| `pwd`			   | NON				   | IGNORE TOUT | echo de la va d'env $PWD | |
| `export`		   | NON				   | \[key]=\[value] | Ajoute dans lenv une key qui est egale a une valeur | Il y a une syntaxe de clée et de valeur a respecter |
| `unset`		   | NON				   | key... | Retire une key et vide sa value 
| `env`			   | NON				   | IGNORE TOUT | affiche toutes les env et leur value | |
| `exit`		   | NON				   | n = numeric | quite le programme et retourne larguement ou $? si null bash error si cest non un caractere numeric et 2 par consequnt | modulo de 255, si y a un pipe modife juste $?|