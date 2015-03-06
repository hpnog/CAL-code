/*
 * Factorial.h
 */

#ifndef FACTORIAL_H_
#define FACTORIAL_H_

#include "Defs.h"

/*Calcula o factorial de um valor de entrada n usando recursividade*/
int factorialRecurs(int n) {
	int num = n;
	int i = n - 1;
	while (i > 1) {
		num = num * i;
		i--;
	}
	return num;
};

/*Calcula o factorial de um valor de entrada n usando programação dinâmica*/
int factorialDinam(int n);

/*Calcula o factorial de todos os valores até n (n >=0), colocando os resultados numa array*/
int* factorialDinamArray(int n);

#endif /* FACTORIAL_H_ */
