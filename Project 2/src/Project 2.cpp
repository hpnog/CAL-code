#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Graph.h"
using namespace std;

Graph<string> graph;
int tamanho = 0;

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

	if(myReadFile.is_open())
		while(!myReadFile.eof())
		{
			getline(myReadFile, id1);
			int id_1 = atoi(id1.c_str());
			getline(myReadFile, id2);
			int id_2 = atoi(id2.c_str());
			graph.addEdge(graph.getVertexbyId(id_1), graph.getVertexbyId(id_2));
		}
	else
		return -1;

	return 0;
}

int main()
{
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

	return 0;
}
