#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#define pi acos(-1);
int main(void)
{
	system("chcp 1251>nul");

	double r, L, U, f, Xl, I, E;
	int a, b, c;
	double rezistor[16];
	double minRezistor;
	int countRezistor = 0;
	int lenghtR = 0;
#pragma region Ввод исходных данных
	printf("РГР, задание_2, вариант 14\n");
	printf("------------------------------------------------------------\n");
	
	printf("Введите количество значений активного сопротивления \n");

	if (scanf("%d", &lenghtR) != 1 || lenghtR < 1 || lenghtR>15)
	{
		printf("Некоректный ввод...");
		return 0;
	}
	// значений активного сопротивления добовляем в массив
	for (int i = 1; i <= lenghtR; i++)
	{
		printf("Введите R%d=", i);
		if (scanf("%lf", &rezistor[i]) != 1 || rezistor[i] < 0)
		{
			printf("Некоректный ввод...");
			return 0;
		}
	}
	// находим минимальное сопротивление
	minRezistor = rezistor[1];
	for (int i = 2; i <= lenghtR; i++)
	{
		if (minRezistor > rezistor[i]) { minRezistor = rezistor[i]; }
	}
	// находим колличество минимальных сопротивлений
	for (int i = 1; i <= lenghtR; i++)
	{
		if (minRezistor == rezistor[i]) { countRezistor++; }
	}

	printf("Колличество минимальных значений сопротивления = %d\n", countRezistor);
	printf("Введите целую часть 'a' и дробную часть 'b' для значения индуктивности L\n от 0 до 100\n");
	printf("  a = ");
	if (scanf("%d", &a) != 1 || a < 0 || a > 100)  //scanf возвращает 1 или 0, 1 если полученны корректные данные, 0 если полученны не корректные данные
	{
		printf("\t\tНекорректные данные!\n");
		return 1;
	}
	printf("  b = ");
	if (scanf("%d", &b) != 1 || b < 0 || b > 100)
	{
		printf("\t\tНекорректные данные!\n");
		return 1;
	}
	if (a == 0 && b == 0) {
		printf("\t\tНекорректные данные!\n");
		return 1;
	}
	printf("------------------------------------------------------------\n");
	//индуктивность l
	printf("Введите индуктивность L = ");
	if (scanf("%lf", &L) != 1 || L < 0 )
	{
		printf("\t\tНекорректные данные!\n");
		return 1;
	}
	//напряжение u
	printf("Введите напряжение U = ");
	if (scanf("%lf", &U) != 1 || U < 0)
	{
		printf("\t\tНекорректные данные!\n");
		return 1;
	}
	//частота f
	printf("Введите частоту f = ");
	if (scanf("%lf", &f) != 1 || f < 0)
	{
		printf("\t\tНекорректные данные!\n");
		return 1;
	}
#pragma endregion
	printf("------------------------------------------------------------\n");
	printf(" L = %0*.*lf\n U = %5.*lf\n f = %.1lf\n", a + b + 1, b, L, 7 - 5 - 1, U, f);
	for (int i = 1; i <= lenghtR; i++)
	{
		printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		

		r = rezistor[i];
		printf("\t\tРасчет N%d для активного сопротивления r = % .1lf\n\n", i, r);
		
		printf("Реактивное значение катушки 'Xl' вычисляется по формуле:\n  Xl=2пfL\n");
		Xl = f * L * 2 * pi;
		printf("  Xl = %lf\n", Xl);
		
		printf("Сила тока 'I' в цепи вычисляется по формуле:\n  I = U/(r^2+Xl^2)^1/2\n");
		I = U / sqrt(r * r + Xl * Xl);
		printf("  I = %7.3lf\n", I);
		
		printf("ЭДС самоиндукции 'E' вычисляется по формуле:\n  |E|=|Ul|=|I*Xl|\n");
		E = fabs(I * Xl);
		printf("  |E| = %.3lf\n", E);
		
	}
	printf("------------------------------------------------------------\n");
	system("pause");

	return 0;
}



