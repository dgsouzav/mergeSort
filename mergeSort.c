#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void merge(int *V, int inicio, int meio, int fim){
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim - inicio + 1; // tamanho do vetor temporário
    p1 = inicio; // primeiro elemento do primeiro vetor
    p2 = meio + 1;  // primeiro elemento do segundo vetor
    temp = (int *) malloc(tamanho * sizeof(int));  // aloca o vetor temporário

    if(temp != NULL) {
        for(i = 0; i < tamanho; i++) {
            
            // se não chegou ao final de nenhum dos vetores
            if(!fim1 && !fim2) {
                if(V[p1] < V[p2]) // compara os elementos 
                    temp[i] = V[p1++]; // copia o elemento do primeiro vetor
                else
                    temp[i] = V[p2++];  // copia o elemento do segundo vetor
                
            
                // verifica se chegou ao final de algum dos vetores
                if(p1 > meio) fim1 = 1;
                if(p2 > fim) fim2 = 1;
            
            
            } else {
            
                // se chegou ao final de um dos vetores, copia os elementos do outro vetor
                if(!fim1)
                    temp[i] = V[p1++]; 
                else
                    temp[i] = V[p2++];
            
            
            }
        }
        
        // copiar o vetor temporário para o vetor original
        for(j = 0, k = inicio; j < tamanho; j++, k++)  
            V[k] = temp[j];
    
    
    }
    free(temp);
}

void mergeSort(int *V, int inicio, int fim) {  // ordena o vetor V entre os índices inicio e fim
    int meio;
    if (inicio < fim) { // se o vetor tiver mais de um elemento
        meio = floor((inicio + fim) / 2); // calcula o meio do vetor	
        mergeSort(V, inicio, meio); // ordena a primeira metade
        mergeSort(V, meio + 1, fim); // ordena a segunda metade
        merge(V, inicio, meio, fim); // intercala as duas metades ordenadas
    }
}

int main() {
    int V[10] = {7, 10, 8, 1, 4, 9, 6, 5, 2, 3};
    int i;
    mergeSort(V, 0, 9);
    for(i = 0; i < 10; i++)
        printf("%d ", V[i]);
    return 0;
}