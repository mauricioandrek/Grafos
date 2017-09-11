#include <stdio.h>
#include <stdlib.h>

int menorCaminho(int verticeAtual, int matriz[5][8]) { //achar o menor caminho do grafo
	int menor = 1000, vertice = 0, j;
	
	for(j = 0; j < 8; j++) { //vai achar o menor valor na linha
		if((matriz[verticeAtual][j] < menor) && (matriz[verticeAtual][j] > 0)) {
			menor = matriz[verticeAtual][j];
			vertice = j;
		}
	}
	printf("menor>%d\n", menor);
	return vertice; //retorna a coluna com o menor valor
}

int achaLinha(int linha, int coluna, int matriz[5][8]) { //acha a linha para a proxima procura no menor caminho
	int valor = matriz[linha][coluna];
	int i, procura;

	procura = valor - valor*2;
	for(i = 0; i < 5; i++) {
		if(matriz[i][coluna] == procura) break;
	}
	
	return i;
}

int main() {
	int matriz[5][8] = {{30, 0, 0, 20, -15, 0, 0, 0},
                     {-30, 50, 0, 0, 0, -10, 0, 0},
                     {0, 0, 0, 0, 15, 10, 5, -10},
                     {0, 50, -30, 0, 0, 0, -5, 0},
                     {0, 0, 30, -20, 0, 0, 0, 10}};

	/*int matrizB[7][9] = {{2, 0, 12, 0, 0, 6, 0, 0, 0},
						 {-2, 1, 0, 0, 0, 0, 0, 0, 5},
						 {0, -1, 0, 40, 0, 0, 0, 0, 0},
						 {0, 0, 0, 0, 0, -6, 4, 0, 0},
						 {0, 0, -12, 0, 30, 0, 0, 0, 0},
						 {0, 0, 0, 0, 0, 0, -4, 8, -5},
						 {0, 0, 0, -40, -30, 0, 0,-8,0}};
	*/

	int vLidos = 0, tVertices = 5;
	int proxVertice = 0, verticeAtual, totalPercorido, linha;
	int jaPassou[5];
	

	while(vLidos < tVertices-1) {	
		verticeAtual = proxVertice; //linha
		jaPassou[vLidos] = verticeAtual;
		vLidos++;
			
		proxVertice = menorCaminho(verticeAtual,matriz); //retorna a coluna
		linha = achaLinha(verticeAtual, proxVertice, matriz); //linha, coluna, retorna o vertice
	
		proxVertice = linha;	
	}

	
	printf("Vertices Lidos: %d\n",vLidos);
	for(int i = 0; i < 4; i++){
		printf("Leu -> %d	", jaPassou[i]+1);
		if(i==0){
			totalPercorido+=matriz[0][jaPassou[i]];
		}else{
			totalPercorido+=matriz[jaPassou[i-1]][jaPassou[i]];	
		}		
	}	
	printf("\n\nTotal Percorido: %d\n",totalPercorido);

	return 0;
}
