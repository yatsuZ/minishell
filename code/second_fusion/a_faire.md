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

Il ne reste plus que export.
Retirer tout les g_status et remplacer par un element de la structure.
Puis fusion la partie exec

les builtin son fini il ne reste plus qu'a corriger 3 chose pour corriger :
1- Faire les signal et au passage corriger g_status par g_signal et biens faire la distinction.
2- Fusione le travail de Ilham des exec pour que tout marche
3- Poffiner pour verifier la securitée