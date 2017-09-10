#include <stdio.h>
#include <stdlib.h>

int totalPercorido=0;
int caminhoMenor(int verticeAtual,int matriz[5][5]){
	int menor=1000;
	int vertice=0;
	for(int i=0;i<5;i++){
		if(matriz[verticeAtual][i]<menor){
			if(matriz[verticeAtual][i]>0){
			menor= matriz[verticeAtual][i];
			vertice = i;	
			}			
		}
	}
	return vertice;
}
int caminhoMenorB(int verticeAtual,int matriz[7][7]){
	int menor=1000;
	int vertice=0;
	for(int i=0;i<7;i++){
		if(matriz[verticeAtual][i]<menor){
			if(matriz[verticeAtual][i]>0){
			menor= matriz[verticeAtual][i];
			vertice = i;	
			}			
		}
	}
	return vertice;
}
int main(int argc, char *argv[]) {
	int matriz[5][5];
	int jaPassou[5];
	int countVerticesLidos=0;
	int verticeAtual;
	
	matriz[0][0]=0;
	matriz[0][1]=30;
	matriz[0][2]=-15;
	matriz[0][3]=0;
	matriz[0][4]=20;
	
	matriz[1][0]=-30;
	matriz[1][1]=0;
	matriz[1][2]=-10;
	matriz[1][3]=50;
	matriz[1][4]=0;
	
	matriz[2][0]=15;	
	matriz[2][1]=10;
	matriz[2][2]=0;
	matriz[2][3]=5;
	matriz[2][4]=-10;
	
	matriz[3][0]=0;
	matriz[3][1]=50;
	matriz[3][2]=-5;
	matriz[3][3]=0;
	matriz[3][4]=-30;
	
	matriz[4][0]=-20;
	matriz[4][1]=0;
	matriz[4][2]=10;
	matriz[4][3]=30;
	matriz[4][4]=0;
	
	// Vertices
	// 1 -> 0
	// 2 -> 1
	// 3 -> 2
	// 4 -> 3
	// 5 -> 4
	// Começa pelo vertice 1
	int totalVertices = 5;
	int proximoVertice = 0;
	while(countVerticesLidos<totalVertices){
		//printf("\n-> %d \n",proximoVertice+1);
		verticeAtual = proximoVertice;
		jaPassou[countVerticesLidos]=verticeAtual;
		countVerticesLidos++;
		proximoVertice = caminhoMenor(verticeAtual,matriz);
	}
	
	printf("Resultados 1: \n");
	printf("Vertices Lidos: %d\n",countVerticesLidos);
	for(int i=0;i< 5;i++){
		printf("Leu -> %d	", jaPassou[i]+1);
		if(i==0){
			totalPercorido+=matriz[0][jaPassou[i]];
		}else{
			totalPercorido+=matriz[jaPassou[i-1]][jaPassou[i]];	
		}		
	}	
	printf("\n\nTotal Percorido: %d\n",totalPercorido);		
	
	// Vertices
	// Inicio -> 0
	// 2 -> 1
	// 3 -> 2
	// 4 -> 3
	// 5 -> 4
	// 6 -> 5
	// Objetivo -> 6
	// Começa pelo vertice 1 (Inicio)
	int matrizB[7][7];
	int *jaPassouB;
	jaPassouB = (int *) malloc(1 * sizeof(int));
	countVerticesLidos=0;
	verticeAtual=0;
	
	matrizB[0][0]=0;
	matrizB[0][1]=2;
	matrizB[0][2]=0;
	matrizB[0][3]=6;
	matrizB[0][4]=12;
	matrizB[0][5]=0;
	matrizB[0][6]=0;
	
	matrizB[1][0]=-2;
	matrizB[1][1]=0;
	matrizB[1][2]=1;
	matrizB[1][3]=0;
	matrizB[1][4]=0;
	matrizB[1][5]=5;
	matrizB[1][6]=0;
	
	matrizB[2][0]=0;
	matrizB[2][1]=-1;
	matrizB[2][2]=0;
	matrizB[2][3]=0;
	matrizB[2][4]=0;
	matrizB[2][5]=0;
	matrizB[2][6]=40;
	
	matrizB[3][0]=-6;
	matrizB[3][1]=0;
	matrizB[3][2]=0;
	matrizB[3][3]=0;
	matrizB[3][4]=0;
	matrizB[3][5]=4;
	matrizB[3][6]=0;
	
	matrizB[4][0]=-12;
	matrizB[4][1]=0;
	matrizB[4][2]=0;
	matrizB[4][3]=0;
	matrizB[4][4]=0;
	matrizB[4][5]=0;
	matrizB[4][6]=30;
	
	matrizB[5][0]=0;
	matrizB[5][1]=-5;
	matrizB[5][2]=0;
	matrizB[5][3]=-4;
	matrizB[5][4]=0;
	matrizB[5][5]=0;
	matrizB[5][6]=8;
	
	matrizB[6][0]=0;
	matrizB[6][1]=0;
	matrizB[6][2]=-40;
	matrizB[6][3]=0;
	matrizB[6][4]=-30;
	matrizB[6][5]=-8;
	matrizB[6][6]=0;
	
	
	proximoVertice = 0;
	countVerticesLidos=0;
	verticeAtual=0;
	totalPercorido=0;
	while(verticeAtual!=6){
		//printf("\nLendo -> %d \n",proximoVertice+1);
		verticeAtual = proximoVertice;
		if(countVerticesLidos!=0){
			jaPassouB = (int *) realloc(jaPassouB,countVerticesLidos * sizeof(int*));	
		}
		jaPassouB[countVerticesLidos]=verticeAtual;
		countVerticesLidos++;		
		proximoVertice = caminhoMenorB(verticeAtual,matrizB);
	}
	
	printf("\n\n\nResultados 2: \n");
	printf("Vertices Lidos: %d\n",countVerticesLidos);
	for(int i=0;i< countVerticesLidos ;i++){
		if(jaPassouB[i]==0){
			printf("Leu -> Inicio	");	
		}else if(jaPassouB[i]==6){
			printf("Leu -> Objetivo	");	
		}else{
			printf("Leu -> %d	", jaPassouB[i]+1);	
		}
	
				
		if(i==0){
			totalPercorido+=matrizB[0][jaPassouB[i]];
		}else{
			totalPercorido+=matrizB[jaPassouB[i-1]][jaPassouB[i]];	
		}		
	}	
	printf("\n\nTotal Percorido: %d\n",totalPercorido);
	
	return 0;
	
}
