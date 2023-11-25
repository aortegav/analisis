#include <jni.h>
#include <math.h>
#include <stdio.h>

/*
 * Class:     appsecante_JavaCalc
 * Method:    calLin
 * Signature: (DDDDD)D
 */

   const int ITERACIONES_MAXIMAS = 100;

   double fL(double x, double a, double b)
   {
    return a * x + b;
   }

JNIEXPORT jdouble JNICALL Java_appsecante_JavaCalc_calLin
  (JNIEnv * env, jobject obj, jdouble a, jdouble b, jdouble tolerancia, jdouble x0, jdouble x1)
{
   jdouble xi; 
   double err;
   int n = 1;

    if (fL(x0, a, b) > 0 && (fL(x1, a, b) > 0) || (fL(x0, a, b) < 0) && (fL(x1, a, b) < 0))
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
        } while (err > tolerancia && n <= ITERACIONES_MAXIMAS);
    }
    return xi;
}

/*
 * Class:     appsecante_JavaCalc
 * Method:    calQua
 * Signature: (DDDDDD)D
 */

   double fQ(double x, double a, double b, double c)
   {
    return a * x * x + b * x + c;
   }
JNIEXPORT jdouble JNICALL Java_appsecante_JavaCalc_calQua
  (JNIEnv *, jobject, jdouble a, jdouble b, jdouble c, jdouble tolerancia, jdouble x0, jdouble x1)
{
    double xi, err;
    int n = 1;

    if ((fQ(x0, a, b, c) > 0) && (fQ(x1, a, b, c) > 0) || (fQ(x0, a, b, c) < 0) && (fQ(x1, a, b, c) < 0))
    {
        printf("No se encontro la raiz: cambiar intervalos iniciales");
    } else
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
        } while (err > tolerancia && n <= ITERACIONES_MAXIMAS);
      }
    return xi;
}

