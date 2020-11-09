/*Xènia Domènech 49783658C*/
#include "oper-quater.h"

int main(void){
	int i;
	quaternio p, conj, invers, comprov;
	double norma;
	printf("Doni el quaternio.\n");
	scanf("%le", &p.real);
	for(i=0; i<3; i++)
		scanf("%le", &p.imag[i]);
	conj=conjQuat(p);
	norma=normQuat(p);
	invers=inversQuat(p);
	printf("El quaternio p=\n%15.8le ", p.real);
	for(i=0; i<3; i++)
		printf("%15.8le ", p.imag[i]);
	printf("\n");
	printf("Amb norma %15.8le\n", norma);	
	printf("Te conjugat p* =\n%15.8le ", conj.real);
	for(i=0; i<3; i++)
		printf("%15.8le ", conj.imag[i]);
	printf("\n");
	printf("Comprovacio norma: p p*\n");
	comprov=prodQuat(p,conj);
	printf("%15.8le ", comprov.real);
	for(i=0; i<3; i++)
		printf("%15.8le ", comprov.imag[i]);
	printf("\n");
	printf("L'arrel de la part real es: %15.8le\n", sqrt(comprov.real));
	printf("Te inversa p^-1  =\n%15.8le ", invers.real);
	for(i=0; i<3; i++)
		printf("%15.8le ", invers.imag[i]);
	printf("\n");
	printf("Comprovacio inversa: p p^-1\n");
	comprov=prodQuat(p,invers);
	printf("%15.8le ", comprov.real);
	for(i=0; i<3; i++)
		printf("%15.8le ", comprov.imag[i]);
	printf("\n");
	return 0;
}
