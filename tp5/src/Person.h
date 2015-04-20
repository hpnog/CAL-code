/*
 * Person.h
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <string>
using namespace std;

class Person {
	string name;
	int age;
public:
	Person();
	Person (string n, int a);
	string getName() const;
	bool operator == (const Person &p2) const;
	friend ostream & operator << (ostream &os, Person &p);
};

#endif /* NETWORK_H_ */
