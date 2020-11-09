#include "oper-quater.h"

int main(void){
	quaternio q;
	int n;
	char nom[30];
	double tol, d[3], compd;
	FILE *sor, *ent;
	printf("Doni la tolerancia.\n");
	scanf("%le", &tol);
	printf("Doni el nom d'entrada.\n");
	scanf (" %s", nom);
	ent=fopen(nom, "r");
	printf("Doni el nom del fitxer de sortida.\n");
	scanf(" %s", nom);
	sor=fopen(nom, "w");
	if(sor==NULL || ent==NULL){
		printf("Error en el fitxer.\n");
		exit(1);
	}
	fscanf(ent, "%d", &n);
	while (fscanf(ent, "%le %le %le %le", &q.real, &q.imag[0], &q.imag[1], &q.imag[2])!=EOF){
		fscanf(ent, "%le %le %le", &d[0], &d[1], &d[2]);
		compd=d[0]*d[0]+d[1]*d[1]+d[2]*d[2];
		compd=sqrt(compd);
		if(rotacioQuat(n,q,d,tol,sor)==0 || compd!=1){
			printf("Hi ha hagut problemes amb algun quaternio o amb el vector direccio d.\n");
			exit(2);
		}
		fprintf(sor, "\n\n");
	}
	fclose(sor);
	fclose(ent);
	printf("Tot correcte.\n");
	return 0;
}
