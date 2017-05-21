#include <iostream>
#include <map>
#include <set>
#include <fstream>
#include <utility>
#include <limits>

using namespace std;

struct edge
{
	int u;
	double weight;
	edge* next;
	edge* previus;
};

struct Adj_list{

	int   ActualSize;
	edge* front;
	edge* end;

};


void Init_G(Adj_list &L){
	L.ActualSize = 0;
	L.front	 = NULL;
	L.end 	 = NULL;
}

void G_add_front(Adj_list &L, int u, double w){

	edge* newE = new edge;
	newE -> u 			= u;
	newE -> weight  	= w;	
	newE -> previus		= NULL;	

	if(L.ActualSize == 0 ){
		newE -> next	= NULL;
		L.front 		= newE;
		L.end 			= newE;
	}
	else{
		newE -> next 	= L.front;
		L.front 		= newE;
	} 

	L.ActualSize++;

}

void G_add_end(Adj_list &L, int u, double w){

	edge* newE = new edge;
	newE -> u		= u;
	newE -> weight 	= w;
	newE -> next	= NULL;
		
	if(L.ActualSize == 0) {
		L.front = newE;
		L.end 	= newE;
		newE -> previus	= NULL;
	}
	else{
		newE -> previus	= L.end;
		L.end 	= newE;
	}

	L.ActualSize++;
}

int size(Adj_list L) {
	return L.ActualSize;
}

void destroy(Adj_list &L) {
	while (L.front != NULL) {
		edge *p  = L.front;
		L.front = L.front->next;
		delete p;
	}
	L.ActualSize = 0;
}


int n, m;

void create_graph(const char* filename){

	ifstream dados(filename, ifstream::in);	

	if (dados.fail()) {
		cerr << "     File \"" << filename << "\" not found." << endl;
		//exit(1);
	}	

	dados >> n >> m;

	Adj_list* Graph;
	Graph = new Adj_list [n];

	
	int row, column;
	double weight;

	for(int i=0; i<m; i++){
		dados >> row >> column >> weight;
		
	}	

}