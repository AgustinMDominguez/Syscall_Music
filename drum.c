#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h> //for usleep()

#define PER 1000 //microsegundos :: 1s = 1000000 (1e6) microsegundos

void shift_volume(int volume) {
    FILE * f = NULL;
    char c;
    int rate = (double)volume / (double)100.0f;
    int output;
    while (true) {
        f = fopen("/proc/stat", "r");
        c = fgetc(f);
        while(c!=EOF) {
            output = (int)(rate * (double)c);
            putchar(output);
            c = fgetc(f);
        }
        putchar(c);
        fclose(f);
        usleep(PER);
    }
}

int main(int argc, char *argv[]) {
    int volume;
    if(argc!=2) {
        volume = 100;
    }
    else {
        volume = atoi(argv[1]);
    }
    shift_volume(volume);
}
