#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
# include <stdlib.h>

int main() {
    // Nom du fichier à ouvrir
    const char *nomFichier = "exemple.txt";
    int descripteurFichier = -1;
	int stdout_sauvegarde;
    char    *str;

    // printf("Je suis avant le dup2\n");
	stdout_sauvegarde = dup(STDOUT_FILENO);

    // printf("descripteurFichier = %d\n", descripteurFichier);
    // descripteurFichier = open(nomFichier, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    // printf("descripteurFichier = %d\n", descripteurFichier);
    // dup2(descripteurFichier, STDOUT_FILENO);
    // printf("descripteurFichier = %d\n", descripteurFichier);
    // printf("Je dois etre dans le fichier\n");
    // close(descripteurFichier);
    // printf("descripteurFichier = %d\n", descripteurFichier);
	// dup2(stdout_sauvegarde, STDOUT_FILENO);
    // printf("Je suis sortie du fichier\n");
    // str = readline("$> ");
    // printf("%s\n", str);
    // free(str);
    // // close(15);
    // perror("test : ");
    close(stdout_sauvegarde);
    return 0;
}
