/*
 * UtilFunctions.cpp
 */

#include "Ponto.h"
#include "Util.h"
#include <time.h>
#include <sys/timeb.h>

/**
 * function to fill list 'lp' with 'Ponto' objects read from 'is'
 */
void lerPontos(istream &is, vector<Ponto> &vp){
	double x, y;
	if (!is)
		return;
	while (!is.eof()) {
		is >> x >> y;
		Ponto p(x,y);
		vp.push_back(p);
	}
}
//---------------------------------------------------------------------------

/**
 * function to compare 'Ponto' based on 'X' or 'Y'
 */
double comparaPontos(Ponto p1, Ponto p2, int type) {
    if (type == X)
        return p1.x - p2.x;
    return p1.y - p2.y;
}
//---------------------------------------------------------------------------
/**
 * quickSort algorithm for 'std::vector<bestHistory>' by ascending X coordinate
 */
void quickSortX(vector<Ponto> &vp)
{
    quickSort(vp, 0, vp.size()-1, X);
}
//---------------------------------------------------------------------------

/**
 * quickSort algorithm for 'std::vector<bestHistory>' by ascending Y coordinate
 */
void quickSortY(vector<Ponto> &vp)
{
    quickSort(vp, 0, vp.size()-1, Y);
}
//---------------------------------------------------------------------------

void quickSort(vector<Ponto> &v, int left, int right, int type)
{
    if (right - left <= 50)    // if small vector
        insertionSort(v, left, right, type);
    else {
        Ponto p = median3(v, left, right, type);  // x is pivot
        int i = left; int j = right-1;            // partition step
        double comp;
        for(; ; ) {

            comp = -1;
            while (comp < 0) {
                comp = comparaPontos(v[++i], p, type);
            }

            comp = -1;
            while (comp < 0) {
                comp = comparaPontos(p, v[--j], type);
            }
            if (i < j)
                swap(v[i], v[j]);
            else break;
        }
        swap(v[i], v[right-1]);  // reset pivot
        quickSort(v, left, i-1, type);
        quickSort(v, i+1, right, type);
    }
}
//---------------------------------------------------------------------------

/**
 * choose pivot as the median of three values:
 * extremes and central value of vector
 */
Ponto & median3(vector<Ponto> &v, int left, int right, int type)
{
    int center = (left+right) /2;
    if (comparaPontos(v[center], v[left], type) < 0)
        swap(v[left], v[center]);

    if (comparaPontos(v[right], v[left], type) < 0)
        swap(v[left], v[right]);

    if (comparaPontos(v[right], v[center], type) < 0)
        swap(v[center], v[right]);

    swap(v[center], v[right-1]);     // put pivot in position 'right-1'
    return v[right-1];
}
//---------------------------------------------------------------------------

/**
 * for small vectors use a simple method - insertion sort
 */
void insertionSort(vector<Ponto> &v, int left, int right, int type)
{
    for (int i = left+1; i < right+1; i++)
    {
        Ponto tmp = v[i];
        int j;
        for (j = i; j > left && comparaPontos(tmp, v[j-1], type) < 0; j--)
            v[j] = v[j-1];
        v[j] = tmp;
    }
}
//---------------------------------------------------------------------------

/*
 * Print time
 */
// Something like GetTickCount but portable
// It rolls over every ~ 12.1 days (0x100000/24/60/60)
// Use GetMilliSpan to correct for rollover

int GetMilliCount()
{
  timeb tb;
  ftime( &tb );
  int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
  return nCount;
}
//---------------------------------------------------------------------------
double nearestPDC(vector<Ponto> & vp, int l, int r, vector<Ponto> & vMP) {
	vMP.resize(2);
	vector<Ponto> vMPl = vMP;
	vector<Ponto> vMPr = vMP;

	//-------------------Se apenas houver 2 pontos---------------------------------------------------
	if ((r-l) == 1) {
		vMP[0] = vp[l];
		vMP[1] = vp[r];
		return vMP[0].distancia(vMP[1]);
	}
	//-------------------Se apenas houver 1 ponto----------------------------------------------------
	if (r == l)
		return DMAXIMUM;

	int middle = (r+l)/2;

	//-------------------Chega ao minimo do lado esquerdo/direito------------------------------------
	double dminL = nearestPDC(vp, l, middle, vMPl);
	double dminR = nearestPDC(vp, middle+1, r, vMPr);
	double dmin;
	//-------------------Verifica qual o minimo mais pequeno-----------------------------------------
	if (dminL < dminR) {
		dmin = dminL;
		vMP[0] = vMPl[0];
		vMP[1] = vMPl[1];
	}
	else {
		dmin = dminR;
		vMP[0] = vMPr[0];
		vMP[1] = vMPr[1];
	}
	//-------------------Calcula faixa central para comparações entre pontos dos 2 lados------------
	int index = middle;
	int indexL = index;
	int indexR = index;

	while (indexL > l && comparaPontos(vp[index], vp[indexL], X) < dmin)
		indexL--;

	while (indexR < r && comparaPontos(vp[index], vp[indexR], X) < dmin)
		indexR++;
	//---Com o espaço já limitado, força bruta é aplicável pois o número de pontos já é reduzido---
	vector<Ponto> temp;
	for (int i = indexL; i <= indexR; i++)
		temp.push_back(vp[i]);

	dmin = min(dmin, nearestPoints_BF(temp, vMP));
	return dmin;
}

int GetMilliSpan(int nTimeStart)
{
  int nSpan = GetMilliCount() - nTimeStart;
  if (nSpan < 0)
	  nSpan += 0x100000 * 1000;
  return nSpan;
}

double nearestPoints_BF(vector<Ponto>& vp, vector<Ponto>& vMP) {
	double dist = DMAXIMUM;
	vMP.push_back(Ponto(0,0));
	vMP.push_back(Ponto(0,0));

	for (unsigned int i = 0; i < vp.size(); i++) {
		for (unsigned int j = i + 1; j < vp.size(); j++) {
			double distTemp = vp[i].distancia(vp[j]);
			if (distTemp < dist) {
				vMP[0] = vp[i];
				vMP[1] = vp[j];
				dist = distTemp;
			}
		}
	}
	return dist;
}

double nearestPoints_DC(vector<Ponto>& vp, vector<Ponto>& vMP) {
	quickSortX(vp);
	return nearestPDC(vp, 0, vp.size()-1, vMP);
}
//---------------------------------------------------------------------------

