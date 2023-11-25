package appsecante;

import java.util.Scanner;

/**
 *
 * Clase ejemplo para probar el funcionamiento de la libreria secante
 *
 */

public class Main {

	static {
	   System.loadLibrary("secante");
 	}

	public static void main(String[] argumentos){

/*
	    Scanner in = new Scanner(System.in);

	    System.out.println("Ingrese el cofeciente a: ");
	    double a = in.nextDouble();
	    System.out.println("Ingrese el cofeciente b: ");
            double b = in.nextDouble();
	    System.out.println("Ingrese la tolerancia: ");
            double tole = in.nextDouble();
	    System.out.println("Ingrese el intervalo x0: ");
            double x0 = in.nextDouble();
	    System.out.println("Ingrese el intervalo x1: ");
            double x1 = in.nextDouble();
*/
	    JavaCalc calculadora = new JavaCalc();

	    double x = calculadora.calLin(3, -2, 0.01, 0, 1);

	    System.out.println(x);
	}

}

