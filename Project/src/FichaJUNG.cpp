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



void carregarFicheiro(string nome, string cor){

	int lastId = -1;
	ifstream myReadFile;
	myReadFile.open(nome.c_str());
	string output;
	Estacao ultima =  Estacao(-1,"",Coordenadas());
	if (myReadFile.is_open()) {
		Estacao tempo;
		while (!myReadFile.eof()) {
			getline(myReadFile,output);
			int id = atoi(output.c_str());
			getline(myReadFile,output);
			string nome = output;
			getline(myReadFile,output);
			int x = atoi(output.c_str());
			getline(myReadFile,output);
			int y = atoi(output.c_str());
			if(graph.addVertex(Estacao(id,nome,Coordenadas(x,y)))){
				gv->addNode(id,x,y);
				gv->setVertexLabel(id,nome);
					gv->setVertexColor(id, cor);
				tempo = Estacao(id,nome,Coordenadas(x,y));
			}else{
				gv->setVertexColor(id, "black");
				tempo = graph.getVertexbyId(id);
			}
			if(lastId == -1){
				lastId = id;
			}else{
				graph.addEdge(ultima,tempo,0,0,0);
				gv->addEdge(edgeId,lastId,id,EdgeType::UNDIRECTED);
				lastId = id;
				edgeId++;
			}
			ultima = tempo;
		}
	}else{
		cout << "File not opened\n";
	}
}


void carregarGraphos()
{
	//Inicializar graphos
	gv = new GraphViewer(600, 600, NOT_DYNAMIC);
	gv->setBackground("background.jpg");
	gv->createWindow(600, 600);
	gv->defineVertexColor(DEFAULT_COLOR);
	gv->defineEdgeColor(DEFAULT_COLOR);

	carregarFicheiro("linha1.txt", "red");
	carregarFicheiro("linha2.txt", "green");
	carregarFicheiro("linha3.txt", "orange");
	gv->rearrange();

}


int main() {
	carregarGraphos();
	//exercicio2();
	//exercicio3();
	getchar();
	return 0;
}
