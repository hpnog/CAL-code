#include <cstdio>
#include "graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>

void exercicio1();
void exercicio2();
void exercicio3();

void exercicio1()
{
	GraphViewer *gv = new GraphViewer(600, 600, true);
	gv->setBackground("background.jpg");
	gv->createWindow(600, 600);
	gv->defineVertexColor("blue");
	gv->defineEdgeColor("black");

	gv->addNode(0);
	gv->addNode(1);
	gv->addEdge(0, 0, 1, EdgeType::UNDIRECTED);
	gv->removeNode(1);
	gv->addNode(2);
	gv->addEdge(1, 0, 2, EdgeType::UNDIRECTED);
	gv->setVertexLabel(2, "Este é o terceiro nó");
	gv->setEdgeLabel(1, "Esta é a segunda aresta");
	gv->setVertexColor(2, "green");
	gv->setEdgeColor(1, "yellow");

	gv->rearrange();
}

void exercicio2()
{
	GraphViewer *gv = new GraphViewer(600, 600, false);

	ifstream myfile;
	myfile.open ("nos.txt");
	std::string no;

	while (std::getline(myfile, no)) {
		cout << no;
	}

	myfile.close();
	return;
}

void exercicio3()
{

}


int main() {
	//exercicio1();
	exercicio2();
	//exercicio3();
	getchar();
	return 0;
}
