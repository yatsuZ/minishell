# Sigaction

La fonction sigaction est utilisée pour manipuler le comportement des signaux dans les programmes C. Elle permet de spécifier des actions personnalisées à exécuter lorsqu'un signal particulier est reçu.

## Syntax

```h
int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
```

- signum : Le numéro du signal à manipuler.
- act : Un pointeur vers une structure struct sigaction décrivant le nouveau gestionnaire de signal et les options associées.
- oldact : (Optionnel) Un pointeur vers une structure struct sigaction pour stocker l'ancienne action associée au signal.

## Description

La fonction sigaction permet de spécifier le comportement à adopter lorsqu'un signal spécifique est reçu par un processus. Elle remplace souvent la fonction signal() car elle offre un contrôle plus précis sur la gestion des signaux.

La structure struct sigaction utilisée comme argument act dans sigaction ressemble à ceci :

```h
struct sigaction {
    void (*sa_handler)(int);  // Gestionnaire de signal (fonction)
    sigset_t sa_mask;         // Signaux bloqués pendant l'exécution du gestionnaire
    int sa_flags;             // Drapeaux pour spécifier le comportement
    void (*sa_sigaction)(int, siginfo_t *, void *);  // Gestionnaire de signal alternatif
};
```
- sa_handler : Un pointeur vers la fonction qui sera appelée lorsque le signal est reçu.
- sa_mask : Un ensemble de signaux à bloquer pendant l'exécution du gestionnaire de signal.
- sa_flags : Des drapeaux pour définir le comportement du signal.
- sa_sigaction : Un gestionnaire alternatif qui peut fournir des informations supplémentaires sur le signal.
- La fonction sigaction renvoie 0 en cas de succès ou -1 en cas d'erreur.

### Différences entre `sigaction()` et `signal()`

|   | `sigaction()` | `signal()` |
|---|---------------|------------|
| **Précision** | Offre un contrôle plus précis sur la gestion des signaux grâce à l'utilisation de la structure `struct sigaction` qui permet de spécifier des options avancées comme le masquage des signaux (`sa_mask`). | Moins précise et moins flexible, permettant uniquement de spécifier une simple fonction de gestion des signaux (`sa_handler`). |
| **Contrôle du signal** | Permet une gestion plus fine des signaux avec des options pour contrôler le comportement lors de la réception d'un signal. | Moins de contrôle sur la manière dont le signal est géré. |
| **Compatibilité** | Plus portable entre les différents systèmes d'exploitation. | La portabilité peut varier selon les implémentations, moins garantie sur tous les systèmes. |
| **Ancienneté** | Méthode de gestion de signal plus récente. | Méthode de gestion de signal plus ancienne et moins sophistiquée. |
| **Stockage de l'ancien gestionnaire** | Permet de stocker l'ancien gestionnaire de signal lors de la définition d'un nouveau. | Ne stocke pas l'ancien gestionnaire de signal lors du remplacement d'un nouveau. |
| **Options supplémentaires** | Offre des options supplémentaires telles que la gestion d'informations supplémentaires sur les signaux (`sa_sigaction`) et des options de drapeaux (`sa_flags`). | Moins d'options et de contrôle avancé disponibles. |
