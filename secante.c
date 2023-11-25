#include <stdio.h>
#include <math.h>

const int ITERACIONES_MAXIMAS = 100;
const double TOLERANCIA;

// Función que calcula el valor de la ecuación
double fQ(double x, double a, double b, double c)
{
    return a * x * x + b * x + c;
}

double calQua(double a, double b, double c, double TOLERANCIA, double x0, double x1)
{
    double xi, err;
    int n = 1;

    if ((fQ(x0, a, b, c) > 0) && (fQ(x1, a, b, c) > 0) || (fQ(x0, a, b, c) < 0) && (fQ(x1, a, b, c) < 0))
    {
        printf("No se encontro la raiz: cambiar intervalos iniciales");
    }
    else
    {
        xi = x1 - (fQ(x1, a, b, c) * (x0 - x1) / (fQ(x0, a, b, c) - fQ(x1, a, b, c)));
        x0 = x1;
        x1 = xi;
        xi = x1 - (fQ(x1, a, b, c) * (x0 - x1) / (fQ(x0, a, b, c) - fQ(x1, a, b, c)));
        do
        {
            err = fabs(((xi - x1) / xi) * 100);
            if (err != 0)
            {
                x0 = x1;
                x1 = xi;
                xi = x1 - (fQ(x1, a, b, c) * (x0 - x1) / (fQ(x0, a, b, c) - fQ(x1, a, b, c)));
            }
            n++;
        } while (err > TOLERANCIA && n <= ITERACIONES_MAXIMAS);
    }
    return xi;
}

// Función que calcula el valor de la ecuación
double fL(double x, double a, double b)
{
    return a * x + b;
}

double calLin(double a, double b, double TOLERANCIA, double x0, double x1)
{
    double xi, err;
    int n = 1;

    if ((fL(x0, a, b) > 0) && (fL(x1, a, b) > 0) || (fL(x0, a, b) < 0) && (fL(x1, a, b) < 0))
    {
        printf("No se encontro la raiz: cambiar intervalos iniciales");
    }
    else
    {
        xi = x1 - (fL(x1, a, b) * (x0 - x1) / (fL(x0, a, b) - fL(x1, a, b)));
        x0 = x1;
        x1 = xi;
        xi = x1 - (fL(x1, a, b) * (x0 - x1) / (fL(x0, a, b) - fL(x1, a, b)));
        do
        {
            err = fabs(((xi - x1) / xi) * 100);
            if (err != 0)
            {
                x0 = x1;
                x1 = xi;
                xi = x1 - (fL(x1, a, b) * (x0 - x1) / (fL(x0, a, b) - fL(x1, a, b)));
            }
            n++;
        } while (err > TOLERANCIA && n <= ITERACIONES_MAXIMAS);
    }
    return xi;
}
