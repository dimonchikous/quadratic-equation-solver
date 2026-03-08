#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define EPSILON 1e-9

double inputd(char name);
void quadeq(double a, double b, double c);

int main(void){
	printf("Form of equation: ax^2+bx+c=0\n");

	double a, b, c;

	a = inputd('a');
	b = inputd('b');
	c = inputd('c');

	if (fabs(a) < EPSILON){
		printf("ERROR: a - cant be 0!\n");
		return 1;
	}
	printf("\n");

	quadeq(a,b,c);
	
	return 0;
}

double inputd(char name){
	double value;
	
	printf("Input %c: ", name);

	while (scanf("%lf", &value) !=1){
		printf("ERROR: Not a number!\n");

		while (getchar() != '\n');

		printf("Input %c: ", name);
	}
	return value;
}


void quadeq(double a, double b, double c){
	double discr = b*b-4*a*c;
	printf("Discriminant is %f\n", discr);
	if (fabs(discr)<EPSILON){
		printf("1 answer\n");
		double x=(-b)/(2*a);
		if (fabs(x)<EPSILON)
			x=0.0;
		printf("x = %f\n", x);
	}

	else if (discr > 0){
		printf("2 answers\n");
		double sqrtd=sqrt(discr);
		double x1=(-b+sqrtd)/(2*a);
		double x2=(-b-sqrtd)/(2*a);
		printf("x1 = %f\nx2 = %f\n",x1,x2);
	}
	else
		printf("No answers\n");
}
