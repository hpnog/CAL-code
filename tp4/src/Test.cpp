#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"

#include "Ponto.h"
#include "Util.h"
#include <fstream>

using namespace std;


void testNearestPoints_BF(string in, double res) {
	vector<Ponto> pontos, pontosMP;
	ifstream is(in.c_str());
	lerPontos(is, pontos);

	double d = nearestPoints_BF(pontos, pontosMP);
	cout << in << " - Distancia dos pontos mais proximos: " << d << endl;
	cout << "p1:" << pontosMP[0] << endl;
	cout << "p2:" << pontosMP[1] << endl;

	ASSERT_EQUAL_DELTA(res,d,0.01);
}

void testNP_BruteForce() {
	int nTimeStart = GetMilliCount();
	cout << nTimeStart << endl;
	testNearestPoints_BF("Pontos8",11841.3);
	int nTimeElapsed = GetMilliSpan( nTimeStart );
	cout << nTimeElapsed << endl;

	nTimeStart += nTimeElapsed;
	testNearestPoints_BF("Pontos64",556.066);
	nTimeElapsed = GetMilliSpan( nTimeStart );
	cout << nTimeElapsed << endl;

	nTimeStart += nTimeElapsed;
	testNearestPoints_BF("Pontos1k",100.603);
	nTimeElapsed = GetMilliSpan( nTimeStart );
	cout << nTimeElapsed << endl;

	nTimeStart += nTimeElapsed;
	testNearestPoints_BF("Pontos16k",13.0384);
	nTimeElapsed = GetMilliSpan( nTimeStart );
	cout << nTimeElapsed << endl;

	nTimeStart += nTimeElapsed;
	testNearestPoints_BF("Pontos32k",1);
	nTimeElapsed = GetMilliSpan( nTimeStart );
	cout << nTimeElapsed << endl;

	nTimeStart += nTimeElapsed;
	testNearestPoints_BF("Pontos64k",1);
	nTimeElapsed = GetMilliSpan( nTimeStart );
	cout << nTimeElapsed << endl;

	nTimeStart += nTimeElapsed;
	testNearestPoints_BF("Pontos128k",0);
	nTimeElapsed = GetMilliSpan( nTimeStart );
	cout << nTimeElapsed << endl;
}



void testNearestPoints_DC(string in, double res) {
	vector<Ponto> pontos, pontosMP;
	ifstream is(in.c_str());
	lerPontos(is, pontos);

	double d = nearestPoints_DC(pontos, pontosMP);
	cout << in << " - Distancia dos pontos mais proximos: " << d << endl;
	cout << "p1:" << pontosMP[0] << endl;
	cout << "p2:" << pontosMP[1] << endl;

	ASSERT_EQUAL_DELTA(res,d,0.01);
}

void testNP_DivideConquer() {
	int nTimeStart = GetMilliCount();
	cout << nTimeStart << endl;
	testNearestPoints_DC("Pontos8",11841.3);
	int nTimeElapsed = GetMilliSpan( nTimeStart );
	cout << nTimeElapsed << endl;

	nTimeStart += nTimeElapsed;
	testNearestPoints_DC("Pontos64",556.066);
	nTimeElapsed = GetMilliSpan( nTimeStart );
	cout << nTimeElapsed << endl;

	nTimeStart += nTimeElapsed;
	testNearestPoints_DC("Pontos1k",100.603);
	nTimeElapsed = GetMilliSpan( nTimeStart );
	cout << nTimeElapsed << endl;

	nTimeStart += nTimeElapsed;
	testNearestPoints_DC("Pontos16k",13.0384);
	nTimeElapsed = GetMilliSpan( nTimeStart );
	cout << nTimeElapsed << endl;

	nTimeStart += nTimeElapsed;
	testNearestPoints_DC("Pontos32k",1);
	nTimeElapsed = GetMilliSpan( nTimeStart );
	cout << nTimeElapsed << endl;

	nTimeStart += nTimeElapsed;
	testNearestPoints_DC("Pontos64k",1);
	nTimeElapsed = GetMilliSpan( nTimeStart );
	cout << nTimeElapsed << endl;

	nTimeStart += nTimeElapsed;
	testNearestPoints_DC("Pontos128k",0);
	nTimeElapsed = GetMilliSpan( nTimeStart );
	cout << nTimeElapsed << endl;
}

void runSuite(){
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(testNP_BruteForce));
	s.push_back(CUTE(testNP_DivideConquer));
	cute::ide_listener<> lis;
	cute::makeRunner(lis)(s, "The Suite");
}

int main(){
    runSuite();
    return 0;
}



