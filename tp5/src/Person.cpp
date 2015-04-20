/*
 * Person.cpp
 */

#include "Person.h"

Person::Person(string n, int a): name(n), age(a) {}
Person::Person(){}

string Person::getName() const {
	return name;
}

bool Person::operator == (const Person &p2) const {
	return (name==p2.name && age==p2.age);
}

ostream & operator << (ostream &os, Person &p) {
   os << p.getName();
   return os;
}
