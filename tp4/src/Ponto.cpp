/*
 * Ponto.cpp
 *
 *  Created on: 4 de Mar de 2011
 *      Author: ap
 */

#include "Ponto.h"
#include <cmath>

Ponto::Ponto() {
	x = 0;
	y = 0;
}

Ponto::~Ponto() {
	// TODO Auto-generated destructor stub
}

Ponto::Ponto(double x, double y) {
	this->x = x;
	this->y = y;
}

Ponto::Ponto(int x, int y) {
	this->x = x;
	this->y = y;
}

double Ponto::distancia(Ponto &p) {
	return (sqrt(pow(x-p.x, 2) + pow(y-p.y, 2)));
}

bool Ponto::operator==(const Ponto &p) const {
	return (x == p.x && y == p.y);
}

ostream& operator<<(ostream& os, Ponto &p) {
	os << "(" << p.x << "," << p.y << ")";
	return os;
}

