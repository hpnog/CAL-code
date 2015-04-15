/*
 * Estacao.h
 *
 *  Created on: 21/04/2015
 *      Author: Pedro
 */

#ifndef ESTACAO_H_
#define ESTACAO_H_
#include "Coordenadas.h"

class Estacao {
	int id;
	Coordenadas coord;
	string nome;
public:
	Estacao(){};
	Estacao(int i,string nome, Coordenadas coord){
		this->id = i;
		this->coord = coord;
		this->nome = nome;
	}
	int getId();
	const int getIdConst();
};

bool operator==(Estacao&a, const Estacao &rhs) {
	Estacao estacao = rhs;
	if(a.getId() == estacao.getId()) return true;
	else return false;
}

int Estacao::getId(){
	return id;
}

const int Estacao::getIdConst(){
	return id;
}

#endif /* ESTACAO_H_ */
