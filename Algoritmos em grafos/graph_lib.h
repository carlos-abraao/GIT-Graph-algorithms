#include <iostream>
#include <map>
#include <set>
#include <fstream>
#include <utility>
#include <limits>

using namespace std;

struct Adj_list{

	int size;
	egde* front;
	edge* end;

};

struct edge
{
	int u;
	double weight;
	edge* next;
	edge* previus;
};

void Init_G(Adj_list &L){
	L.size 		= 0;
	L.next 		= NULL;
	L.previus 	= NULL;
}

void G_add_front(Adj_list &G, int u, double w){

	egde newE;
	newE.u 			= u;
	newE,weight  	= w;
	newE.next		= L.front;
	newE.previus	= NULL;
	L.front 		= newE;
	if(L.size == 0 ) L.end = newE;
	L.size++;

}

void G_add_end(Adj_list &G, int u, double w){

	egde newE;
	newE.u 			= u;
	newE,weight  	= w;
	newE.next		= NULL;
	newE.previus	= L.end;
	L.end 			= newE;
	if(L.size == 0) L.front = newE;
	L.size++;


}

int n, m;

void create_graph(const char* filename){

	ifstream dados(filename, ifstream::in);	

	if (dados.fail()) {
		cerr << "     File \"" << filename << "\" not found." << endl;
		//exit(1);
	}	

	dados >> n >> m;

	Adj_list[n] Graph;

	
	int row, column;
	double weight;

	for(int i=0; i<m; i++){
		dados >> row >> column >> weight;
		
	}	

}