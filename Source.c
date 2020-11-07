#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

/*L7-25 : Initialisation de fonctions permettant de changer la couleur du texte dans le CMD*/
void red()
{
	printf("\033[1;31m");
}

void green()
{
	printf("\033[0;32m");
}

void blue()
{
	printf("\033[0;34m");
}

void reset()
{
	printf("\033[0m");
}
//////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
	/*L30-41 : Initialisation des variables (int = entier; double = flottant; char = caractère(s)*/
	int val_A = 0;
	int val_B = 0;
	int val_C = 0;
	int delta = 0;
	double solx0 = 0;
	double solx1 = 0;
	double solx2 = 0;
	double alpha = 0;
	double beta = 0;
	char sup = '>';
	char inf = '<';
	char eq = '=';
	//////////////////////////////////////////////////////////////////////////

	/*L44-54 : Demande à l'utilisateur de rentrer les valeurs de A, B et C*/
	printf("=================\n");
	printf("CALCUL POLYNOMIAL\n");
	printf("=================\n");
	puts("");
	printf("La forme d'un polynome correspondant a : ax^2 + bx + c, rentrez la valeur de  A, B et C.\n\n");
	printf("Valeur de A : ");
	scanf_s("%d", &val_A);
	printf("Valeur de B : ");
	scanf_s("%d", &val_B); //L'instruction scanf_s permet de récupérer les informations entrées par l'utilisateur
	printf("Valeur de C : ");
	scanf_s("%d", &val_C);
	getchar(); /*Force le programme à rester ouvert une fois que l'execution atteint la partie conditionnelle. Sans,
			   le programme se fermerait brusquement après que l'utilisateur ait entré les 3 valeurs*/
	//////////////////////////////////////////////////////////////////////////
	if (val_A <= 0)
	{
		system("cls");
		printf("=================\n");
		printf("CALCUL POLYNOMIAL\n");
		printf("=================\n");
		puts("");
		printf("\Format du polynome : %dx^2 + %dx + %d\n\n", val_A, val_B, val_C);
		red();
		printf("Valeur de A : %d", val_A);
		printf("\nErreur 0x01 : Calcul impossible (la valeur A doit etre strictement superieur a 0 !!!)\n\a");
		reset();
		return(1);
	}
	system("cls");
	printf("=================\n");
	printf("CALCUL POLYNOMIAL\n");
	printf("=================\n\n");
	printf("Format du polynome : %dx^2 + %dx + %d\n", val_A, val_B, val_C);
	delta = pow(val_B, 2)-4*val_A*val_C; //Calcul du discriminant Delta (b²-4ac)
	printf("Le discriminant vaut %d\n", delta);

	if (delta > 0)
	{
		printf("Delta %c 0\n", sup);
		solx1 = (-val_B + sqrt(delta)) / (2 * val_A); //Calcul de la solution x1 ([-b+racine de delta]/2a)
		solx2 = (-val_B - sqrt(delta)) / (2 * val_A);//Calcul de la solution x2 ([-b-racine de delta]/2a)
		alpha = -val_B / 2 * val_A; //Calcul de Alpha, première valeur de la forme Conique
		beta = -delta / 4 * val_A; //Calcul de Beta, dernière valeur de la forme Conique
		green();
		printf("\nLe polynome admet deux solutions : x1 = %.2f et x2 = %.2f\n\n\n", solx1, solx2);
		reset();
		blue();
		printf("Forme canonique : %d(x - %.2f)^2 + %.2f\n", val_A, alpha, beta);
		printf("Forme factorisee : %d(x - %.2f)(x - %.2f)\n\n\n", val_A, solx1, solx2);
		reset();
	}
	else if (delta < 0)
	{
		printf("Delta %c 0\n", inf);
		red();
		printf("\nLe polynome n'a pas de solutions dans R\a\n");
		printf("Inutile donc d'afficher la forme Fact' et Can'\n");
		reset();
	}
	else if (delta == 0)
	{
		printf("Delta %c 0\n", eq);
		solx0 = (2 * val_A);
		solx0 = -val_B / solx0;
		alpha = solx0; //Calcul de Alpha, première valeur de la forme Conique (à savoir que Alpha est égal à la Solution 0 lorsque Delta est égal à 0
		beta = -delta / 4 * val_A; //Calcul de Beta, dernière valeur de la forme Conique
		green();
		printf("\nLe polynome admet une solution : x0 = %.2f\n\n", solx0);
		reset();
		blue();
		printf("Forme canonique : %d(x - %.2f)^2 + %.2f\n", val_A, alpha, beta);
		printf("Forme factorisee : %d(x - %.2f)^2\n\n\n", val_A, solx0);
		reset();
	}
	system("pause"); //Informe l'utilisateur qu'il faut appuyer sur n'importe quelle touche pour quitter le progrmme.
	return(0);
}