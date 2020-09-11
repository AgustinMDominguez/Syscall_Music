#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
// aplay::  Unsigned 8 bit, Rate 8000 Hz, Mono

/*      pitch == tono
Las siguientes constantes definen la relacion de syscalls-to-pitch
si getDelta() devuelve MAX_D calls, getPitch() va a devolver MAX_P
si getDelta() devuelve MIN_D calls, getPitch() va a devolver MIN_P
y proporcional en todos los valores entre si */
#define MAX_D 30
#define MAX_P 10.0
#define MIN_D 1
#define MIN_P 0.5
#define PER2 1024 //Define el periodo en que se actualiza el delta de las syscalls

typedef unsigned long long ull;

ull SYS_HIST = 0;
int CPUS_AMOUNT = -1;
double CONST_A = (MAX_P-MIN_P) / (double)(MAX_D-MIN_D);
double CONST_B = MIN_P - (double)(MIN_D) * ((MAX_P-MIN_P) / (double)(MAX_D-MIN_D));

//Supone que el stdin son 39 int separados por espacios con los syscalls
void updateSysCalls() {
    unsigned int t;
    ull saux = 0ull;
    for(int i=0; i<36; ++i) {  //Si el makefile hace cut -d' ' f2-37, debe ser 36 (siempre 1 menos)
        scanf("%u", &t);
        saux += (ull)(t);
    }
    SYS_HIST = saux;
}

ull getDelta() {
    ull prev = SYS_HIST;
    updateSysCalls();
    return SYS_HIST-prev;
}

double getPitch() {
    ull delta = SYS_HIST;
    updateSysCalls();
    delta = SYS_HIST-delta;
    return CONST_A*delta  + CONST_B;
}

int main() {
    updateSysCalls();
    double d;
    int c;
    while (true) {
        d = (double)getDelta();
        //printf("pitch:%lf\n",d);
        for(int i=0; i<PER2; ++i) {
            c = (int)(d * (double)(i));
            c = c;
            putchar(c);
        }
    }
}
