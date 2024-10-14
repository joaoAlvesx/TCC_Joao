#include <iostream>
#include <windows.h>

#define P -50
#define L -60
#define O 999
#define D 0
#define tamanho 20

using namespace std;

int cenario [tamanho][tamanho] = 
{
	{P,P,P,P,P,P,P,P,P,P,P,P,P,P,P,P,P,P,P,P},
	{P,O,P,L,P,L,P,L,L,L,P,L,P,L,L,L,L,L,L,P},
	{P,L,P,L,P,L,P,L,L,L,P,L,P,L,L,L,L,L,L,P},
	{P,L,P,L,P,L,L,L,L,L,P,L,L,L,P,P,L,L,L,P},
	{P,L,P,L,P,L,P,L,L,L,P,L,P,L,L,P,L,L,L,P},
	{P,L,P,L,P,L,P,L,L,L,P,L,P,L,L,P,L,L,L,P},
	{P,L,P,L,L,L,P,L,L,L,P,L,P,L,L,P,L,L,L,P},
	{P,L,P,L,P,L,L,L,L,L,P,L,P,L,L,P,L,L,L,P},
	{P,L,P,L,P,L,L,L,L,L,P,L,P,L,L,L,P,L,L,P},
	{P,L,P,L,P,L,P,L,L,L,L,L,P,L,L,L,L,L,L,P},
	{P,L,P,L,P,L,L,L,L,L,P,L,P,L,P,L,L,L,L,P},
	{P,L,P,L,P,L,P,L,L,L,P,L,P,L,L,L,P,L,L,P},
	{P,L,P,L,P,L,L,L,L,L,P,L,P,L,L,L,L,L,L,P},
	{P,L,P,L,P,L,P,L,L,L,P,L,P,L,L,L,L,L,L,P},
	{P,L,P,L,P,L,L,L,L,L,P,L,L,L,L,L,L,L,L,P},
	{P,L,P,L,P,L,L,L,L,L,P,L,P,L,L,L,P,P,L,P},
	{P,L,P,L,P,L,P,L,L,L,P,L,P,L,L,L,L,P,L,P},
	{P,L,P,L,P,L,P,P,P,P,P,L,P,L,L,L,L,P,L,P},
	{P,L,L,L,P,L,L,L,L,L,L,L,P,P,L,L,L,L,D,P},
	{P,P,P,P,P,P,P,P,P,P,P,P,P,P,P,P,P,P,P,P}
};

main (void)
{
	int matriz [tamanho][tamanho];
	int aux [tamanho][tamanho];
	int caminho[tamanho][tamanho];
	int val=0, x, y, origem[2],destino[2];
	int lista=0, a, b, indice=0,cont=0, achou=0;

	for (x=0;x<tamanho;x++)
	{
		for(y=0;y<tamanho;y++)
		{
			matriz[x][y]=cenario[x][y];
			caminho[x][y]=0;
			aux[x][y]=-1;
			//procurando origrm
			if(cenario[x][y]==O)
			{
				origem[0] = x;
				origem[1] = y;
				matriz[x][y]=O;	
				aux[x][y]=O;	
				
			}
			//procyrando Destino
			if(cenario[x][y]==D)
			{
				destino[0] = x;
				destino[1] = y;
				matriz[x][y]=D;
				aux[x][y]=D;	
			}
			//sla
			if(cenario[x][y]!=-50 && cenario[x][y] != 0 && cenario[x][y] != 999)
			{
			lista++;
			}
			printf("%5d",cenario[x][y] );
		}
			cout<<"\n";
	}

	while(achou==0)
	{
		for (x=0;x<tamanho;x++)
		{
			for(y=0;y<tamanho;y++)
			{
				if(aux[x][y]==indice)
				{
					cont++;
				}
			}
		}
		cout<<cont<<"\n";
		Sleep(100);
		int	rc = system( "cls" );
		if (cont>=1)
		{
			for (x=0;x<tamanho;x++)
			{
				for(y=0;y<tamanho;y++)
				{
					if(aux[x][y]==indice)
					{
						a=x;
						b=y;
						aux[x][y]=-99; //-2 na tabela auxiliar significa que foi lido o campo
						
						if (matriz[a+1][b]==-60)	{	matriz[a+1][b]=indice+1;	aux[a+1][b]=indice+1; 		}
						if (matriz[a][b+1]==-60)	{	matriz[a][b+1]=indice+1;	aux[a][b+1]=indice+1;		}
						if (matriz[a-1][b]==-60)	{	matriz[a-1][b]=indice+1;	aux[a-1][b]=indice+1; 		}
						if (matriz[a][b-1]==-60)	{	matriz[a][b-1]=indice+1;	aux[a][b-1]=indice+1;		}
						 
						if(matriz[a+1][b]==999 || matriz[a][b+1]==999 ||matriz[a-1][b]==999 ||matriz[a][b-1]==999 )	{	achou=1;}
						cont--;
						cout<<aux[x][y];
					}
					printf("%5d",aux[x][y] );
				}
				cout<<"\n";
			}

			}
		if (cont==0)
		{
			indice++;
		}
		
//		cout<<achou;
	}
//	cout<<indice;
	Sleep(100);
//	matriz[origem[0]][origem[1]]=indice;
//	aux[origem[0]][origem[1]]=-99;
	caminho[origem[0]][origem[1]]=indice;
	caminho[destino[0]][destino[1]]=-10;

	a=origem[0];
	b=origem[1];
	
	caminho[a][b]=indice;
	
	while(indice>1)
	{	indice--;
			 	if (matriz[a-1][b]==indice)	{	caminho[a-1][b]=indice;		a=a-1;	b=b;	}		//1
			else	if (matriz[a+1][b]==indice)	{	caminho[a+1][b]=indice;		a=a+1;	b=b;	}	//2
			else 	if (matriz[a][b+1]==indice)	{	caminho[a][b+1]=indice;		a=a;	b=b+1;	}	//3
			else	if (matriz[a][b-1]==indice)	{	caminho[a][b-1]=indice;		a=a;	b=b-1;	}	//4
			//muldar 3 e 4 pra 2 e 3 altera a busca de baixo para lateral
		
	}
//	Sleep(100);
	int	rc = system( "cls" );
	for (x=0;x<tamanho;x++)
			{
				for(y=0;y<tamanho;y++)
				{
					printf("%5d",caminho[x][y] );		
				}
				cout<<"\n";
			}
}
