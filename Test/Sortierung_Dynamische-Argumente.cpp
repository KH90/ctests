#include <iostream>                                                   //
#include <stdio.h>                                                    //
#include <stdarg.h>                                                   // Einfügen von Headern
                                                                      //
using namespace std;                                                  // Namensraum erweitern (std::cout -> cout)
                                                                      //
int* my_test(int num, ...)                                            // Start der Definition von der Funktion my_test
{                                                                     // 
	int i;                                                        // Deklaration von i
	                                                              //
	int *sum;                                                     // Deklaration von sum(Pointer) 
	sum = new int[num];                                           // Definition von sum
	                                                              //
	va_list meineliste;                                           // Deklaration von meineliste
	va_start(meineliste, num);                                    // Initialisierung von meineliste
                                                                      //
                                                                      //
	for (i = 0; i < num; i++)                                     // Start der For-Schleife, welche die Werte in sum-Array einträgt
	{                                                             // 
		sum[i] = va_arg(meineliste, int);                     // Einzelne Werte von meineliste sum zuweisen
	}                                                             //
                                                                      //
	va_end(meineliste);                                           // Nötig für my_test Funktion, welche über "meineliste" Argumente
                                                                      // benutzt hat  
	int temp;                                                     // Deklaration von temp
	int j;                                                        // Deklaration von j
	for (i = num-1; i > 0; i--)                                   // Start von For-Schleife für Sortierung
	{                                                             //
		for (j = 0; j < i; j++)                               //
		{                                                     //
			if (sum[j] > sum[j + 1])                      //
			{                                             //
				temp = sum[j + 1];                    //
				sum[j + 1] = sum[j];                  //
				sum[j] = temp;                        //
			}                                             //
		}                                                     //
	}                                                             // Ende von Sortierung
                                                                      //
	return sum;                                                   // sum-Array wird zurückgegeben
}                                                                     //
                                                                      //
int main(int argc, char *argv[])                                      // Start von Hauptprogramm
{                                                                     //
	int n;                                                        // Deklaration von n
	cout << "Hello World!" << endl;                               // Ausgabe mittels C++-Programm "cout" (endl für Endline -> "\n")
                                                                      // 
	int *ergebnis = my_test(5, 8, 7, 1, 4, 5);                    // Initialisierung von Pointer "ergebnis" auf Rückgabewert
	                                                              // von "my_test" Aufruf
                                                                      //
	for (n = 0; n < 5; n++)                                       // Start von Schleife zur Ausgabe von "ergebnis" Werten
	{                                                             //
		printf("sum[%d]: %d\n", n, ergebnis[n]);              // Ausgabe des Wertes von "ergebnis[n]"
	}                                                             //
                                                                      //
	return 0;                                                     // Rückgabewert von Hauptprogramm
}                                                                     //
