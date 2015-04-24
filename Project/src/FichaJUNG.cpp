#include <cstdio>
#include "graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <conio.h>
#include <vector>
#include "Graph.h"
#include "Estacao.h"
#include "DadosGraficos.h"

#define DEFAULT_COLOR "black"
#define NOT_DYNAMIC false

Graph<Estacao> graph;
GraphViewer *gv;
vector<DadosGraficos> dg;
int edgeId = 0;
int tempId = -2; //para estacoes em paralelo

void carregarFicheiro(string nome, string cor, int line)
{

	int lastId = -1;
	ifstream myReadFile;
	myReadFile.open(nome.c_str());
	string output;
	Estacao ultima =  Estacao(-1,"",Coordenadas(),line);
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
			if(graph.addVertex(Estacao(id,nome,Coordenadas(x,y),line)))
			{
				gv->addNode(id,x,y);
				gv->setVertexLabel(id,nome);
				gv->setVertexColor(id, cor);
				tempo = Estacao(id,nome,Coordenadas(x,y),line);
			}
			else
			{
				gv->setVertexColor(id, "black");
				nome =  graph.getVertexbyId(id).getNome();
				graph.addVertex(Estacao(tempId,nome,Coordenadas(x,y),line));
				tempo = graph.getVertexbyId(tempId);
				graph.addEdge(graph.getVertexbyId(id), tempo, 1000, line);
				graph.addEdge(tempo, graph.getVertexbyId(id), 1000, line);
				for(int i = 0; i < graph.getVertexbyId(id).getLinked().size(); i++){
					int id_temp = graph.getVertexbyId(id).getLinked()[i];
					graph.addEdge(graph.getVertexbyId(id_temp), tempo, 1000, line);
					graph.addEdge(tempo, graph.getVertexbyId(id_temp), 1000, line);
				}
				graph.getVertexbyIdPointer(id)->push_back(tempId);
				tempId--;
			}

			if (lastId == -1)
			{
				lastId = id;
			}
			else
			{
				double dist = sqrt(((abs(y - ultima.getCoordenadas().gety())) ^ 2) + ((abs(x - ultima.getCoordenadas().getx())) ^ 2));
				graph.addEdge(ultima, tempo, dist, line);
				graph.addEdge(tempo, ultima, dist, line);
				gv->addEdge(edgeId,lastId,id,EdgeType::UNDIRECTED);
				dg.push_back(DadosGraficos(edgeId,lastId,id));
				dg.push_back(DadosGraficos(edgeId,id,lastId));
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

int getEdgeId(int a, int b){
	for(int i = 0; i < dg.size(); i++){
		if(dg[i].id_origem == a && dg[i].id_destino == b){
			return dg[i].id_aresta;
		}
	}
	return -1;
}

void interfaceCliente(){
	system("CLS");
	int origem;
	int destino;
	for(int i = 0; i < graph.getNumVertex(); i++){
		stringstream ss;
		ss << graph.getVertexSet()[i]->getInfo().getNome() << " (linha " << graph.getVertexSet()[i]->getInfo().getLinha() << ")" << endl;
		string str = ss.str();
		cout << endl << i + 1 << ". " << str;
	}
	cout << endl << "Escolhe o numero da estacao de origem: ";
	cin >> origem;
	destino = origem;
	while(destino == origem){
	cout << "Escolhe o numero da estacao de destino: ";
	cin >> destino;
	if(destino ==  origem){
		cout << "O destino nao pode ser igual a origem, escolhe outra vez." << endl;
		return;
	}
	Estacao est_origem = graph.getVertexSet()[origem - 1]->getInfo();
	graph.dijkstraShortestPath(graph.getVertexSet()[origem - 1]->getInfo());
	vector<Estacao> caminho = graph.getPath(graph.getVertexSet()[origem - 1]->getInfo(), graph.getVertexSet()[destino - 1]->getInfo());
	system("CLS");
	Estacao last;
	cout << "O caminho mais curto: " << endl;
	for(int i = 0; i < caminho.size(); i++){
		if(i > 0){
			int id1 = graph.getFirstId(last.getNome());
			int id2 = graph.getFirstId(caminho[i].getNome());
			gv->setEdgeColor(getEdgeId(id1,id2), "green");
			gv->setEdgeThickness(getEdgeId(id1,id2), 8);
		}
		stringstream ss;
		ss << caminho[i].getNome() << " (linha " << caminho[i].getLinha() << ")";
		string str = ss.str();
		cout << str << endl;
		last = caminho[i];
	}
	gv->rearrange();
	getchar();
	}
}

int main() {
	cout << "A carregar...\n";
	carregarGraphos();
	interfaceCliente();
	getchar();
	return 0;
}
