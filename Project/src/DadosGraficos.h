/*
 * DadosGraficos.h
 *
 *  Created on: 24/04/2015
 *      Author: Pedro
 */

#ifndef DADOSGRAFICOS_H_
#define DADOSGRAFICOS_H_

class DadosGraficos {
public:
	int id_aresta;
	int id_origem;
	int id_destino;
	DadosGraficos(int a, int b, int c){
		id_aresta = a;
		id_origem = b;
		id_destino = c;
	}
};

#endif /* DADOSGRAFICOS_H_ */
