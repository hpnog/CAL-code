#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Graph.h"
#include "graphviewer.h"

#define DEFAULT_COLOR "black"
#define DYNAMIC true

using namespace std;

Graph<string> graph;
GraphViewer *gv;
int tamanho = 0;

void initializeGraphViewer()
{
	//Inicializar graphos
	gv = new GraphViewer(1200, 1200, DYNAMIC);
	gv->createWindow(1200, 1200);
	gv->defineVertexColor(DEFAULT_COLOR);
	gv->defineEdgeColor(DEFAULT_COLOR);
}

int carregarNomes(string nome)
{
	ifstream myReadFile;
	myReadFile.open(nome.c_str());
	string nome_pessoa;

	if(myReadFile.is_open())
		while(!myReadFile.eof())
		{
			getline(myReadFile, nome_pessoa);
			graph.addVertex(nome_pessoa, tamanho);
			gv->addNode(tamanho);
			gv->setVertexLabel(tamanho, nome_pessoa);
			tamanho++;
		}
	else
		return -1;

	return 0;
}

int carregarAmizades(string nome)
{
	ifstream myReadFile;
	myReadFile.open(nome.c_str());
	string id1;
	string id2;
	int edgeId = 0;

	if(myReadFile.is_open())
		while(!myReadFile.eof())
		{
			getline(myReadFile, id1);
			int id_1 = atoi(id1.c_str());
			getline(myReadFile, id2);
			int id_2 = atoi(id2.c_str());
			graph.addEdge(graph.getVertexbyId(id_1), graph.getVertexbyId(id_2));
			gv->addEdge(edgeId,id_1, id_2,EdgeType::UNDIRECTED);
			gv->setEdgeColor(edgeId, LIGHT_GRAY);

			edgeId++;
		}
	else
		return -1;

	return 0;
}

int main()
{
	initializeGraphViewer();

	if(carregarNomes("nomes.txt") == -1)
	{
		cout << "ERRO! O ficheiro nomes.txt nao foi aberto\n";
		exit(EXIT_FAILURE);
	}

	if(carregarAmizades("amizades.txt") == -1)
	{
		cout << "ERRO! O ficheiro amizades.txt nao foi aberto\n";
		exit(EXIT_FAILURE);
	}

	getchar();
	return 0;
}
