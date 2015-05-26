#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Graph.h"
#include "graphviewer.h"

#define DEFAULT_COLOR "black"
#define DYNAMIC true

using namespace std;

Graph<string> graph;
GraphViewer *gv;
int tamanho = 0;
int edgeId = 0;

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

	if(myReadFile.is_open())
		while(!myReadFile.eof())
		{
			getline(myReadFile, id1);
			int id_1 = atoi(id1.c_str());
			getline(myReadFile, id2);
			int id_2 = atoi(id2.c_str());
			if (graph.addEdge(graph.getVertexbyId(id_1), graph.getVertexbyId(id_2)))
			{
				gv->addEdge(edgeId,id_1, id_2,EdgeType::UNDIRECTED);
				gv->setEdgeColor(edgeId, LIGHT_GRAY);
			}

			edgeId++;
		}
	else
		return -1;

	return 0;
}

void listPeople()
{
	system("cls");
	cout << "Conceptcao e Analise de Algoritmos - FEUP\n"
			"Ano 2015 - Tema 2 - Pesquisa em Rede\n\n"
			"\t\tList of People\n\n\n";
	for (int i = 0; i < graph.getNumVertex(); i++)
		cout << graph.getVertexSet()[i]->getId() << " - " << graph.getVertexSet()[i]->getInfo() << endl;
	system("pause");
}

void friendsOfSomeoneSpecific()
{
	int j = -1;
	while (j < 0 && j > graph.getVertexSet().size())
	{
		system("cls");
		cout << "Conceptcao e Analise de Algoritmos - FEUP\n"
				"Ano 2015 - Tema 2 - Pesquisa em Rede\n\n"
				"\t\tList of People\n\n\n"
				"Choose the person of whose friends you want to know\n\n\n";
		for (int i = 0; i < graph.getNumVertex(); i++)
			cout << graph.getVertexSet()[i]->getId() << " - " << graph.getVertexSet()[i]->getInfo() << endl;
		cin >> j;
	}
	system("cls");
	cout << "Conceptcao e Analise de Algoritmos - FEUP\n"
			"Ano 2015 - Tema 2 - Pesquisa em Rede\n\n"
			"\t\tList of People\n\n\n"
			"The friends of: " << graph.getVertexSet()[j]->getInfo()
			<< "\n\n\n";
	for (unsigned int a = 0; a < graph.getVertexSet()[j]->getAdj().size(); a++)
		cout << graph.getVertexSet()[j]->getAdj()[a].getDest()->getId() << " - " << graph.getVertexSet()[j]->getAdj()[a].getDest()->getInfo() << endl;
	if (graph.getVertexSet()[j]->getAdj().size() == 0)
		cout << "This person has no friends :(\n\n";

	system("pause");
}

void addFriendship()
{
	int j, q = -1;
	while (j < 0 || j > graph.getVertexSet().size() || q < 0 || q > graph.getVertexSet().size() || j == q)
	{
		system("cls");
		cout << "Conceptcao e Analise de Algoritmos - FEUP\n"
				"Ano 2015 - Tema 2 - Pesquisa em Rede\n\n"
				"\t\tAdd Friendship\n\n\n";
		for (int i = 0; i < graph.getNumVertex(); i++)
			cout << graph.getVertexSet()[i]->getId() << " - " << graph.getVertexSet()[i]->getInfo() << endl;
		cout << "Person 1: ";
		cin >> j;
		cout << "\nPerson 2: ";
		cin >> q;
	}

	if (graph.addEdge(graph.getVertexbyId(j), graph.getVertexbyId(q)))
	{
		gv->addEdge(edgeId,j, q,EdgeType::UNDIRECTED);
		gv->setEdgeColor(edgeId, LIGHT_GRAY);
		edgeId++;
		cout << "\nFrienship created.\n";
	}
	else
		cout << "\nFrienship already exists.\n\n";

	system("pause");
}

void addPerson()
{
	string j;
	system("cls");
	cout << "Conceptcao e Analise de Algoritmos - FEUP\n"
			"Ano 2015 - Tema 2 - Pesquisa em Rede\n\n"
			"\t\tAdd Person\n\n\n";
	cout << "Name: ";
	cin.ignore();
	getline(cin, j, '\n');
	graph.addVertex(j, tamanho);
	gv->addNode(tamanho);
	gv->setVertexLabel(tamanho, j);
	tamanho++;
	cout << "\nPerson added.\n\n";
	system("pause");
}

void pre_kmp(string pattern, vector<int> & prefix) //funcoes implementadas nas aulas
{
	int m=pattern.length();
	prefix[0]=-1;
	int k=-1;
	for (int q=1; q<m; q++) {
		while (k>-1 && pattern[k+1]!=pattern[q])
			k = prefix[k];
		if (pattern[k+1]==pattern[q]) k=k+1;
		prefix[q]=k;
	}
}

int kmp(string text, string pattern) //funcoes implementadas nas aulas, retorna o numero de ocorrencias
{
	int num=0;
	int m=pattern.length();
	vector<int> prefix(m);
	pre_kmp(pattern, prefix);

	int n=text.length();

	int q=-1;
	for (int i=0; i<n; i++) {
		while (q>-1 && pattern[q+1]!=text[i])
			q=prefix[q];
		if (pattern[q+1]==text[i])
			q++;
		if (q==m-1) {
			num++;
			q=prefix[q];
		}
	}
	return num;
}

void searchName()
{
	int j = -1;
	while (j < 0 && j > graph.getVertexSet().size())
	{
		system("cls");
		cout << "Conceptcao e Analise de Algoritmos - FEUP\n"
				"Ano 2015 - Tema 2 - Pesquisa em Rede\n\n"
				"\t\tSearch by Name\n\n\n"
				"Choose the person of whose friends you want to search\n\n\n";
		for (int i = 0; i < graph.getNumVertex(); i++)
			cout << graph.getVertexSet()[i]->getId() << " - " << graph.getVertexSet()[i]->getInfo() << endl;
		cin >> j;
	}
	system("cls");
	cout << "Conceptcao e Analise de Algoritmos - FEUP\n"
			"Ano 2015 - Tema 2 - Pesquisa em Rede\n\n"
			"\t\tSearch by Name\n\n\n"
			"Choose a name to search\n\n\n";
	string search;
	cin.ignore();
	getline(std::cin,search);
	vector<string> words;
	int last_space = 0;
	for(int i = 0; i < search.size(); i++){
		if(search[i] == ' ' || i + 1 == search.size()){
			if(last_space != i){
				int size = i - last_space;
				if(i + 1 == search.size()) size++;
				words.push_back(search.substr(last_space,size));
		}
			last_space = i + 1;
		}
	}
	system("cls");
	cout << "Conceptcao e Analise de Algoritmos - FEUP\n"
				"Ano 2015 - Tema 2 - Pesquisa em Rede\n\n"
				"\t\tSearch by Name\n\n\n"
				"Results by order:\n\n\n";
	vector<string> res = graph.bfs(graph.getVertexSet()[j]);
	vector<int> num;
	for(unsigned int a = 0; a < res.size(); a++){
		int value = 0;
		for(unsigned int i = 0; i < words.size() ; i++){
			value += kmp(res[a], words[i]);
		}
		num.push_back(value);
	}
	int maxValue = -1;
	for (unsigned int j = 0; j < num.size(); j++)
		if (num[j] > maxValue)
			maxValue = num[j];

	for (;maxValue > 0; maxValue--)
		for (unsigned int order = 0; order < res.size(); order++)
			if (num[order] == maxValue)
				cout << res[order] << endl;

	cout << "\n\n";

	graph.setNotVisited();
	system("pause");
}

void mainMenu()
{
	int choice = -1;
	while (choice < 0 || choice > 6)
	{
		system("cls");
		cout << "Conceptcao e Analise de Algoritmos - FEUP\n"
				"Ano 2015 - Tema 2 - Pesquisa em Rede\n\n"
				"\t\tMain Menu\n\n\n";

		cout << "1 - List of People\n";
		cout << "2 - Friends of Someone specific\n";
		cout << "3 - Add friendship\n";
		cout << "4 - Add Person\n";
		cout << "5 - Rearrange Graphics\n";
		cout << "6 - Search for friends by name\n";
		cout << "0 - Exit\n\n\n";

		cout << "NOTAS:\n\n"
				"Na pesquisa, e tida em conta em primeiro lugar o numero de ocorrencias das "
				"palavras que compoem o campo de pesquisa nos nomes, e seguidamente a sua "
				"proximidade ao utilizador original.\n\n"
				"Em relacao a adicao de pessoas e amizades, estas apenas serao validas enquanto"
				"o programa permanecer aberto.\n\n";

		cin >> choice;

		if (choice == 0)
			return;
		else if (choice == 1)
			listPeople();
		else if (choice == 2)
			friendsOfSomeoneSpecific();
		else if (choice == 3)
			addFriendship();
		else if (choice == 4)
			addPerson();
		else if (choice == 5)
			gv->rearrange();
		else if (choice == 6)
			searchName();

		choice = -1;
	}
}

int main()
{
	cout << "Conceptcao e Analise de Algoritmos - FEUP\n"
			"Ano 2015 - Tema 2 - Pesquisa em Rede\n\n"
			"Pedro Fraga\nJoao Nogueira\nFilipa Barroso\n\n\n";

	initializeGraphViewer();

	if(carregarNomes("nomes.txt") == -1)
	{
		cout << "ERRO! O ficheiro nomes.txt nao foi aberto\n";
		exit(EXIT_FAILURE);
	}
	cout << "Nomes carregados\n";

	if(carregarAmizades("amizades.txt") == -1)
	{
		cout << "ERRO! O ficheiro amizades.txt nao foi aberto\n";
		exit(EXIT_FAILURE);
	}
	cout << "Amizades carregadas\n\n";

	mainMenu();

	return 0;
}
