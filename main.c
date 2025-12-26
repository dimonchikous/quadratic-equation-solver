#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXCHAR 202

void inputd(char t, char s[]);
void quadeq(double a, double b, double c);

int main(void){
	printf("Form of equation: ax^2+-bx+-c=0\n");

	char sa[MAXCHAR];
	char sb[MAXCHAR];
	char sc[MAXCHAR];

	char *trash;

	inputd('a', sa);
	inputd('b', sb);
	inputd('c', sc);

	double a = strtod(sa, &trash);
	double b = strtod(sb, &trash);
	double c = strtod(sc, &trash);

	if (a == 0){
		printf("ERROR: a - cant be 0!\n");
		return 0;
	}

	quadeq(a,b,c);
	
	return 0;
}

void inputd(char t, char s[]){
	int i, c;
	printf("Input %c: ", t);
	for (i = 0; (c=getchar()) != '\n' && i < MAXCHAR - 1; i++)
		s[i]=(char)c;
	s[i] = '\0';
	printf("\n");
}

void quadeq(double a, double b, double c){
	double discr = pow(b,2)-4*a*c;
	printf("Discriminant is %f\n", discr);
	if (discr > 0){
		printf("2 answers\n");
		double x1=((b*(-1))+sqrt(discr))/(2*a);
		double x2=((b*(-1))-sqrt(discr))/(2*a);
		printf("x1 = %f\nx2 = %f\n",x1,x2);
	}
	else if (discr==0){
		printf("1 answer\n");
		double x=((b*(-1))+sqrt(discr))/(2*a);
		printf("x = %f\n", x);
	}
	else
		printf("No answers\n");
}
