#include <cstdio>
#include "graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "Graph.h"
#include "Estacao.h"

#define DEFAULT_COLOR "black"
#define NOT_DYNAMIC false

Graph<Estacao> graph;
GraphViewer *gv;
int edgeId = 0;

void carregarFicheiro(string nome, string cor, int line)
{

	int lastId = -1;
	ifstream myReadFile;
	myReadFile.open(nome.c_str());
	string output;
	Estacao ultima =  Estacao(-1,"",Coordenadas());
	if (myReadFile.is_open())
	{
		Estacao tempo;
		int x, y;
		while (!myReadFile.eof())
		{
			getline(myReadFile,output);
			int id = atoi(output.c_str());
			getline(myReadFile,output);
			string nome = output;
			getline(myReadFile,output);
			x = 2 * atoi(output.c_str());
			getline(myReadFile,output);
			y = 2 * atoi(output.c_str());
			if(graph.addVertex(Estacao(id,nome,Coordenadas(x,y))) && ultima.getId() < id)
			{
				gv->addNode(id,x,y);
				gv->setVertexLabel(id,nome);
				gv->setVertexColor(id, cor);
				tempo = Estacao(id,nome,Coordenadas(x,y));
			}
			else
			{
				gv->setVertexColor(id, "black");
				tempo = graph.getVertexbyId(id);
			}
			if (lastId == -1)
			{
				lastId = id;
			}
			else
			{
				double dist = sqrt(((abs(y - ultima.getCoordenadas().gety())) ^ 2) + ((abs(x - ultima.getCoordenadas().getx())) ^ 2));
				graph.addEdge(ultima, tempo, dist, line);
				gv->addEdge(edgeId,lastId,id,EdgeType::UNDIRECTED);
				lastId = id;
				edgeId++;
			}
			ultima = tempo;
		}
	}
	else
	{
		cout << "File not opened\n";
	}
}

void carregarGraphos()
{
	//Inicializar graphos
	gv = new GraphViewer(1200, 1200, NOT_DYNAMIC);
	gv->setBackground("background.png");
	gv->createWindow(1200, 1200);
	gv->defineVertexColor(DEFAULT_COLOR);
	gv->defineEdgeColor(DEFAULT_COLOR);

	carregarFicheiro("linha1.txt", "red", 1);
	carregarFicheiro("linha2.txt", "green", 2);
	carregarFicheiro("linha3.txt", "orange", 3);
	carregarFicheiro("linha4.txt", "blue", 4);
	carregarFicheiro("linha5.txt", "pink", 5);
	gv->rearrange();

}

int main() {
	carregarGraphos();
	//exercicio2();
	//exercicio3();
	getchar();
	return 0;
}
