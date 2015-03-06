/*
 * Partioning.h
 */

#ifndef PARTITIONING_H_
#define PARTITIONING_H_

#include "Defs.h"

/*Implementa a função s(n,k) usando recursividade*/
int s_recursive(int n,int k);

/*Implementa a função b(n) usando recursividade*/
int b_recursive(int n);

/*Implementa a função s(n,k) usando programação dinâmica*/
int s_dynamic(int n,int k);

/*Implementa a função b(n) usando programação dinâmica*/
int b_dynamic(int n);

#endif /* SUM_H_ */
