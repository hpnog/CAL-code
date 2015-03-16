
#ifndef UTIL_H_
#define UTIL_H_

/*
 * constantes e funcoes genericas
 */
const int X=0;
const int Y=1;
const double DMAXIMUM=999999999;

void lerPontos(istream &is, vector<Ponto> &vp);
double comparaPontos(Ponto p1, Ponto p2, int type);

void quickSortX(vector<Ponto> &vp);
void quickSortY(vector<Ponto> &vp);
void quickSort(vector<Ponto> &v, int left, int right, int type);
Ponto& median3(vector<Ponto> &v, int left, int right, int type);
void insertionSort(vector<Ponto> &v, int left, int right, int type);

int GetMilliCount();
int GetMilliSpan(int nTimeStart);

/* Funcoes a implementar */
double nearestPoints_DC(vector<Ponto> &vp, vector<Ponto> &vMP);
double nearestPoints_BF(vector<Ponto> &vp, vector<Ponto> &vMP);

#endif
