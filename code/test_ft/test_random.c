#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Nom du fichier à ouvrir
    const char *nomFichier = "exemple.txt";

	int fd_tab[2];

	fd_tab[0] = dup(0);
	fd_tab[1] = dup(1);

    // Ouvre le fichier en mode écriture (O_WRONLY | O_CREAT | O_TRUNC)
    int descripteurFichier = open(nomFichier, O_WRONLY | O_CREAT | O_TRUNC, 0666);

    // Vérifie si l'ouverture du fichier a réussi
    if (descripteurFichier == -1) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;  // Quitte le programme avec un code d'erreur
    }

    // Redirige la sortie standard vers le fichier avec dup2
    if (dup2(descripteurFichier, fd_tab[1]) == -1) {
        perror("Erreur lors de la redirection de la sortie standard");
        return 1;  // Quitte le programme avec un code d'erreur
    }
	close(fd_tab[1]);
    // Affiche "salut" à l'écran avec printf (mais cela sera redirigé vers le fichier)
    printf("salut\n");

    // Ferme le fichier avec close (fermera également la sortie standard)
    close(descripteurFichier);
	dup2(fd_tab[1], STDOUT_FILENO);
    printf("test\n");
	close(fd_tab[0]);
	close(fd_tab[1]);

    return 0;  // Quitte le programme avec succès
}
