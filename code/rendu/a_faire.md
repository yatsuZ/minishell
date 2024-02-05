# A faire

sortie en securite 
les signal
verifeir labscence de leak error et de fichier ouvert (fermer les fichier dans bultin). - check

# Issues

## Leaks

- Leaks quand la commande n'existe pas (ca leak pas a chaque fois bizarrement, mais ca arrive apres un `echo $?` par exemple)

- Leaks quand redirection seule

- Leaks sur erreur de synthax :

```sh
$>hello >|salade
```

-
```sh
echo a > coucou | cat
```

- Leaks dans les heredocs

## Comportements

### Retours d'erreurs

- Retour d'erreur toujours a 0 quand "command not found" devrait donner 127
```sh
$>dsdf
command not found: dsdf
$>echo $?
0
```

- Retour d'erreur toujours a 0 quand permission denied devrait donner 126 (+ n'affiche pas d'erreurs)

```sh
$>chmod 000 ls
$>./ls
$>echo $?
0
```

### Exec

- Pas de check/message d'erreur si file est un folder ou non (les folders sont consideres comme des executables par access donc il faut verifier par dessus)
```sh
$>ls /home/aubreysmie/.local/bin -la
total 60
drwxrwxr-x 3 ekhaled aubreysmie  4096 janv. 31 10:41 .
drwx------ 5 ekhaled aubreysmie  4096 juil. 24  2023 ..
-rwxr-xr-x 1 ekhaled aubreysmie 24964 nov.  19 11:36 man_reader
-rwxrwxr-x 1 ekhaled aubreysmie   218 aoÃ»t   4  2023 norminette
-rwxrwxr-x 1 ekhaled aubreysmie   221 juil. 24  2023 pip
-rwxrwxr-x 1 ekhaled aubreysmie   221 juil. 24  2023 pip3
-rwxrwxr-x 1 ekhaled aubreysmie   221 juil. 24  2023 pip3.10
-rwxrwxr-x 1 ekhaled aubreysmie   221 juil. 24  2023 pip3.11
drwxr-xr-x 2 ekhaled aubreysmie  4096 janv. 31 10:41 salade
$>salade
$>echo $?
0
```

### Historique

- Commandes vides ajoutees a l'historique alors qu'elles ne devraient pas

### Builtins

#### echo

- Mauvaise gestion `-n`
```sh
$>echo -n -n -n hello
-n -n hello$>
```

```sh
bash-5.1$ echo -n -n -n hello
hellobash-5.1$ 
```

## Remarques

- Attention tu as pas enlever tous tes debugs!!
- Fautes d'orthographes dans les messages d'erreurs + certains messages ne decrivent pas la premiere erreur detectee (ca c'est pas tres grave)

➜  rendu git:(main) ✗ valgrind --track-fds=yes --trace-children=yes --leak-check=full --suppressions=readline.supp ./minishell