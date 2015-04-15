/*
 * Coordenadas.h
 *
 *  Created on: 21/04/2015
 *      Author: Pedro
 */

#ifndef COORDENADAS_H_
#define COORDENADAS_H_

class Coordenadas {
	int y;
	int x;
public:
	Coordenadas(int x, int y){
		this->y = y;
		this->x =  x;
	}

	Coordenadas(){
		y = 0;
		x = 0;
	}

	int gety(){return y;}

	int getx(){return x;}

	void sety(int value){y = value;}

	void setx(int value){x =  value;}

	void setCoordenadas(int x, int y){
		this->y = y;
		this->x = x;
	}
};



#endif /* COORDENADAS_H_ */
