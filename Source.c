#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

void red()
{
	printf("\033[1;31m");
}

void green()
{
	printf("\033[0;32m");
}

void reset()
{
	printf("\033[0m");
}

int main(int argc, char* argv[])
{
	int val_A = 0;
	int val_B = 0;
	int val_C = 0;
	int delta = 0;
	int solx0 = 0;
	int solx1 = 0;
	int solx2 = 0;
	char sup = '>';
	char inf = '<';
	char eq = '=';

	printf("=================\n");
	printf("CALCUL POLYNOMIAL\n");
	printf("=================\n");
	puts("");
	printf("La forme d'un polynome correspondant a : ax^2 + bx + c, rentrez la valeur de  A, B et C.\n\n");
	printf("Valeur de A : ");
	scanf_s("%d", &val_A);
	printf("Valeur de B : ");
	scanf_s("%d", &val_B);
	printf("Valeur de C : ");
	scanf_s("%d", &val_C);
	system("cls");
	printf("=================\n");
	printf("CALCUL POLYNOMIAL\n");
	printf("=================\n\n");
	printf("Format du polynome : %dx^2 + %dx + %d\n", val_A, val_B, val_C);
	delta = pow(val_B, 2)-4*val_A*val_C;
	printf("Le discriminant vaut %d\n", delta);
	if (delta > 0)
	{
		printf("Delta %c 0\n", sup);
		solx1 = (-val_B - sqrt(delta)) / 2 * val_A;
		solx2 = (-val_B + sqrt(delta)) / 2 * val_A;
		green();
		printf("Le polynome admet deux solutions : x1 = %d et x2 = %d\n\n\n", solx1, solx2);
		reset();
	}
	else if (delta < 0)
	{
		printf("Delta %c 0\n", inf);
		red();
		printf("Le polynome n'a pas de solutions dans R\a\n\n\n");
		reset();
	}
	else if (delta == 0)
	{
		printf("Delta %c 0\n", eq);
		solx0 = -val_B / 2 * val_A;
		green();
		printf("Le polynome admet une solution : x0 = %d\n\n\n", solx0);
		reset();
	}
	return(0);
}