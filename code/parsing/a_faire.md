# Je suis sur ma 2iem Ebauche

je suis sur la deuxime Ebauche ce que je dois faire rejouter les \\ pour stoper.
Donc je vais re arranger tout mon code par consequent je vais aussi netoyer mes fichier et mieux rangée.
puis continuer mon parsing et le faire de telle sorte :
Le parsing aura en entre un chaine de caractere en entre et je vais deoire redoner cela :
[CMD][ARG][RD][PIP]

| Enum: Type_input | input |Description |
|------------------|---------|-------------|
| NON_DEFINI | Tout lors de l'initialisation de la structure | Si les chaînes n'ont pas encore été catégorisées |
| SINGLE_COT | ' | Ne doit pas être encapsulé par des guillemets. Doit être fermé par un autre guillemet simple sinon erreur de syntaxe. Tout entre ces guillemets forme une seule chaîne de caractères. |
| DOUBLE_COT | " | Comme les guillemets simples, mais peut contenir des variables d'environnement (VA_ENV). |
| SEPARATOR | \t ou " " | Espace, tabulation, ou autre. Ils sont considérés comme des séparateurs. |
| STR | Tout entre des guillemets (sauf les variables d'environnement et ce qui suit le $). |
| VA_ENV | $[KEY] | Commence par un dollar et est suivi d'une clé représentant une variable d'environnement. Si la clé est valide, c'est une variable d'environnement, sinon traité comme une chaîne ou un argument. |
| CMD | Première chaîne de caractères | fichier, chemin de fichier d'execution ou builtin. |
| ARG | Tout ce qui suit une commande | Tout les arugment a envoyer lors des execution |
| R_IN | <[RD] | Redirection d'entrée. |
| R_OUT | >[RD] | Redirection de sortie. |
| R_IN_LIMIT | <<[RD] | Fait un heredoc (plus complexe). |
| R_OUT_ADD | >>[RD] | Ajout à la redirection de sortie. |
| F_RD | [RD] | STRING ou ARG qui suit une redirection. |
| PIP | \| |Redirection de sortie principale quoi qu'il arrive. (sauf en cas derreur de parsing)|

1. Recuperer readline et couper la string en fonction des input speciaux puis les metre dans des noeud et on pouras savoir le type d'inpute qu'on as.
Pendant cette etapde decoupage je peux catgoriser les BACK_SLASH et le reste NON_DEFINI.
1. Une fois qu'onas cree des noeud et tout divisée on dois categoriser chaque noeud puis fusione les noeud voici la procedure :
   1. Puis trouver les cote simple double et Variable denvironement.
   2. Je dois fusionée ce qui a entre les cote car ce sont des STR.
   Ca speciaux pour les double cote et Variable d'envirnoment et 
   Cas speciaux pour si il y a un VA_ENV dans une double cote alors je saute la VA et le noeud suivant, Pareil pour les BACK_SLASH on le saute on s'en couppe apres.
   3. Je dois fusione les noeud de variable d'environement. (Cas speciaux si le $ et suivie d'une cote)
   4. Je dois trouver toute les Redirection et leur fichier de redirection atribuer si il na pas de fichier de redirection erreur syntax + verifier leur existance et Leur droit de lecture si ces un R_IN et verifier leur droit decriture si c des R_OUT ou R_OUT_ADD. Si c'est faux alors retour syntaxe erreur
   5. Verifier Les PIP et qu'il ne se suivent pas.
2. Apres avoir categoriser, Je dois replacer les VA_ENV pour leur valeur. Et les faire fusionée si ils sont compris dans des string. et retirer les BACSLASH et les cote pour les string pur les transformr en argument.
3. Je vais devoirs metre tout ces noeud dans cette structure :
[CMD] -> CHAR *
[ARG] -> CHAR **
[RD] -> Noeud de redirection
[PIP] -> Redirection Veris les prochainne commande>
4. Puis la partie parsing sera fini et il restera l'execution c'est Ilham qui prendra la suite.
les builtin et les signaux.

Les rd se font de gauche a droite mais les R_IN_LIMIT recupere en rpioriée le buffer.