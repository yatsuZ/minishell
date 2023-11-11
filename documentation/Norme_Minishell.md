# Norme du projet Minishell

Ce fichier explique comment Yassine et Ilhma ont rangé leurs documents, fichiers, leur manière de coder tout en respectant la norminette. Ce fichier évoluera continuellement à l'avancement du projet.

**Si une nouvelle règle est créée, créez une section.**

## Norme de compilation et `Makefile`

Les règles obligatoires des variables pour chaque commande et dossier dans le dossier source.

Tous les fichiers `.o` seront mis dans un dossier séparé nommé `obj_compilation`.

## Norme `main.c`

Pour un main bien compréhensible, il sera créé de cette manière :

Les `main.c` auront toujours cette structure, une structure `data` contenant toutes les informations nécessaires.

On l'initialise avec les paramètres. Si il y a un cas d'erreur alors la fonction `init_data` retournera 1 et le programme s'arrête.

La fonction `ft_minisheel` sera le cœur du programme. Et à la fin on finit par `ft_end`.
```c
int	main(int argc, char **argv, char **env)
{
	t_data	*data;
	if (init_data(data, argc, argv, env))
		return (ft_end(data));
	ft_minishell(data);
	return (ft_end(data));
}
```

## Rangement des fichiers et dossiers

**Racine du projet :**

- `Makefile` : Fichier permettant de compiler le programme.

---

**Headers :** Dossier contenant tous mes fichiers `.h`.

- `Constante.h` : Fichier contenant uniquement des constantes.
- `Import.h` : Fichier important toutes les bibliothèques et autres headers, important également "Constante.h".
- `Structure.h` : Fichier contenant toutes les structures créées pour le programme, important "Import.h".
- `Minishell.h` : Fichier contenant toutes les fonctions créées pour le programme, important "Structure.h".

---

**Source :** Dossier contenant tous mes fichiers `.c`, à l'exception de ceux du bonus.

- `main.c` : Fichier principal en format `.c` qui lancera le programme.
- `Struct` : Dossier contenant des fichiers `.c` pour l'initialisation de structures et leur destruction.
- `Utile` : Dossier contenant des fichiers `.c` contenant des fonctions utiles communes.
- Et un dossier pour chaque implémentation.
