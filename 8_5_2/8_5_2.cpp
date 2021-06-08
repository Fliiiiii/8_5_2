
#include <iostream>
double f1();
double f2(double a, double b, int i);
double f3(double& a, double& b, int& i);
double g1();
double g2(double a, double b, int n);
double g3(double& a, double& b, int& n);
void input(double& amin, double& amax, double& bmin, double& bmax, double& da, double& db, int& n);
void info();
double a_g, b_g;
int i_g;
int main()
{
	setlocale(LC_ALL, "Russian");
	bool save = false;
	int select, i, n;
	double amin, amax, bmin, bmax, da, db, Yi, U, j, k;
	do {
		system("cls");
		info();
		i = 0;
		do {
			if (i) {
				system("cls");
				info();
				printf("Ошибка! ");
			}
			printf("Выберите режим работы программы:\n");
			printf(" [1] Обмен всеми данными с функцией через глобальные переменные\n");
			printf(" [2] Обмен данными с функцией через список параметров по значению\n");
			printf(" [3] Обмен данными с функцией через список параметров по ссылке\n");
			printf("> ");
			scanf_s("%i", &select);
			i++;
		} while (select < 1 || select>3);
		i = 0;
		system("cls");
		printf("Вы выбрали:");
		switch (select) {
		case 1: printf(" [1] Обмен всеми данными с функцией через глобальные переменные\n"); break;
		case 2: printf(" [2] Обмен данными с функцией через список параметров по значению\n"); break;
		case 3: printf(" [3] Обмен данными с функцией через список параметров по ссылке\n"); break;
		}
		if (!save)
			input(amin, amax, bmin, bmax, da, db, n);
		save = false;
		printf(" +---------+---------+-------+------------+-----------+\n");
		printf(" |    a    |    b    |   i   |     Yi     |     U     |\n");
		printf(" +---------+---------+-------+------------+-----------+\n");
		for (k = amin; k <= amax; k += da)
			for (j = bmin; j <= bmax; j += db)
				for (i = 1; i <= n; i++) {
					switch (select) {
					case 1: {
						a_g = k;
						b_g = j;
						i_g = i;
						Yi = f1();
						U = g1();
						break;
					}
					case 2: {
						Yi = f2(k, j, i);
						U = g2(k, j, i);
						break;
					}
					case 3: {
						Yi = f3(k, j, i);
						U = g3(k, j, i);
						break;
					}
					}
					printf(" | %7.2f | %7.2f | %5i | %10.2f | %9.2f |\n", k, j, i, Yi, U);
				}
		printf(" +---------+---------+-------+------------+-----------+\n");
		i = 0;
		do {
			if (i)
				printf("Ошибка! ");
			printf("Программа выполнена. Что дальше?\n");
			printf(" [1] Завершение работы\n");
			printf(" [2] Продолжить работу с новыми значениями\n");
			printf(" [3] Продолжить работу с этими же значениями\n");
			printf("> ");
			scanf_s("%i", &select);
			i++;
		} while (select < 1 || select>3);
		if (select == 3)
			save = true;
	} while (select != 1);
	system("pause");
}
void info() {
	printf("************[ О ПРОГРАММЕ ]***********\n");
	printf("* Информация: Программа строит табл. *\n");
	printf("* рез-тов ф-й от неск.арг            *\n");
	printf("* Авторы: Шалагин Д.Д., Басорин И.А. *\n");
	printf("* Группа: КЭ-218                     *\n");
	printf("* Челябинск, ЮУрГУ, 2021             *\n");
	printf("**************************************\n");
}
void input(double& amin, double& amax, double& bmin, double& bmax, double& da, double& db, int& n) {
	int i;
	printf("Задайте значения переменных:\n");
	printf("amin = ");
	scanf_s("%lf", &amin);
	i = 0;
	do {
		if (i)
			printf("ОШИБКА: (amin)=%g больше (amax)=%g. Введите другие данные.\n", amin, amax);
		printf("amax = ");
		scanf_s("%lf", &amax);
		i++;
	} while (amax < amin);
	printf("bmin = ");
	scanf_s("%lf", &bmin);
	i = 0;
	do {
		if (i)
			printf("ОШИБКА: (bmin)=%g больше (bmax)=%g. Введите другие данные.\n", bmin, bmax);
		printf("bmax = ");
		scanf_s("%lf", &bmax);
		i++;
	} while (bmax < bmin);
	i = 0;
	do {
		if (i)
			printf("С таким шагом (da)=%g мы не доберёмся до (amax)=%g. Введите другие данные.\n", da, amax);
		printf("da = ");
		scanf_s("%lf", &da);
		i++;
	} while (da <= 0);
	i = 0;
	do {
		if (i)
			printf("С таким шагом (db)=%g мы не доберёмся до (bmax)=%g. Введите другие данные.\n", db, bmax);
		printf("db = ");
		scanf_s("%lf", &db);
		i++;
	} while (db <= 0);
	i = 0;
	do {
		if (i)
			printf("Значение (n)=%i должно быть не меньше 1\n", n);
		printf("n = ");
		scanf_s("%i", &n);
		i++;
	} while (n < 1);
}
double f1() {
	double res;
	if (a_g < b_g) {
		if ((a_g * a_g + 4 * b_g * b_g + i_g * i_g) <= 0)
			return 0;
		res = (2 * i_g * i_g * a_g - b_g * i_g + 3 * a_g * b_g) / (sqrt(a_g * a_g + 4 * b_g * b_g + i_g * i_g));
	}
	else {
		if (a_g - b_g + i_g == 0)
			return 0;
		res = (i_g * i_g + 1)/(a_g - b_g + i_g);
	}
	return res;
}
double f2(double a, double b, int i) {
	double res; 
	if (a < b) {
		if ((a * a + 4 * b * b + i * i) <= 0)
			return 0;
		res = (2 * i * i * a - b * i + 3 * a * b) / (sqrt(a * a + 4 * b * b + i * i));
	}
	else {
		if (a - b + i == 0)
			return 0;
		res = (i * i + 1) / (a - b + i);
	}
	return res;
}
double f3(double& a, double& b, int& i) {
	double res;
	if (a < b) {
		if ((a * a + 4 * b * b + i * i) <= 0)
			return 0;
		res = (2 * i * i * a - b * i + 3 * a * b) / (sqrt(a * a + 4 * b * b + i * i));
	}
	else {
		if (a - b + i == 0)
			return 0;
		res = (i * i + 1) / (a - b + i);
	}
	return res;
}
double g1() {
	double res = 0, yi;
	int temp = i_g;
	res = f1();
	for (int i = 1; i <= temp; i++) {
		i_g = i;
		yi = f1();
		if ((abs(yi) > 1) && (yi < res))
			res = yi;
		if ((abs(yi) <= 1) && (2 < res))
			res = 2;
	}
	i_g = temp;
	return res;
}
double g2(double a, double b, int n) {
	double res = 0, yi;
	res = f2(a, b, n);
	for (int i = 1; i <= n; i++) {
		yi = f2(a, b, i);
		if ((abs(yi) > 1) && (yi < res))
			res = yi;
		if ((abs(yi) <= 1) && (2 < res))
			res = 2;
	}
	return res;
}
double g3(double& a, double& b, int& n) {
	double res = 0, yi;
	res = f3(a, b, n);
	for (int i = 1; i <= n; i++) {
		yi = f3(a, b, i);
		if ((abs(yi) > 1) && (yi < res))
			res = yi;
		if ((abs(yi) <= 1) && (2 < res))
			res = 2;
	}
	return res;
}