#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    static char template[] = "/mnt/c/Users/cicha/OneDrive/Bureau/projet c/myfileXXXXXX";
    char fname[1000];
    strcpy(fname, template);
    int fd = mkstemp(fname);

     printf("tst test tes ");
    return 0;
}

