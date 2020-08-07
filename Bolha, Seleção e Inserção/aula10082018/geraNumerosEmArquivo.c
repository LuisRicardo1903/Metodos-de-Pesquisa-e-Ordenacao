#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

int main() {
    long long int qtdNumeros;
    char qtd[100];
    FILE *procurador;
    char nomeArquivo[100];
    int numero;
    
    printf("Quantos numeros no arquivo? ");
    scanf("%llu",&qtdNumeros);
    strcpy(nomeArquivo,"numeros");
    sprintf(qtd, "%llu", qtdNumeros);
    strcat(nomeArquivo,qtd);
    strcat(nomeArquivo,".txt");

    printf("%s\n", nomeArquivo);
    
    procurador = fopen(nomeArquivo,"w");
    srand(time(NULL));
    for (; qtdNumeros > 0; qtdNumeros--) {
        numero = rand() % 1000;
        //printf("%llu -> %d\n", qtdNumeros, numero);
        fprintf(procurador,"%d\n",numero);
        fflush(procurador);
    }
    fclose(procurador);
    return 1;
}
