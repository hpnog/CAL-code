/*
 * Ponto.h
 */

#ifndef PONTO_H_
#define PONTO_H_

#include <iostream>
#include <vector>

using namespace std;

class Ponto {
public:
	double x;
	double y;

	Ponto();
	Ponto(double x, double y);
	Ponto(int x, int y);
	double distancia(Ponto &p);
	virtual ~Ponto();
	bool operator==(const Ponto &p) const;
};
ostream& operator<<(ostream& os, Ponto &p);


#endif /* PONTO_H_ */
