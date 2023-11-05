# Yassine qui essaye decomprendre lenoncer de minishell

## Introduction

Dans l'introduction le sujet nous dis qu'aux par avant les informaticien comuniquer directement en binaire avec les machine.
Ce qui etait compliquer et c'est pour cela qu'ils ont crée des logiciel qui serve d'intermediere (Les systeme dexploitation)
Et Nous devrons faire la meme chose crée un programme qui sert dintermedirare entre lhumain et la machine.

## Instruction commune

Comme dhabithude :
1- Projet code en C
2- Le code doit etre conforme a la norme
3- Les fonctions ne doivent pas s'arrete de maniere inatendue (erreur de segmentation, erreur de bus, double
gratuit, etc). En dehors des comportements non définis.
4- Ne pas avoir de leak (fuite de memoir).
5- SI y a un makefile alors . Je dois compiler avec "cc" et les flags "-Wall, -Wextra -Werror". Et je ne dois pas avoir de relink !
6- Le makefile doit avoir sa comme regle aux minimum $(NAME), all, clean, fclean et re.
7- Si je fais les bonus je dois faire une regle specifique pou sa creation et des fochier diférent si non precise.
8- Si j'utilise la libft je dois la compiler avec mon make
9- c'est conseillier d'utilise un programme test

## Partie Obligatoire

|Nom du programme| minishell |
|Fichier a rendre| Makefile, *.c, *.h|
| Arguement | AUCUN |
| Fonction externe authorise | readline, rl_clear_history, rl_on_new_line,
rl_replace_line, rl_redisplay, add_history,
printf, malloc, free, write, access, open, read,
close, fork, wait, waitpid, wait3, wait4, signal,
sigaction, sigemptyset, sigaddset, kill, exit,
getcwd, chdir, stat, lstat, fstat, unlink, execve,
dup, dup2, pipe, opendir, readdir, closedir,
strerror, perror, isatty, ttyname, ttyslot, ioctl,
getenv, tcsetattr, tcgetattr, tgetent, tgetflag,
tgetnum, tgetstr, tgoto, tputs|
| LIBFT  | autoriser |
| Description  | Write a shell |

## Ce que je dois etre capable de faire

- Afficher une invite lorsque vous attendez une nouvelle commande.
- Avoir un historique de travail.
- Recherchez et lancez le bon exécutable (en fonction de la variable PATH ou en utilisant un
chemin relatif ou absolu).
- Évitez d'utiliser plus d'une variable globale pour indiquer un signal reçu.
Considérer
les implications : cette approche garantit que votre gestionnaire de signaux n’accédera pas à votre
principales structures de données.
```
Sois prudent. Cette variable globale ne peut fournir aucune autre information ou accès aux données que le numéro d'un signal reçu. Il est donc interdit d'utiliser des structures de type "norme" en global.
```
- Ne pas interpréter les guillemets non fermés ou les caractères spéciaux qui ne sont pas requis par le
sujet tel que \ (barre oblique inverse) ou ; (point-virgule).
- ' (guillemet simple) qui devrait empêcher le shell d'interpréter les métacaractères dans la séquence citée.
- " (guillemet double) qui devrait empêcher le shell d'interpréter les métacaractères dans la séquence citée à l'exception de $ (signe dollar).
```
En gros quand c'est entre '' ou "" il peut pas interpreter les caracteres qui doivent faire une interpretation sauf pour le $ en ""
```
- Implémenter des redirections :
◦ < devrait rediriger l'entrée.
◦ > devrait rediriger la sortie.
◦ << doit recevoir un délimiteur, puis lire l'entrée jusqu'à ce qu'une ligne contenant le
le délimiteur est visible. Cependant, il n’est pas nécessaire de mettre à jour l’historique !
◦ >> devrait rediriger la sortie en mode ajout.
- Implémenter des tuyaux (caractère |). La sortie de chaque commande dans le pipeline est
connecté à l’entrée de la commande suivante via un tuyau.
- Gérer les variables d'environnement ($ suivi d'une séquence de caractères) qui
devraient s’étendre à leurs valeurs. (étendre leur valeur ??)
- Gérer $ ? qui devrait s'étendre au statut de sortie du dernier exécuté
pipeline de premier plan. ( pas compris pipeline de premier plan)
- Gérez ctrl-C, ctrl-D et ctrl-\ qui devraient se comporter comme dans bash.
```
En mode interactif :
◦ ctrl-C affiche une nouvelle invite sur une nouvelle ligne.
◦ ctrl-D quitte le shell.
◦ ctrl-\ ne fait rien.
```
- Votre shell doit implémenter les éléments intégrés suivants :
◦ écho avec l'option -n
◦ cd avec seulement un chemin relatif ou absolu
◦ pwd de passe sans options
◦ export sans options
◦ unset sans options
◦ env sans options ni arguments
◦ exit sans options

!!! La fonction readline() peut provoquer des fuites de mémoire. Vous n’êtes pas obligé de les réparer. Mais
cela ne veut pas dire que votre propre code, oui, le code que vous avez écrit peut avoir de la mémoire
des fuites.

Vous devez vous limiter à la description du sujet. Tout ce que
n’est pas demandé n’est pas obligatoire.
Si vous avez des doutes sur une exigence, prenez [bash](https://www.gnu.org/savannah-checkouts/gnu/bash/manual/) comme référence.

## Partie Bonus

Votre programme doit mettre en œuvre :
• && et || avec des parenthèses pour les priorités.
• Les caractères génériques * devraient fonctionner pour le répertoire de travail actuel.

La partie bonus ne sera évaluée que si la partie obligatoire est
PARFAIT. Parfait signifie que la partie obligatoire a été intégralement réalisée
et fonctionne sans dysfonctionnement. Si vous n'avez pas réussi TOUS les
conditions obligatoires, votre partie bonus ne sera pas du tout évaluée.

## Yassine qui explique interpretation

