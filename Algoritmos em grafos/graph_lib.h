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

int size 		(Adj_list L);
void destroy	(Adj_list &L);



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
		newE -> previus = NULL;
		L.front 		= newE;
		L.end 			= newE;
	}
	else{
		newE -> next 	   = L.front;
		L.front -> previus = newE;
		L.front 		   = newE;
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
		L.end->next 	= newE;
		L.end 	= newE;
	}

	L.ActualSize++;
}

edge* G_reomve_front(Adj_list &L) {	
	edge* value = new edge;

	// standard values in case of empty graph
	value -> next	 = NULL;
	value -> previus = NULL;
	value -> u 		= 999999; 		
	value -> weight = 999999;

	//if not empty
	if (size(L)!=0){
		//special case of size=1
	    if ( size(L)==1){
		    value -> u      = L.end->u;
		    value -> weight = L.end->weight;
		    destroy(L);
	    }
	    //general case
		else{
			value -> u      = L.front->u;
		    value -> weight = L.front->weight;
			edge* aux 		= L.front->next;
			delete L.front;
			L.front = aux;
			--L.ActualSize;
		}
	}
	
	return value;
}
edge* G_remove_end(Adj_list &L) {
	edge* value 	 = new edge;
	// standard values in case of empty graph
	value -> next	 = NULL;
	value -> previus = NULL;	
	value -> u 		 = 999999; 		
	value -> weight  = 999999;

	//if not empty
	if (L.ActualSize > 0) {
		value-> u 	   = L.end->u;
		value-> weight = L.end->weight;

		//special case of size=1
		if (L.ActualSize == 1) {
			delete L.end;
			L.end = NULL;
			L.front = NULL;
		}
		// Sgeneral case
		else { 
			edge *aux = L.end->previus;
			delete L.end;
			L.end = aux;
			L.end->next = NULL;
		}		
		L.ActualSize--;
	}

	return value;
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

void printGraph(Adj_list L[], int n){
	for (int i = 0; i < n; i++){
		edge* aux = L[i].front;
		cout << "neighboors of " << i+1 << ":\n";
		while(aux!= NULL){
			cout << "vertex " << aux->u << " with weight: " << aux->weight << "\n";
			aux = aux->next;
		}
	}

}


int n, m;
Adj_list* Graph;

void create_graph(const char* filename){

	ifstream dados(filename, ifstream::in);	

	if (dados.fail()) {
		cerr << "     File \"" << filename << "\" not found." << endl;
		//exit(1);
	}	

	dados >> n >> m;
	
	Graph = new Adj_list [n];
	for(int i = 0; i < n; i++){
		Init_G(Graph[i]);
	}
	
	
	int row, column;
	double weight;

	for(int i=0; i<m; i++){
		dados >> row >> column >> weight;
		G_add_end(Graph[row-1], column, weight);
		G_add_end(Graph[column-1], row, weight);
		
	}	

}