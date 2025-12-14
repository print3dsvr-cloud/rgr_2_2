#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#define pi acos(-1);
int main(void)
{
	system("chcp 1251>nul");
	
	
	int item = 0;
	double discount = 1;
	double price = 0;
	double all_price = 0;
	printf("введите цену  ");


	scanf("%lf", &price);
	printf("введите кол-во  ");
	scanf("%d", &item);
	if (item > 100)
	{
		discount = 0.95;
	}
	if (item > 300)
	{
		discount = 0.9;
	}
	all_price = price * item * discount;
	printf("сумма со скидкой %lf\n", all_price);

	system("pause");

	
	double r, L, U, f, Xl, I, E;
	int a, b, c;
	double rezistor[16];
	double minRezistor;
	int countRezistor = 0;
	int lenghtR = 0;
	int menu = 0;
	int menuI = 0;



#pragma region Ввод исходных данных
	printf("РГР, задание_2, вариант 14\n");
	printf("------------------------------------------------------------\n");
	
	while (1)
	{
		system("cls");
		printf("1 - Ввод данных \n");
		printf("2 - Вывод данных \n");
		printf("3 - Произвести расчеты \n");
		printf("4 - выход \n");
		if (scanf("%d", &menu) != 1 || menu < 1 || menu>4)
		{
			printf("Некоректный ввод...");
			return 0;
		}
		switch (menu)
		{
			case 1:
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
				if (scanf("%lf", &L) != 1 || L < 0)
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
				menuI = 1;
				break;
			case 2:
				if (menuI < 2)
				{
					printf("\t\tРасчет не произведен!\n");
					return 1;
				}
				for (int i = 1; i <= lenghtR; i++)
				{
					r = rezistor[i];
					printf(" r%d = % .1lf\n", i, r);
				}
				printf(" L = %0*.*lf\n U = %5.*lf\n f = %.1lf\n", a + b + 1, b, L, 7 - 5 - 1, U, f);
				printf(" Xl = %lf\n", Xl);
			
				system("pause");
				break;
			case 3:
				if (menuI == 0)
				{
					printf("\t\tОтсутствие входных параметров!\n");
					return 1;
				}
				printf("------------------------------------------------------------\n");
				
				printf("Реактивное значение катушки 'Xl' вычисляется по формуле:\n  Xl=2пfL\n");
				Xl = f * L * 2 * pi;
				printf("  Xl = %lf\n", Xl);
				for (int i = 1; i <= lenghtR; i++)
				{
					printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

					r = rezistor[i];
					printf("\t\tРасчет N%d для активного сопротивления r = % .1lf\n\n", i, r);

					printf("Сила тока 'I' в цепи вычисляется по формуле:\n  I = U/(r^2+Xl^2)^1/2\n");
					I = U / sqrt(r * r + Xl * Xl);
					printf("  I = %7.3lf\n", I);

					printf("ЭДС самоиндукции 'E' вычисляется по формуле:\n  |E|=|Ul|=|I*Xl|\n");
					E = fabs(I * Xl);
					printf("  |E| = %.3lf\n", E);

				}
				printf("------------------------------------------------------------\n");
				menuI = 2;
				system("pause");
				break;
			case 4:
				return;
			default: return;



		}


	}
	
	
	system("pause");

	return 0;
}



