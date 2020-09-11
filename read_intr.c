#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h> //for usleep()

#define PER 1000 //microsegundos :: 1s = 1000000 (1e6) microsegundos

int main() {
    FILE * f = NULL;
    char c;
    while (true) {
        f = fopen("/proc/stat", "r");
        c = fgetc(f);
        while(c!=EOF) {
            putchar(c);
            c = fgetc(f);
        }
        putchar(c);
        fclose(f);
        usleep(PER);
    }
}
