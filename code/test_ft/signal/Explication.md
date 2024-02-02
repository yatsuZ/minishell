# Signal

La fonction signal est utilisée pour manipuler les signaux en langage C. Elle fait partie de la bibliothèque <signal.h>.

## Syntax

```h
void (*signal(int signum, void (*handler)(int)))(int);
```

- signum : Le numéro du signal à manipuler.
- handler : Le gestionnaire (handler) de signal à associer au signal spécifié.

## Description

La fonction signal permet de gérer les signaux en installant des gestionnaires de signaux spécifiques. Un gestionnaire de signal est une fonction qui est appelée lorsqu'un signal particulier est reçu par un processus.

Un appel typique à signal ressemble à ceci :

```c
signal(SIGINT, handler_function);
```

Cet appel associe la fonction handler_function au signal SIGINT (signal d'interruption, souvent généré par Ctrl+C).

### Parametre 

- signum : Le numéro du signal à manipuler. Les signaux sont définis dans <signal.h>.
- handler : Le gestionnaire de signal à exécuter lorsque le signal spécifié est reçu. Il peut s'agir d'une fonction définie par l'utilisateur ou de valeurs spéciales telles que SIG_IGN pour ignorer le signal ou SIG_DFL pour utiliser le comportement par défaut du signal.

### Valeur renvoyée

La fonction signal renvoie un pointeur vers la fonction précédemment associée au signal ou SIG_ERR en cas d'erreur.

### Ques qu'un signal ?

En programmation système, les signaux sont des mécanismes utilisés par les systèmes d'exploitation pour notifier les processus d'événements ou de conditions spécifiques. Les signaux peuvent être déclenchés par le noyau du système, d'autres processus, ou même par le processus lui-même.

Voici quelques points clés à connaître sur les signaux :

- **Notificateurs d'événements** : Les signaux sont des notificateurs asynchrones. Ils avertissent les processus qu'un événement s'est produit, comme la réception d'une interruption matérielle, la fin d'un processus enfant, etc.
- **Identification unique** : Chaque signal est identifié par un numéro, comme SIGINT pour l'interruption (généralement déclenchée par Ctrl+C) ou SIGKILL pour tuer un processus. Ces constantes sont définies dans le fichier d'en-tête <signal.h>.
- **Comportement par défaut** : Chaque signal a un comportement par défaut associé lorsqu'il est reçu. Par exemple, SIGINT entraîne souvent l'interruption d'un processus, tandis que SIGTERM demande poliment à un processus de se terminer.
- **Gestion des signaux** : Les processus peuvent manipuler les signaux en installant des gestionnaires de signaux spécifiques (signal handlers). Ces gestionnaires sont des fonctions qui sont exécutées lorsqu'un signal spécifique est reçu, permettant au processus de prendre des mesures spécifiques en réponse à ce signal.
- **Contrôle du flux d'exécution** : Les signaux peuvent interrompre l'exécution normale du programme en déclenchant l'exécution de leur gestionnaire associé. Cela permet au programme de réagir à des événements imprévus ou de libérer des ressources en cas de besoin.

Documentation : [man signal](http://manpagesfr.free.fr/man/man2/signal.2.html)

## Exemple 

Jesaasi de comporendre la foncion mlais en resume quand je fais control+C j'active la fonction signal.