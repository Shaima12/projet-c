#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* sha256file(char* file)
{ 
    char command[200]; 
    char *h = (char *)malloc(65 * sizeof(char));
    strcpy(command, "sha256sum < \"");
    strcat(command, file); 
    strcat(command, "\""); 
    FILE* hash = popen( command ,"r"); 
    fgets(h,65,hash);
    pclose(hash);
    return h ; 
}



int main() { 
    char* file = "/mnt/c/Users/cicha/OneDrive/Bureau/projet c/tt.c";
    char* hash=sha256file(file);
    printf("%s\n", hash);
    }
