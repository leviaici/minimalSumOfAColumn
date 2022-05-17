#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

void creareNumerePentruAssert(int (*numere)[3][2]) {
    srand(42);
    for(int i = 0; i < 3; i++) {
        int numar1 = (rand() % 10) + 1, numar2 = (rand() % 10) + 1;
        if(numar1 > numar2) {
            (*numere)[i][0] = numar1;
            (*numere)[i][1] = numar2;
        }else {
            (*numere)[i][0] = numar2;
            (*numere)[i][1] = numar1;
        }
    }
}
void creareFisier(int n, int k) {
    FILE *fout = fopen("exemplu.txt", "w");
    fprintf(fout, "%d %d", n, k);
    fclose(fout);
}
void afisareValoriGenerate(int numere[3][2]) {
    printf("Valori generate:\n");
    for(int i = 0; i < 3; i++)
        printf("%d %d\n",numere[i][0], numere[i][1]);
    puts("");
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

void verificare(int n, int k, int **a) {
    int numar = k;
    for(int i = 0; i < n; i++) {
        assert(a[i][k - 1] == numar);
        numar += k;
    }
}

int main() {
    int n, k, **a, numere[3][2];
    creareNumerePentruAssert(&numere);
    afisareValoriGenerate(numere);
    for(int i = 0; i < 3; i++) {
        n = numere[i][0]; k = numere[i][1];
        creareFisier(n, k);
        citire(&n, &k);
        alocare(n, &a);
        creare(n, k, &a);
        verificare(n, k, a);
        assert(k == numere[i][1] && a[0][k - 1] == k);
        afisare(n, a);
        dezalocare(n, &a);
    }
    return 0;
}
