#include <stdio.h>
#include <stdlib.h>

void testaRefleIrrefle(int matriz[][50], int num_elementos, int elementos[], int *reflexiva) {
	int i, elementos_Reflexivos, elementos_Irreflexivos;
	int tuplas_Reflexivas[50][2], tuplas_Irreflexivas[50][2];
	elementos_Reflexivos = 0;
	elementos_Irreflexivos = 0;
	*reflexiva = 1;

	for(i = 0; i < num_elementos; i++) {
		if(matriz[i][i] == 1) {
			tuplas_Irreflexivas[elementos_Irreflexivos][0]= elementos[i];
			tuplas_Irreflexivas[elementos_Irreflexivos][1]= elementos[i];
			elementos_Irreflexivos++;	
		}
		else {
			tuplas_Reflexivas[elementos_Reflexivos][0]= elementos[i];
			tuplas_Reflexivas[elementos_Reflexivos][1]= elementos[i];
			elementos_Reflexivos++;
		}
	}
	if(elementos_Reflexivos > 0) {
		*reflexiva=0;
		printf("1. Reflexiva: F\n");
		for(i = 0; i < elementos_Reflexivos; i++) {
			printf("(%d,", tuplas_Reflexivas[i][0]);
			printf("%d); ", tuplas_Reflexivas[i][1]);
		}
		printf("\n");
	}
	else {
		printf("1. Reflexiva: V\n");
	}	
	if(elementos_Irreflexivos > 0) {
		printf("2. Irreflexiva: F\n");
		for(i = 0; i < elementos_Irreflexivos; i++) {
			printf("(%d,", tuplas_Irreflexivas[i][0]);
			printf("%d); ", tuplas_Irreflexivas[i][1]);
		}
		printf("\n");
	}
	else {
		printf("2. Irreflexiva: V\n");
	}	
}


void testaSimetriAntisimetriAssi(int matriz[][50], int num_elementos, int elementos[], int *simetrica, int *antisimetrica) {
	int i, j, elementos_Simetricos, elementos_Antisimetricos, elementos_Assimetricos;
	int tuplas_Simetricas[2500][2], tuplas_Antisimetricas[2500][2];
	elementos_Simetricos = 0;
	elementos_Antisimetricos = 0;
	elementos_Assimetricos = 0;
	*simetrica = 1;
	*antisimetrica = 1;

	for(i = 0; i < num_elementos; i++) {
		for(j = 0; j < num_elementos; j++) {
			if((matriz[i][j] == matriz[j][i]) && matriz[i][j] == 1) {
				if(i < j) {
					tuplas_Antisimetricas[elementos_Antisimetricos][0] = elementos[i];
					tuplas_Antisimetricas[elementos_Antisimetricos][1] = elementos[j];
					elementos_Antisimetricos++;
					tuplas_Antisimetricas[elementos_Antisimetricos][0] = elementos[j];
					tuplas_Antisimetricas[elementos_Antisimetricos][1] = elementos[i];
					elementos_Assimetricos++;
				}
				else {
					elementos_Assimetricos++;
				}
				
			}
			else if((matriz[i][j] != matriz[j][i]) && matriz[i][j] == 0) {
				tuplas_Simetricas[elementos_Simetricos][0]=elementos[i];
				tuplas_Simetricas[elementos_Simetricos][1]=elementos[j];
				elementos_Simetricos++;
			}
		}
	}
	if(elementos_Simetricos > 0) {
		*simetrica = 0;
		printf("3. Simetrica: F\n");
		for(i = 0; i < elementos_Simetricos; i++) {
			printf("(%d,", tuplas_Simetricas[i][0]);
			printf("%d); ", tuplas_Simetricas[i][1]);
		}
		printf("\n");
	}
	else {
		printf("3. Simetrica: V\n");
	}	
	if(elementos_Antisimetricos > 0) {
		*antisimetrica = 0;
		printf("4. Anti-simetrica: F\n");
		for(i = 0; i < elementos_Antisimetricos; i++) {
			printf("(%d,", tuplas_Antisimetricas[i][0]);
			printf("%d) e ", tuplas_Antisimetricas[i][1]);
			printf("(%d,", tuplas_Antisimetricas[i][1]);
			printf("%d); ", tuplas_Antisimetricas[i][0]);
		}
		printf("\n");
	}
	else {
		printf("4. Anti-simetrica: V\n");
	}	
	if(elementos_Assimetricos > 0) {
		printf("5. Assimetrica: F\n");
	}
	else {
		printf("5. Assimetrica: V\n");
	}
}

void testaTransitiva(int matriz[][50], int num_elementos, int elementos[], int *transitiva) {
	int i, j, k, elementos_Transitivos, repetirTransitiva, matrizcopia[50][50];
	int tuplas_Transitivas[2500][2], copia_tuplasTrans[2500][2];
	elementos_Transitivos = 0;
	*transitiva = 1;
	for(i = 0; i < num_elementos; i++) {
		for(j = 0; j < num_elementos; j++) {
			for(k = 0; k < num_elementos; k++) {
				if((matriz[i][j] == 1) && (matriz[j][k] == 1)) {
					if(matriz[i][k] == 0) {
						tuplas_Transitivas[elementos_Transitivos][0] = i;
						tuplas_Transitivas[elementos_Transitivos][1] = k;
						elementos_Transitivos++;
					}
				}
			}
		}
	}
	repetirTransitiva=1;
	for(i = 0; i < num_elementos; i++) {
		for(j = 0; j < num_elementos; j++) {
			matrizcopia[i][j] = matriz[i][j];
		}
	}
	while(repetirTransitiva == 1) {
		int entrounoIf;
		entrounoIf = 0;
		for(i = 0; i < elementos_Transitivos; i++) {
			matrizcopia[tuplas_Transitivas[i][0]][tuplas_Transitivas[i][1]] = 1;	
		}
		for(i = 0; i < num_elementos; i++) {
			for(j = 0; j < num_elementos; j++) {
				for(k = 0; k < num_elementos; k++) {
					if((matrizcopia[i][j] == 1) && (matrizcopia[j][k] == 1)) {
						if(matrizcopia[i][k] == 0) {
							tuplas_Transitivas[elementos_Transitivos][0] = i;
							tuplas_Transitivas[elementos_Transitivos][1] = k;
							elementos_Transitivos++;
							matrizcopia[i][k] = 1;
							entrounoIf = 1;
						}
					}
				}
			}
		}
		repetirTransitiva=entrounoIf;	
	}	
	if(elementos_Transitivos > 0) {
		*transitiva = 0;
		printf("6. Transitiva: F\n");
		for(i = 0; i < elementos_Transitivos; i++) {
			printf("(%d,", elementos[tuplas_Transitivas[i][0]]);
			printf("%d); ", elementos[tuplas_Transitivas[i][1]]);
		}
		printf("\n");
	}
	else {
		printf("6. Transitiva: V\n");
	}
}

void testaEquivalencia(int *reflexiva, int *simetrica, int *transitiva) {
	if(*reflexiva == 1) {
		if(*simetrica == 1) {
			if(*transitiva == 1) {
				printf("Relacao de equivalencia: V\n");	
			}
			else {
				printf("Relacao de equivalencia: F\n");
			}
		}
		else {
			printf("Relacao de equivalencia: F\n");
		}
	}
	else {
		printf("Relacao de equivalencia: F\n");
	}
}

void testaParcial(int *reflexiva, int *antisimetrica, int *transitiva) {
	if(*reflexiva == 1) {
		if(*antisimetrica == 1) {
			if(*transitiva == 1) {
				printf("Relacao de ordem parcial: V\n");	
			}
			else {
				printf("Relacao de ordem parcial: F\n");
			}
		}
		else {
			printf("Relacao de ordem parcial: F\n");
		}	
	}
	else {
		printf("Relacao de ordem parcial: F\n");
	}
}

void fechoReflexivo(int matriz[][50], int num_elementos, int tuplas[][2], int elementos[], int num_tuplas) {
	int i, elementos_Reflexivos;
	int tuplas_Reflexivas[50][2];
	elementos_Reflexivos = 0;

	for(i = 0; i < num_elementos; i++) {
		if(matriz[i][i] == 0) {
			tuplas_Reflexivas[elementos_Reflexivos][0] = elementos[i];
			tuplas_Reflexivas[elementos_Reflexivos][1] = elementos[i];
			elementos_Reflexivos++;
		}
	}
	printf("Fecho reflexivo da relacao = {");
	for(i = 0; i < num_tuplas; i++) {
		printf("(%d,", tuplas[i][0]);
		printf("%d),", tuplas[i][1]);
		
	}
	for(i = 0; i < elementos_Reflexivos; i++) {
		printf("(%d,", tuplas_Reflexivas[i][0]);
		printf("%d),", tuplas_Reflexivas[i][1]);
	}
	printf("\b");
	printf("}");
	printf("\n");
}

void fechoSimetrico(int matriz[][50], int num_elementos, int tuplas[][2], int elementos[], int num_tuplas) {
	int i, j, elementos_Simetricos;
	int tuplas_Simetricas[2500][2];
	elementos_Simetricos = 0;

	for(i = 0;i < num_elementos; i++) {
		for(j = 0; j < num_elementos; j++) {
			if((matriz[i][j] != matriz[j][i]) && matriz[i][j] == 0) {
				tuplas_Simetricas[elementos_Simetricos][0] = elementos[i];
				tuplas_Simetricas[elementos_Simetricos][1] = elementos[j];
				elementos_Simetricos++;
			}
		}
	}
	printf("Fecho simetrico da relacao = {");
	for(i = 0; i < num_tuplas; i++) {
		printf("(%d,", tuplas[i][0]);
		printf("%d),", tuplas[i][1]);
	}
	for(i = 0; i < elementos_Simetricos; i++) {
		printf("(%d,", tuplas_Simetricas[i][0]);
		printf("%d),", tuplas_Simetricas[i][1]);
	}
	printf("\b");
	printf("}");
	printf("\n");
}

void fechoTransitivo(int matriz[][50], int num_elementos, int tuplas[][2], int elementos[], int num_tuplas) {
	int i, j, k, elementos_Transitivos, repetirTransitiva, matrizcopia[50][50];
	int tuplas_Transitivas[2500][2], copia_tuplasTrans[2500][2];
	elementos_Transitivos = 0;

	for(i = 0; i < num_elementos; i++) {
		for(j = 0; j < num_elementos; j++) {
			for(k = 0; k < num_elementos; k++) {
				if((matriz[i][j] == 1) && (matriz[j][k] == 1)) {
					if(matriz[i][k] == 0) {
						tuplas_Transitivas[elementos_Transitivos][0] = i;
						tuplas_Transitivas[elementos_Transitivos][1] = k;
						elementos_Transitivos++;
					}
				}
			}
		}
	}
	repetirTransitiva=1;
	for(i = 0; i < num_elementos; i++) {
		for(j = 0; j < num_elementos; j++) {
			matrizcopia[i][j] = matriz[i][j];
		}
	}
	while(repetirTransitiva == 1) {
		int entrounoIf;
		entrounoIf = 0;
		for(i = 0; i < elementos_Transitivos; i++) {
			matrizcopia[tuplas_Transitivas[i][0]][tuplas_Transitivas[i][1]] = 1;	
		}
		for(i = 0; i < num_elementos; i++) {
			for(j = 0; j < num_elementos; j++) {
				for(k = 0; k < num_elementos; k++) {
					if((matrizcopia[i][j] == 1) && (matrizcopia[j][k] == 1)) {
						if(matrizcopia[i][k] == 0) {
							tuplas_Transitivas[elementos_Transitivos][0] = i;
							tuplas_Transitivas[elementos_Transitivos][1] = k;
							elementos_Transitivos++;
							matrizcopia[i][k] = 1;
							entrounoIf = 1;
						}
					}
				}
			}
		}
		repetirTransitiva = entrounoIf;	
	}
	printf("Fecho transitivo da relacao = {");
	for(i = 0; i < num_tuplas; i++) {
		printf("(%d,", tuplas[i][0]);
		printf("%d),", tuplas[i][1]);
		
	}
	for(i = 0; i < elementos_Transitivos; i++) {
		printf("(%d,", elementos[tuplas_Transitivas[i][0]]);
		printf("%d),", elementos[tuplas_Transitivas[i][1]]);
	}
	printf("\b");
	printf("}");
	printf("\n");
	
}

int main(int argc, char *argv[]) {
	
	FILE *arq;
	int i, j, k, num_tuplas=0;
	int posicaoX, posicaoY;
	int num_elementos, elementos[50], tuplas[2500][2], matriz[50][50];
	int reflexiva, simetrica, antisimetrica, transitiva;
	
	//lendo arquivo 
	arq=fopen("R1.txt", "r"); 
	if((arq == NULL) || (arq == 0)) {
		printf("Erro: Nome de arquivo nao correspondente ou retorno nulo/zero.");
	}
			
	//zerando matriz
	for(i = 0; i < 50; i++) {
		for(j = 0; j < 50; j++) {
			matriz[i][j] = 0;
		}
	}
		
	//pegando o numero de elementos
	fscanf(arq, "%d", &num_elementos);
		
	//colocando os elementos em um vetor
	for(i = 0; i < num_elementos; i++) {
		fscanf(arq, "%d", &elementos[i]);
	}
			
	//colocando as relacoes em uma matriz
	for(i = 0; !feof(arq); i++) {
		for(j = 0; j < 2; j++) {
			fscanf(arq, "%d", &tuplas[i][j]);
		}
		num_tuplas++;
	}
			
	//achando posicao da matriz para as relacoes
	for(i = 0; i < num_tuplas; i++) {
		posicaoX=0;
		posicaoY=0;
		for(k = 0; k < num_elementos; k++) {
			if(tuplas[i][0] == elementos[k]) {
				posicaoX = k;
			}
			if(tuplas[i][1] == elementos[k]) {
				posicaoY = k;
			}
		}
		matriz[posicaoX][posicaoY] = 1;
	}

	//PROPRIEDADES
	printf("Propriedades\n");
	//reflexiva e irreflexiva
	testaRefleIrrefle(matriz, num_elementos, elementos, &reflexiva);
	//simetrica, anti-simetrica e assimetrica
	testaSimetriAntisimetriAssi(matriz, num_elementos, elementos, &simetrica, &antisimetrica);
	//transitiva
	testaTransitiva(matriz, num_elementos, elementos, &transitiva);
	printf("\n");
	//equivalencia
	testaEquivalencia(&reflexiva, &simetrica, &transitiva);
	//ordem parcial
	testaParcial(&reflexiva, &antisimetrica, &transitiva);
	printf("\n");
	//fecho reflexivo
	fechoReflexivo(matriz, num_elementos, tuplas, elementos, num_tuplas);
	//fecho simetrico
	fechoSimetrico(matriz, num_elementos, tuplas, elementos, num_tuplas);
	//fecho transitivo
	fechoTransitivo(matriz, num_elementos, tuplas, elementos, num_tuplas);
	
	return 0;
}
