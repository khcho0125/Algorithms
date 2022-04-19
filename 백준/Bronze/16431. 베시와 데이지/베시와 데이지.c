#include<stdio.h>
#include<stdlib.h>

int main() {
    int Nx, Ny, Mx, My, Kx, Ky, temp, temp2;
    scanf("%d %d %d %d %d %d", &Nx, &Ny, &Mx, &My, &Kx, &Ky);
    temp = abs(Nx - Kx) > abs(Ny - Ky) ? abs(Nx - Kx) : abs(Ny - Ky);
    temp2 = abs(Mx - Kx) + abs(My - Ky);
    if(temp > temp2) {
        printf("daisy");
    } else if(temp < temp2) {
        printf("bessie");
    } else {
        printf("tie");
    }
}
