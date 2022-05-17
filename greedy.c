#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void creareNumerePentruAssert(int *n, int *k) {
    srand(time(NULL));
    int numar1 = (rand() % 10) + 1, numar2 = (rand() % 10) + 1;
    if(numar1 > numar2) {
        *n = numar1;
        *k = numar2;
    }else {
        *n = numar2;
        *k = numar1;
    }
}
void creareFisier(int n, int k) {
    FILE *fout = fopen("exemplu.txt", "w");
    fprintf(fout, "%d %d", n, k);
    fclose(fout);
}

void citire(int *n, int *k) {
    FILE *fin = fopen("exemplu.txt", "r");
    fscanf(fin, "%d", n);
    fscanf(fin, "%d", k);
    fclose(fin);
}

void alocare(int n, int ***a) {
    *a = (int**)malloc(n * sizeof(int*)) ;
    for(int i = 0; i < n; i++)
        (*a)[i] = (int*)malloc(n * sizeof(int)) ;
}
void dezalocare(int n, int ***a) {
    for(int i = 0; i < n; i++)
        free((*a)[i]);
    free(*a);
    *a = NULL;
}

void creare(int n, int k, int ***a) {
    int numar = 1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < k; j++)
            (*a)[i][j] = numar++;

    for(int i = 0; i < n; i++)
        for(int j = k; j < n; j++)
            (*a)[i][j] = numar++;
}

void afisare(int n, int **a) {
    for(int i = 0; i < n; i++, puts(""))
        for(int j = 0; j < n; j++)
            printf("%d ",a[i][j]);
    puts("");
}

int main() {
    int n, k, **a;
    creareNumerePentruAssert(&n, &k);
    creareFisier(n, k);
    citire(&n, &k);
    alocare(n, &a);
    creare(n, k, &a);
    afisare(n, a);
    dezalocare(n, &a);
    return 0;
}
