#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include "Graph.h"
#include "Person.h"


void createNetwork(Graph<Person> & net1)
{
Person p1("Ana",19);
Person p2("Carlos",33);
Person p3("Filipe", 20);
Person p4("Ines", 18);
Person p5("Maria", 24);
Person p6("Rui",21);
Person p7("Vasco",28);
net1.addVertex(p1); net1.addVertex(p2);
net1.addVertex(p3); net1.addVertex(p4);
net1.addVertex(p5); net1.addVertex(p6); net1.addVertex(p7);
net1.addEdge(p1,p2,0);
net1.addEdge(p1,p3,0);
net1.addEdge(p1,p4,0);
net1.addEdge(p2,p5,0);
net1.addEdge(p5,p6,0);
net1.addEdge(p5,p1,0);
net1.addEdge(p3,p6,0);
net1.addEdge(p3,p7,0);
net1.addEdge(p6,p2,0);
}

void test_addVertex() {
	Graph<Person> net1;
	Person p1("Ana",19);
	Person p2("Carlos",33);
	Person p3("Filipe", 20);
	Person p4("Inês", 18);
	net1.addVertex(p1); net1.addVertex(p2);
	net1.addVertex(p3); net1.addVertex(p4);
	ASSERT_EQUAL(false, net1.addVertex(p2));
	ASSERT_EQUAL(4, net1.getNumVertex());
}

void test_removeVertex() {
	Graph<Person> net1;
	Person p1("Ana",19);
	Person p2("Carlos",33);
	Person p3("Filipe", 20);
	Person p4("Inês", 18);
	net1.addVertex(p1); net1.addVertex(p2);
	net1.addVertex(p3); net1.addVertex(p4);
	ASSERT_EQUAL(true, net1.removeVertex(p2));
	ASSERT_EQUAL(false, net1.removeVertex(p2));
	ASSERT_EQUAL(3, net1.getNumVertex());
}

void test_addEdge() {
	Graph<Person> net1;
	Person p1("Ana",19);
	Person p2("Carlos",33);
	Person p3("Filipe", 20);
	Person p4("Inês", 18);
	Person p5("Maria", 24);
	net1.addVertex(p1); net1.addVertex(p2);
	net1.addVertex(p3); net1.addVertex(p4);
	ASSERT_EQUAL(true, net1.addEdge(p1,p2,0));
	ASSERT_EQUAL(true, net1.addEdge(p1,p3,0));
	ASSERT_EQUAL(true, net1.addEdge(p1,p4,0));
	ASSERT_EQUAL(false, net1.addEdge(p2,p5,0));
}

void test_removeEdge() {
	Graph<Person> net1;
	Person p1("Ana",19);
	Person p2("Carlos",33);
	Person p3("Filipe", 20);
	Person p4("Inês", 18);
	Person p5("Maria", 24);
	net1.addVertex(p1); net1.addVertex(p2);
	net1.addVertex(p3); net1.addVertex(p4);
	ASSERT_EQUAL(true, net1.addEdge(p1,p2,0));
	ASSERT_EQUAL(true, net1.addEdge(p1,p3,0));
	ASSERT_EQUAL(true, net1.addEdge(p1,p4,0));
	ASSERT_EQUAL(true, net1.addEdge(p2,p4,0));
	ASSERT_EQUAL(true, net1.removeEdge(p1,p3));
	ASSERT_EQUAL(false, net1.removeEdge(p1,p5));
	ASSERT_EQUAL(false, net1.removeEdge(p2,p3));
}


void test_dfs() {
	Graph<Person> net1;
	createNetwork(net1);
	vector<Person> v1=net1.dfs();
	ASSERT_EQUAL("Ana", v1[0].getName());
	ASSERT_EQUAL("Carlos", v1[1].getName());
	ASSERT_EQUAL("Maria", v1[2].getName());
	ASSERT_EQUAL("Rui", v1[3].getName());
	ASSERT_EQUAL("Filipe", v1[4].getName());
	ASSERT_EQUAL("Vasco", v1[5].getName());
	ASSERT_EQUAL("Ines", v1[6].getName());
}

void test_bfs() {
	Graph<Person> net1;
	createNetwork(net1);
	vector<Person> v1=net1.bfs(net1.getVertexSet()[0]);
	ASSERT_EQUAL("Ana", v1[0].getName());
	ASSERT_EQUAL("Carlos", v1[1].getName());
	ASSERT_EQUAL("Filipe", v1[2].getName());
	ASSERT_EQUAL("Ines", v1[3].getName());
	ASSERT_EQUAL("Maria", v1[4].getName());
	ASSERT_EQUAL("Rui", v1[5].getName());
	ASSERT_EQUAL("Vasco", v1[6].getName());
}

void test_removeVertex_Again() {
	Graph<Person> net1;
	createNetwork(net1);
	Person p2("Carlos",33);
	ASSERT_EQUAL(true, net1.removeVertex(p2));
	vector<Person> v1=net1.dfs();
	ASSERT_EQUAL("Ana", v1[0].getName());
	ASSERT_EQUAL("Filipe", v1[1].getName());
	ASSERT_EQUAL("Rui", v1[2].getName());
	ASSERT_EQUAL("Vasco", v1[3].getName());
	ASSERT_EQUAL("Ines", v1[4].getName());
	ASSERT_EQUAL("Maria", v1[5].getName());
}

void test_removeEdge_Again() {
	Graph<Person> net1;
	createNetwork(net1);
	Person p5("Maria", 24);
	Person p6("Rui",21);
	ASSERT_EQUAL(true, net1.removeEdge(p5,p6));
	vector<Person> v1=net1.dfs();
	ASSERT_EQUAL("Ana", v1[0].getName());
	ASSERT_EQUAL("Carlos", v1[1].getName());
	ASSERT_EQUAL("Maria", v1[2].getName());
	ASSERT_EQUAL("Filipe", v1[3].getName());
	ASSERT_EQUAL("Rui", v1[4].getName());
	ASSERT_EQUAL("Vasco", v1[5].getName());
	ASSERT_EQUAL("Ines", v1[6].getName());
}

void test_maxNewChildren() {
	Graph<Person> net1;
	Person p1("Ana",19);
	Person p2("Carlos",33);
	Person p3("Filipe", 20);
	Person p4("Inês", 18);
	Person p5("Maria", 24);
	Person p6("Rui",21);
	Person p7("Vasco",28);
	net1.addVertex(p1); net1.addVertex(p2);
	net1.addVertex(p3); net1.addVertex(p4);
	net1.addVertex(p5); net1.addVertex(p6); net1.addVertex(p7);
	net1.addEdge(p1,p2,0);
	net1.addEdge(p1,p3,0);
	net1.addEdge(p2,p5,0);
	net1.addEdge(p3,p4,0);
	net1.addEdge(p5,p6,0);
	net1.addEdge(p5,p1,0);
	net1.addEdge(p3,p6,0);
	net1.addEdge(p3,p7,0);
	net1.addEdge(p3,p2,0);
	Person pt;
	ASSERT_EQUAL(3, net1.maxNewChildren(net1.getVertexSet()[0],pt));
	ASSERT_EQUAL("Filipe", pt.getName());
}





void runSuite(){
	cute::suite s;
	s.push_back(CUTE(test_addVertex));
	s.push_back(CUTE(test_removeVertex));
	s.push_back(CUTE(test_addEdge));
	s.push_back(CUTE(test_removeVertex));
	s.push_back(CUTE(test_dfs));
	s.push_back(CUTE(test_bfs));
	s.push_back(CUTE(test_removeVertex_Again));
	s.push_back(CUTE(test_removeEdge_Again));
	s.push_back(CUTE(test_maxNewChildren));
	cute::ide_listener <> lis;
	cute::makeRunner(lis)(s, "CAL 2012/2013 - Aula Pratica 4");
}

int main(){
    runSuite();
    return 0;
}


