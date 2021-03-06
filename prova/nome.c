#include<stdio.h>
#include<stdlib.h>


int EstaOrdemCrescente(int vetor[], int tamanho) {
    for (int i = 1; i < tamanho; i++) 
    	if (vetor[i - 1] > vetor[i]) 
    		return 0;
    return 1; 
 }

 int EstaOrdemDecrescente(int vetor[], int tamanho) {
    for (int i = tamanho/2 + 1; i < tamanho; i++) 
    	if (vetor[i - 1] < vetor[i]) 
    		return 0;
    return 1; 
 }


int main(){

	int n[100000],m[100000],achou[100000], tamvet=0,tambusca=0,i,j,k, flag,certo;
	scanf("%d",&tamvet);

	for(i = 0; i<tamvet; i++){
		scanf("%d",&n[i]);
	}

	if(EstaOrdemCrescente(n,tamvet/2) != 1){
		exit(1);
	}

	if(EstaOrdemDecrescente(n,tamvet) != 1){
		exit(1);
	}

	scanf("%d",&tambusca);

	i = 0;
	k = 0;

	for(j = 0; j<tambusca; j++){

		flag = 0;
		scanf("%d",&m[j]);
		
		while(i < tamvet){
			if(m[j] == n[i]){
				flag = 1;
				achou[k] = i;
				k++;
				break;
			}
			else{
				i++;
			}
		}
		if(flag != 1){
			achou[k] = -1;
			k++;
		}

		i = 0;
	}

	k = 0;
	i = 0;
	for(i = 0; i<tambusca; i++){
		printf("%d ",achou[k]);
		k++;
	}

	return 0;
}