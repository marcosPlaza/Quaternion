#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct{
	double real;
	double imag[3];
}quaternio;

quaternio sumaQuat(quaternio p, quaternio q);
quaternio prodQuat(quaternio p, quaternio q);
quaternio prodEscQuat(quaternio p, int d);
quaternio conjQuat(quaternio p);
double normQuat(quaternio p);
quaternio inversQuat(quaternio p);
void escriuQuat(quaternio p, FILE *fitxer);
int rotacioQuat(int n, quaternio q, double d[3], double tol, FILE *fitxer);
