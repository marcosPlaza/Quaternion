#include "oper-quater.h"

quaternio sumaQuat (quaternio p, quaternio q){
	int i;
	quaternio suma;
	suma.real=p.real+q.real;
	for(i=0; i<3; i++)
		suma.imag[i]=p.imag[i]+q.imag[i];
	return suma;
}

/*Deduim: ij=k	ki=j  kj=i ji=-k ik=-j jk=-i*/
quaternio prodQuat(quaternio p, quaternio q){
	int i;
	quaternio prod;
	prod.real=p.real*q.real;
	for(i=0; i<3; i++)
		prod.real+=-(p.imag[i]*q.imag[i]);
	prod.imag[0]=p.real*q.imag[0]+p.imag[0]*q.real+p.imag[1]*q.imag[2]-p.imag[2]*q.imag[1];
	prod.imag[1]=p.real*q.imag[1]+p.imag[1]*q.real+p.imag[2]*q.imag[0]-p.imag[0]*q.imag[2];
	prod.imag[2]=p.real*q.imag[2]+p.imag[2]*q.real+p.imag[0]*q.imag[1]-p.imag[1]*q.imag[0];
	return prod;
}

quaternio prodEscQuat(quaternio p, int d){
	quaternio prodE;
	prodE.real=p.real*d;
	prodE.imag[0]=p.imag[0]*d;
	prodE.imag[1]=p.imag[1]*d;
	prodE.imag[2]=p.imag[2]*d;
	return prodE;
}

quaternio conjQuat(quaternio p){
	int i;
	quaternio conj;
	conj.real=p.real;
	for(i=0; i<3; i++)
		conj.imag[i]=-p.imag[i];
	return conj;
}

double normQuat(quaternio p){
	int i;
	quaternio prod;
	double norma;
	prod=prodQuat(p,conjQuat(p));
	norma=prod.real;
	for(i=0; i<3; i++)
		norma+=prod.imag[i];
	norma=sqrt(norma);
	return norma;
}

quaternio inversQuat(quaternio p){
	quaternio invers;
	int i;
	double norma;
	invers=conjQuat(p);
	norma=normQuat(p)*normQuat(p);
	invers.real=invers.real/norma;
	for(i=0; i<3; i++)
		invers.imag[i]=invers.imag[i]/norma;
	return invers;
}

void escriuQuat(quaternio p, FILE *fitxer){
	double norma;
	norma=normQuat(p);
	fprintf(fitxer, "QUATERNIO\n PART REAL: %15.8le\t PART IMAGINARIA: %15.8lei %15.8lej %15.8lek\t NORMA: %15.8le\n", p.real, p.imag[0], p.imag[1], p.imag[2], norma);
	return;
}

int rotacioQuat(int n, quaternio q, double d[3], double tol, FILE *fitxer){
	int i;
	double pi=4*atan(1.);
	quaternio p, rotacio;
	for(i=0; i<=n; i++){
		p.real = cos(pi/n);
		p.imag[0] = sin(pi/n)*d[0];
		p.imag[1] = sin(pi/n)*d[1];
		p.imag[2] = sin(pi/n)*d[2];
		rotacio=prodQuat(p,q);
		rotacio=prodQuat(rotacio, conjQuat(p));
		if(fabs(rotacio.real)<tol){
			escriuQuat(rotacio,fitxer);
			q=rotacio;
		}
		else{
			return 0;
		}
	}
	return 1;
}
	




