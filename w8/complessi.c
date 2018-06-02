#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979323846

struct complex{
  double reale;
  double imm;
};

struct complexMF {
  double modulo;
  double teta;
};

typedef struct complex Complex;
typedef struct complexMF ComplexMF;

Complex init(double x, double y);
//Complex add(Complex, Complex);
//Complex multiply(Complex, Complex);
ComplexMF conversione(Complex c);
void stampaComplexMF(ComplexMF c);

int main(){
  double a;
  double b;
  Complex numero;

  printf("Inserisci la parte reale: ");
  scanf("%lf", &a);
  printf("Inserisci la parte immaginaria: ");
  scanf("%lf", &b);
  numero = init(a, b);

  printf("Il numero complesso e' %.2f +i%.2f\n", numero.reale, numero.imm);

  ComplexMF numerofase = conversione(numero);

  stampaComplexMF(numerofase);
  puts("\n");
}

Complex init(double x, double y){
  Complex temp;
  temp.reale = x;
  temp.imm = y;
  return temp;
}

ComplexMF conversione(Complex c){
  ComplexMF nuovo;
  double teta = 0.0;

  if (c.reale > 0){
    teta = atan(c.imm / c.reale);
  } else if ((c.reale < 0) && (c.imm < 0)) {
    teta = atan(c.imm / c.reale) - PI;
  } else if ((c.reale < 0) && (c.imm >0)){
    teta = atan(c.imm / c.reale) + PI;
  } else if ((c.reale == 0.0) && (c.imm > 0)){
    teta = PI/2;
  } else if ((c.reale == 0.0) && (c.imm < 0)){
    teta = -PI/2;
  } else if((c.reale < 0) && (c.imm == 0.0)){
    teta = -PI;
  }

  nuovo.modulo = sqrt((c.reale*c.reale)+(c.imm*c.imm));
  nuovo.teta = teta;

  return nuovo;
}

void stampaComplexMF(ComplexMF c){
  printf("z = %lf(cos(%lf) + isen(%lf))",c.modulo, c.teta, c.teta);
}
