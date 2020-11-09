#include "oper-quater.h"

int main(void){
	quaternio p,q,pq,qp,l;
	double tol=10e-10;	
	int i, igual=0;
	printf("Doni els dos quaternions.\n");
	scanf("%le", &p.real);
	for(i=0; i<3; i++)
		scanf("%le", &p.imag[i]);
	scanf("%le", &q.real);
	for(i=0; i<3; i++)
		scanf("%le", &q.imag[i]);
	/*COMPROVEM QUE pq!=qp*/
	pq=prodQuat(p,q);
	qp=prodQuat(q,p);
	if(fabs(pq.real-qp.real)>tol)
		igual++;
	for(i=0; i<3; i++)
		if(fabs(pq.imag[i]-qp.imag[i])>tol)
			igual++;
	printf("pq = %15.8le %15.8lei %15.8lej %15.8lek\n", pq.real, pq.imag[0], pq.imag[1], pq.imag[2]);
	printf("qp = %15.8le %15.8lei %15.8lej %15.8lek\n", qp.real, qp.imag[0], qp.imag[1], qp.imag[2]);
	if(igual!=0)
		printf("pq!=qp i per tant el producte d'un quaternio no es commutatiu.\n");
	/*COMPORVEM QUE ijk=-1*/	
	p.real=0; p.imag[0]=1; p.imag[1]=0; p.imag[2]=0;	
	q.real=0; q.imag[0]=0; q.imag[1]=1; q.imag[2]=0;
	l.real=0; l.imag[0]=0; l.imag[1]=0; l.imag[2]=1;
	pq=prodQuat(p,q);
	pq=prodQuat(pq,l);
	printf("Per comprovar si ijk=-1 fem: p=(0,1,0,0), q=(0,0,1,0) i l=(0,1,0,0) tal que pql=(%15.8le,%15.8le,%15.8le,%15.8le)\n", pq.real, pq.imag[0], pq.imag[1], pq.imag[2]);
	printf("Per tant ijk=-1\n");
	/*COMPROVEM i^2=-1*/
	p.real=0; p.imag[0]=1; p.imag[1]=0; p.imag[2]=0;	
	q.real=0; q.imag[0]=1; q.imag[1]=0; q.imag[2]=0;
	pq=prodQuat(p,q);
	printf("Per comprovar si i^2=-1 fem: p=(0,1,0,0) i q=(0,1,0,0) tal que pq=(%15.8le,%15.8le,%15.8le,%15.8le)\n", pq.real, pq.imag[0], pq.imag[1], pq.imag[2]);
	printf("Per tant i^2=-1\n");
	/*COMPROVEM j^2=-1*/
	p.real=0; p.imag[0]=0; p.imag[1]=1; p.imag[2]=0;	
	q.real=0; q.imag[0]=0; q.imag[1]=1; q.imag[2]=0;
	pq=prodQuat(p,q);
	printf("Per comprovar si j^2=-1 fem: p=(0,0,1,0) i q=(0,0,1,0) tal que pq=(%15.8le,%15.8le,%15.8le,%15.8le)\n", pq.real, pq.imag[0], pq.imag[1], pq.imag[2]);
	printf("Per tant j^2=-1\n");
	/*COMPROVEM k^2=-1*/
	p.real=0; p.imag[0]=0; p.imag[1]=0; p.imag[2]=1;	
	q.real=0; q.imag[0]=0; q.imag[1]=0; q.imag[2]=1;
	pq=prodQuat(p,q);
	printf("Per comprovar si k^2=-1 fem: p=(0,0,0,1) i q=(0,0,0,1) tal que pq=(%15.8le,%15.8le,%15.8le,%15.8le)\n", pq.real, pq.imag[0], pq.imag[1], pq.imag[2]);
	printf("Per tant k^2=-1\n");
	return 0;
}
	

