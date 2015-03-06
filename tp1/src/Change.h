/*
 * Change.h
 */

#ifndef CHANGE_H_
#define CHANGE_H_

#include "Defs.h"

/* Calcula o troco para n cêntimos, utilizando o número mínimo de moedas, tendo apenas disponíveis
 * moedas de 1, 2 e 5 cêntimos.
 *
 * Devolve:
 * Uma string que contém com a indicação, para cada n, a combinação de moedas a utilizar.
 * Por exemplo: troco de 1 cêntimo: 1 moeda de 1
 * 				troco de 2 cêntimos: 1 moeda de 2
 * 				troco de 3 cêntimos: 1 moeda de 1, 1 moeda de 2
 * 				(...)
 * A string devolvida representar os valores das moedas (separadas por virgula) para cada n (separado por ponto e vírgula)
 * Exemplo: 1;2;1,2;2,2;5;1,5;...
 * */
string calcChange(int n){
	stringstream final;
	int numTotal = n;
	int numPit = 1;
	while (numTotal >= numPit) {
		int num = numPit;
		int num1, num2, num5;
		num5 = numPit / 5;
		num2 = (numPit % 5) / 2;
		num1 = ((numPit % 5) % 2);
		while (num1 != 0) {
			num--;
			num1--;
			final << "1";
			if (num == 0)
				final << ";";
			else
				final << ",";
		}
		while (num2 != 0) {
			num2--;
			num = num - 2;
			final << "2";
			if (num == 0)
				final << ";";
			else
				final << ",";
		}
		while (num5 != 0) {
			num = num - 5;
			num5--;
			final << "5";
			if (num == 0)
				final << ";";
			else
				final << ",";
		}
		numPit++;
	}
	return final.str();
};

#endif /* CHANGE_H_ */
