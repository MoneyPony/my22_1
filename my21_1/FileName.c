#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <math.h>

double function1(double x);
double function2(double x);
double function3(double x);
void printTable(double (*function)(double), double start, double end, double step);

int main() {
    setlocale(LC_ALL, "RUS");
    int selectedFunction;
    printf("Выберите функцию (1, 2 или 3): ");
    scanf("%d", &selectedFunction);
    double start, end, step;
    printf("Введите начальное значение x: ");
    scanf("%lf", &start);
    printf("Введите конечное значение x: ");
    scanf("%lf", &end);
    printf("Введите шаг: ");
    scanf("%lf", &step);
    switch (selectedFunction) {
    case 1:
        printTable(function1, start, end, step);
        break;
    case 2:
        printTable(function2, start, end, step);
        break;
    case 3:
        printTable(function3, start, end, step);
        break;
    default:
        printf("Некорректный выбор функции.\n");
        break;
    }
}

// Функция 1: y(x) = ln(sqrt(x^3)) при x>0
double function1(double x)
{
    if (x > 0)
    {
        return log(fabs(sqrt(pow(x, 3))));
    }
    else
    {
        return 0; // Если x <= 0, функция не определена
    }
}

// Функция 2: V(x) = sqrt(tg(x^2-1)) при x > 1, -2x при 0<=x<=1, e^cos(x) при x<0
double function2(double x)
{
    if (x > 1)
    {
        return sqrt(tan(pow(x, 2) - 1));
    }
    else if (x >= 0 && x <= 1)
    {
        return -2 * x;
    }
    else
    {
        return exp(cos(x));
    }
}

// Функция 3: S(x) = (x-1)/(x+1) + 1/3 * ((x-1)/(x+1)^3) + 1/5 * ((x-1)/(x+5)^5) + 1/7 * ((x-1)/(x+1)^7)
double function3(double x)
{
    return (x - 1) / (x + 1) + 1 / 3 * pow((x - 1) / (x + 1), 3) + 1 / 5 * pow((x - 1) / (x + 5), 5) + 1 / 7 * pow((x - 1) / (x + 1), 7);
}

void printTable(double (*function)(double), double start, double end, double step)
{
    printf("x\t|\ty(x)\n");
    printf("-----------------------\n");
    for (double x = start; x <= end; x += step)
    {
        printf("%.2f\t|\t%.6f\n", x, function(x));
    }
}