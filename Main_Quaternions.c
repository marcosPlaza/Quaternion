/*Xènia Domènech 49783658C*/
#include "oper-quater.h"
/*Al compilar em dona violacio de segment i he vist que ni em llegeix bé les matrius aixi que suposo que s'ha de guradar memoria per elles pero no se com fer-ho*/
typedef struct{
	quaternio **mat;
	int nFil, nCol;
}infoMatriu;

void prodMat (infoMatriu A, infoMatriu B, infoMatriu C){
	quaternio aux;
	int i,j,k;
	C.nFil=A.nFil;
	C.nCol=B.nCol;
	for(k=0; k<B.nCol; k++){
		for(i=0; i<A.nFil; i++){
			aux.real=0;aux.imag[0]=0; aux.imag[1]=0; aux.imag[2]=0;
			for(j=0; j<A.nCol; j++)
				aux=sumaQuat(prodQuat(A.mat[i][j], B.mat[j][i]), aux);
			C.mat[i][k]=aux;
		}
	}	
	return;
}

int comparar(quaternio p, quaternio q){
	double np, nq;
	int i;	
	np=normQuat(p);
	nq=normQuat(q);
	if (np < nq)
		return -1;
	if (nq < np)
		return 1;
	if(nq == np){
		if(p.real!=q.real)
			return -1;
		for(i=0; i<3; i++)
			if(p.imag[i]!=q.imag[i])
				return -1;
	}
	return 0;
}

int main(void){
	char nom[30];
	int i,j, posicio=0;
	double norma=0.;
	quaternio aux,p;
	infoMatriu C,D,B;
	FILE *ent, *sor;
	printf("Doni el nom del fitxer d'entrada.\n");
	scanf (" %s", nom);
	ent=fopen(nom, "r");
	printf("Doni el nom del fitxer de sortida.\n");
	scanf (" %s", nom);
	sor=fopen(nom, "w");
	if(ent==NULL || sor==NULL){
		printf("Error amb algun fitxer.\n");
		exit(1);
	}
	fscanf(ent, "%d %d", &C.nFil, &C.nCol);
	C.mat=(quaternio**)malloc(C.nFil*sizeof(quaternio*));
	if(C.mat==NULL)
		exit(1);
	for(i=0; i<C.nFil; i++){
		C.mat[i]=(quaternio*)malloc(C.nCol*sizeof(quaternio));
		if(C.mat[i]==NULL)
			exit(1);
	}
	for(i=0; i<C.nFil; i++)
		for(j=0; j<C.nCol; j++)
			fscanf(ent, "%le %le %le %le", &C.mat[i][j].real, &C.mat[i][j].imag[0], &C.mat[i][j].imag[1], &C.mat[i][j].imag[2]);
	fscanf(ent, "%d %d", &D.nFil, &D.nCol);
	D.mat=(quaternio**)malloc(D.nFil*sizeof(quaternio*));
	if(D.mat==NULL)
		exit(1);
	for(i=0; i<D.nFil; i++){
		D.mat[i]=(quaternio*)malloc(D.nCol*sizeof(quaternio));
		if(D.mat[i]==NULL)
			exit(1);
	}
	for(i=0; i<D.nFil; i++)
		for(j=0; j<D.nCol; j++)
			fscanf(ent, "%le %le %le %le", &D.mat[i][j].real, &D.mat[i][j].imag[0], &D.mat[i][j].imag[1], &D.mat[i][j].imag[2]);
	B.nFil=C.nFil;
	B.nCol=D.nCol;
	B.mat=(quaternio**)malloc(B.nFil*sizeof(quaternio*));
	if(B.mat==NULL)
		exit(1);
	for(i=0; i<B.nFil; i++){
		B.mat[i]=(quaternio*)malloc(B.nCol*sizeof(quaternio));
		if(B.mat[i]==NULL)
			exit(1);
	}
	prodMat(C,D,B);
	fprintf(sor,"El producte de C*D es:\n");
	for(i=0; i<C.nFil; i++){
		for(j=0; j<D.nCol; j++)
			fprintf(sor, "(%23.15le %23.15lei %23.15lej %23.15lek)\t", B.mat[i][j].real, B.mat[i][j].imag[0], B.mat[i][j].imag[1], B.mat[i][j].imag[2]);
		printf("\n");
	}
	/*Podem trobar l'element més gran de la diagonal, si la matriu es quadrada*/
	aux=B.mat[0][0];
	if(B.nFil==B.nCol)
		for(i=1; i<B.nFil; i++){
			p=B.mat[i][i];
			if(comparar(aux,p)==-1){
				aux=p;
				norma=normQuat(aux);
				posicio=i;
			}
		}
	fprintf(sor, "L'element mes gran de la diagonal de B es %le + %lei +%lej + %lek\nI esta a la posicio (%d, %d) i te norma %le\n", B.mat[i][j].real, B.mat[i][j].imag[0], B.mat[i][j].imag[1], B.mat[i][j].imag[2], posicio, posicio, norma); 
	for(i=0; i<C.nFil; i++){
		free(B.mat[i]);
		free(C.mat[i]);
	}
	for(i=0; i<D.nFil; i++)
		free(D.mat[i]);
	free(D.mat);
	free(C.mat);
	free(B.mat);
	fclose(ent);
	fclose(sor);
	return 0;
}
	
