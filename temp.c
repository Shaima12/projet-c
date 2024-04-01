#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    static char template[] = "/mnt/c/Users/cicha/OneDrive/Bureau/projet c/myfileXXXXXX";
    char fname[1000];
    strcpy(fname, template);
    int fd = mkstemp(fname);
    printf("Le chemin du fichier temporaire est : %s\n", fname);
FILE* file = fopen(fname, "w");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier temporaire");
        return 1;
    }
    fputs("Hello, world!\n", file);
    fclose(file);
 file = fopen(fname, "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier temporaire pour la lecture");
        return 1;
    }
    FILE* cmd_output = popen("cat", "w");
    fputs(fname, cmd_output);
    fclose(cmd_output);
    cmd_output = popen("cat", "r");
    char h[65]; 
    if (fgets(h, sizeof(h), cmd_output) == NULL) {
        pclose(cmd_output);
    }   
    pclose(cmd_output);
    printf("Contenu du fichier temporaire : %s\n", h);
    return 0 ;
}

