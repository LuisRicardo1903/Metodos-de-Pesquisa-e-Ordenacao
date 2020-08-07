#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

clock_t tempoInicio, tempoFim;
long long int qtdComparacoes, qtdTrocas;

void populaVetor(int v[], char *nomeArquivo) {
	long long int i;
    FILE *procurador = fopen(nomeArquivo,"r");
    i = 0;
    do {
        if (feof(procurador)) break;

        fscanf(procurador,"%d", &v[i]);
        i++;
    } while (1);

    fclose(procurador);
}

void exibirVetor(int v[], long long int n) {
	long long int i;

	for (i = 0; i < n; i = i + 1) {
		printf("%llu - %d\n", i, v[i]);
	}
	printf("\n\n");
}

void ordenaSelecao(int *v, long long int n) {
	long long int i, j, posMenor;
	int tmp; //para as trocas


	qtdComparacoes = 0;
	qtdTrocas = 0;

	for (i = 0; i < n-1; i++) {
		posMenor = i;
		for (j = i+1; j < n; j++) {
			qtdComparacoes++;
			if (v[j] < v[posMenor]) posMenor = j;
		}
		if (i != posMenor) {
			tmp = v[i];
			v[i] = v[posMenor];
			v[posMenor] = tmp;
			qtdTrocas++;
		}
	}
	printf("Selecao\nQuantidade Comparacoes: %llu\nQuantidade Trocas: %llu\n", qtdComparacoes, qtdTrocas);
}

void ordenaInsercao(int *v, long long int n) {
	long long i, j;
	int tmp; //para as troca
	qtdComparacoes = 1;
	qtdTrocas = 0;
	for (i = 1; i < n; i++) {
		tmp = v[i];
		qtdComparacoes++;
		for (j = i-1; j >= 0 && tmp < v[j]; j--) {
			v[j+1] = v[j];
			qtdComparacoes++;
			qtdTrocas++;
		}
		v[j+1] = tmp;
		qtdTrocas++;
	}
	printf("Insercao\nQuantidade Comparacoes: %llu\nQuantidade Trocas: %llu\n", qtdComparacoes, qtdTrocas);
}

void ordenaBolha(int *v, long long int n) {
	long long int i;
	int houveTroca, tmp;

	qtdComparacoes = 0;
	qtdTrocas = 0;

	do {
		houveTroca = 0; //marca que nao houveTroca
		for (i = 0; i < n - 1; i++) {
			qtdComparacoes++;
			if (v[i] > v[i + 1]) {
				tmp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = tmp;
				houveTroca = 1;
				qtdTrocas++;
			}
		}
	} while (houveTroca);

	printf("Bolha\nQuantidade Comparacoes: %llu\nQuantidade Trocas: %llu\n", qtdComparacoes, qtdTrocas);
}

int existeArquivo(char *nomeArquivo) {
    FILE *procurador = fopen(nomeArquivo, "r");
    if (!procurador) return 0;

    fclose(procurador);
    return 1;
}

long long int contaNumerosArquivo(char *nomeArquivo) {
    FILE *procurador = fopen(nomeArquivo, "r");
    long long int contador = 0;
    char linha[100];
    do {
        fgets(linha,100,procurador);

        if (feof(procurador)) break;

        contador++;
    } while(1);

    fclose(procurador);

    return contador;
}
int main(int argc, char **argv) {

	long long int quantidade, i;

	//if (argc != 2) {
	//	printf("O segundo argumento deve ser o nome do arquivo com os numeros\n");
	//	exit(0);
//	}

    char nomeArquivo[100];
    printf("Digite o nome do arquivo: ");
    gets(nomeArquivo);

    if (!existeArquivo(nomeArquivo)) {
        printf("Arquivo nao localizado\n\n");
        exit(0);
    }

	quantidade = contaNumerosArquivo(nomeArquivo);
	int vetorSelecao[quantidade];
	int vetorInsercao[quantidade];
	int vetorBolha[quantidade];

	//popula vetor com numeros do arquivo
	populaVetor(vetorSelecao, nomeArquivo);

	for (i = 0; i < quantidade; i++) {
		vetorInsercao[i] = vetorSelecao[i];
		vetorBolha[i] = vetorSelecao[i];
		//printf("%llu - %d\n", i,vetorSelecao[i]);
	}
	printf("\n\n");

	printf("\n\nOrdenando ...");
	tempoInicio = clock();
	ordenaSelecao(vetorSelecao, quantidade);
    tempoFim = clock();
	printf("Tempo: %f\n", (float)(tempoFim - tempoInicio)/CLOCKS_PER_SEC);

	printf("\n\nOrdenando ...");
	tempoInicio = clock();
	ordenaBolha(vetorBolha, quantidade);
    tempoFim = clock();
	printf("Tempo: %f\n", (float)(tempoFim - tempoInicio)/CLOCKS_PER_SEC);

	printf("\n\nOrdenando ...");
	tempoInicio = clock();
	ordenaInsercao(vetorInsercao, quantidade);
    tempoFim = clock();
	printf("Tempo: %f\n", (float)(tempoFim - tempoInicio)/CLOCKS_PER_SEC);

	return 1;
}











