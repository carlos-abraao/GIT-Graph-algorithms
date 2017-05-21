#include <iostream>
#include <map>
#include <set>
#include <fstream>
#include <utility>
#include <limits>

using namespace std;

struct Adj_list{

	int v;
	int size;
	egde* front;
	edge* end;

};

struct edge
{
	int u;
	edge* next;
	edge* previus;
};

void G_add_front

int n, m;

void create_graph(const char* filename){

	ifstream dados(filename, ifstream::in);	

	if (dados.fail()) {
		cerr << "     File \"" << filename << "\" not found." << endl;
		//exit(1);
	}	

	dados >> n >> m;

	Adj_list[n] Graph;

	
	int linha, coluna;
	double peso;

	for(int i=0; i<m; i++){
		dados >> linha >> coluna >> peso;
		
	}	

}