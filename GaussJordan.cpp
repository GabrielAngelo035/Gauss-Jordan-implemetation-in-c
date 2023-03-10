#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#define SIZE 17

void Ler(float a[SIZE][SIZE],int n){
	FILE *Inputs;
	char s[2] = " ";
	char *token;
	char linha[70];
	int ler=0,i=1,j;
	int v;
	Inputs = fopen("Inputs.txt", "rt");
	if(Inputs == NULL){
		printf("\n Porblemas na abertura do arquivo");
	}
	printf("\n Matriz original : %d icognitas\n",n);
	
	while(!feof(Inputs)){
		fflush(stdin);
		fgets(linha, 70, Inputs);
		token = strtok(linha, s);
		if(strcmp(token,"numero")==0){
			token = strtok(NULL, s);
			v=atoi(token);
			if(v==n){
			ler=1;
			}
			fgets(linha, 70, Inputs);
			token = strtok(linha, s);
		}
		if(ler==1){
			for(j=1;j<=n+1;j++){
			a[i][j]= atof(token);token = strtok(NULL, s);
			printf("%.03f ",a[i][j]);
			}
			i++;
		}
		if(i==n+1)
		break;
	}
	printf("\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n+1;j++){
			printf(" %.03f",a[i][j]);
		}
		printf("\n");
	}
}

void Pivotar(int x,float a[SIZE][SIZE],int n){
	int maior=x,i,c,b;
	float aux;
	for(i=x;i<=n;i++){
		if((fabs(a[i][x])>fabs(a[x][x]))&&(fabs(a[i][x])>fabs(a[maior][x]))){
			maior=i;
		}
	}
	printf("\n |Maior pivo: %f |",a[maior][x]);
	for(i=1;i<=n+1;i++){
		aux = a[x][i];
		a[x][i]=a[maior][i];
		a[maior][i]=aux;
	}
	
		printf("\n |Pivotamento          |\n");
		for(c=1;c<=n;c++){
			for(b=1;b<=n+1;b++){
				printf(" %.04f ",a[c][b]);
				}
			printf("\n");
			}
}

void GaussJordan(float a[SIZE][SIZE],float x[SIZE], int n){
	int i,j,k,c,b;
	float ratio;
	
	 for(i=1;i<=n;i++){
	 	Pivotar(i,a,n);
			if(a[i][i] == 0.0){//verifica se tem 0 na diagonal principal
				printf("Mathematical Error!\n");
				if(a[i][n+1]!=0){
					printf("S.I!\n");
				}else if(a[i][n+1]==0){
					printf("S.P.I!\n");
				}
				return;
			}
			for(j=1;j<=n;j++){
				if(i!=j){
				ratio = a[j][i]/a[i][i];//quando i!=j ratio recebe a divisao do numero debaixo pelo de cima
					for(k=1;k<=n+1;k++){
					    a[j][k] = a[j][k] - ratio*a[i][k];//faz as operacoes em cada coluna da linha pelo ratio e vai ate n+1 para pegar o resultado 
					}
				}
			}
		printf("\n | Iteracao %d | \n",i);
		for(c=1;c<=n;c++){
			for(b=1;b<=n+1;b++){
				printf(" %.04f ",a[c][b]);
				}
			printf("\n");
			}
	    }
	    
		 /* Obtaining Solution */
		 for(i=1;i<=n;i++)
		 {
		  	x[i] = a[i][n+1]/a[i][i];
		 }
}

int main(){
	int op=-1;
	
		do{
		system("cls");
		printf(" Digite a quantidade de icognitas:");scanf("%d",&op);
		float a[SIZE][SIZE], x[SIZE];
		int i,j,k,n;
	
		Ler(a,op);
		n=op;
		 
		GaussJordan(a,x,n);
		
		printf("\n Solucao:\n");
		
		for(i=1;i<=n;i++){
		printf(" x[%d] = %0.6f\n",i, x[i]);
		}
		system("pause");
	}while(op!=0);
	
	return(0);
}
