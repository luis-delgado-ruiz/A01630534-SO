#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int pid = fork();
    if (pid == 0) {
        printf("soy el hijo");
    }
    else {
        printf("Soy el padre");
    }

}