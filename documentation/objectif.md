# Objectif

Je rédige ce markdown car j'ai réalisé une documentation et je suis un peu perdue. Ainsi, je vais essayer de déterminer un objectif de travail et de formuler clairement ce dont j'ai besoin. Je pense que la première étape consiste à relire le sujet ainsi que le résumé que j'ai fait. Si j'ai une idée de ce que je dois faire, j'écrirai ici et dans la [to do liste](./../README.md#cahiere-de-charge).
Et si je n'ai toujours pas d'idée, je consulterai mes documentations.

## Définition

Je dois définir ces termes.

### Shell

Qu'est-ce qu'un shell ? C'est ce que je dois faire d'ailleurs, mon propre shell. Donc, pour en créer un, je dois connaître les critères.

En français, on appelle cela **une interface système** et son nom est plus évocateur. C'est une interface entre l'humain et la machine. C'est-à-dire que c'est avec cela que l'humain utilisera pour interagir avec la machine avec des lignes de texte. C'est l'interface la plus haute entre l'humain et la machine.

Il peut y avoir différents types :

- CLI et TUI, en gros pour interagir avec des lignes de commande
- GUI, la partie graphique comme les bureaux, etc.

Nous nous concentrons uniquement sur la première partie, la partie graphique nous importe peu.

- Le mode console qui affiche une coque logicielle unique en plein écran, c'est l'interface utilisateur de base du système d'exploitation ;
- Le mode terminal qui émule une console et qui affiche généralement la coque logicielle dans une portion de l'écran.

| Quels sont les critères pour faire un shell ?|
|----------------------------------------------|
| Interactivité : Offrir une interface interactive pour saisir des commandes et recevoir des réponses du système.|
| Gestion des processus : Permettre le lancement, l'arrêt et la gestion des processus en arrière-plan et en premier plan.|
| Manipulation des fichiers : Gérer la création, la suppression, la copie et le déplacement de fichiers ainsi que la navigation dans les répertoires.|
| Redirection et pipelines : Permettre la redirection des entrées/sorties standard et la création de pipelines pour connecter la sortie d'une commande à l'entrée d'une autre.|
| Variables d'environnement : Gérer les variables d'environnement du système et permettre à l'utilisateur de les manipuler.|

### Prompt

Le prompt est le symbole ou le texte affiché par le shell pour indiquer à l'utilisateur qu'il peut saisir une commande. Il peut inclure des informations telles que le nom de l'utilisateur, le nom de l'hôte, le chemin actuel, etc. Exemple : 
```bash
$
```
ou 
```bash
user@hostname:~$.
```
### History

L'historique des commandes conserve un enregistrement des commandes précédemment saisies par l'utilisateur. Cela permet de naviguer dans l'historique, de réexécuter des commandes précédentes et de rechercher des commandes spécifiques.

### Path

Le chemin (path) est une liste de répertoires où le système d'exploitation recherche les exécutables des commandes saisies par l'utilisateur. Il est utilisé pour localiser les programmes lorsque leur nom est saisi dans le shell.

### builtins

Les commandes intégrées (builtins) sont des commandes directement implémentées dans le shell plutôt que d'être des programmes séparés sur le système. Elles offrent des fonctionnalités de base telles que cd, echo, pwd, etc.

### Analyse lexicale

## Ce que je dois et ne dois pas faire

- Pas de code spaghetie
- Ne perdez pas de mémoire et ne perdez pas les descripteurs de fichiers (pas non plus dans vos processus enfants lors de l'exécution de la commande) ;
- Votre shell ne doit planter dans aucun scénario, c'est un shell, la seule interaction possible que vous avez avec votre système d'exploitation, ne le laissez pas planter car vous serez alors condamné.

