/*
 * Change.h
 */

#ifndef CHANGE_H_
#define CHANGE_H_

#include "Defs.h"

/* Calcula o troco para n c�ntimos, utilizando o n�mero m�nimo de moedas, tendo apenas dispon�veis
 * moedas de 1, 2 e 5 c�ntimos.
 *
 * Devolve:
 * Uma string que cont�m com a indica��o, para cada n, a combina��o de moedas a utilizar.
 * Por exemplo: troco de 1 c�ntimo: 1 moeda de 1
 * 				troco de 2 c�ntimos: 1 moeda de 2
 * 				troco de 3 c�ntimos: 1 moeda de 1, 1 moeda de 2
 * 				(...)
 * A string devolvida representar os valores das moedas (separadas por virgula) para cada n (separado por ponto e v�rgula)
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
