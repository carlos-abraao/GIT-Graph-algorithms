#include <iostream>
#include <map>
#include <set>
#include <fstream>
#include <utility>
#include <limits>
#include <queue>

using namespace std;

struct edge
{
	int u;			//incident vertex
	double weight;	//actual eight of the edge
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

void visit_neighbors(Adj_list L, int n){
	cout << "Visiting neighbors of vertex: " << n << endl;
	edge* aux = new edge;
	aux = L.front;
	while(aux != NULL){
		cout << "vertex: " << aux->u << " weight: " << aux-> weight <<endl;
		aux = aux -> next;
	}
	delete aux;
	cout << "\n\n";

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

	cout << "\n\n";

}

void BFS(Adj_list L[], int u, int n){
	cout << "\n\n";
	cout << "Starting BFS algorithm.\n";

	int size = n;
	int* color = new int [size];
	int* dis   = new int [size];
	int* pi    = new int [size];
	for(int i = 0; i < size; i++){
		color[i] = 0;
		dis[i] 	 = 9999999;
		pi[i] 	 = -1;
	}
	color[u-1] = 1;
	dis[u-1]   = 0;
	pi[u-1]	   = -1;

	queue<int> Q;
	Q.push(u-1);

	int aux;
	edge* auxE = new edge;
	while(Q.empty() == 0){
		
		aux = Q.front(); Q.pop();			
		
		auxE = L[aux].front;
		while(auxE != NULL){
			if(color[(auxE->u)-1] == 0){

				color[(auxE->u)-1] = 1;				
				dis[(auxE->u)-1]   = dis[aux]+1;
				pi[(auxE->u)-1]	   = aux+1;
				Q.push((auxE->u)-1);
				
			}
			auxE = auxE -> next;
		}
		color[aux] = 2;
	}

	for(int i = 0; i < size; i++){
		cout << "final color of "<< i+1 <<": " <<	color[i] << endl;
		cout << "final distance of "<< i+1 <<": " <<	dis[i] << endl;
		cout << "final predecesor of "<< i+1 <<": " <<	pi[i] << endl;
		cout << "\n\n";
	}

}

int time_dfs = 0;
int* dscvry_dfs	;
int* fnsh_dfs	;
int* color_dfs	;
int* pi_dfs		;

void DFS_visit(Adj_list G[], int u){
	time_dfs++;
	dscvry_dfs[u] = time_dfs;
	color_dfs[u]  = 1;
	edge* aux 	  = new edge;
	aux 		  = G[u].front;

	while(aux != NULL){
		if(color_dfs[aux->u-1] == 0){
			pi_dfs[aux->u-1] = u+1;
			DFS_visit(G, aux->u-1 );
		}
		aux = aux->next;
	}
	color_dfs[u] = 2;
	time_dfs++;
	fnsh_dfs[u] = time_dfs;

}

void DFS(Adj_list G[], int u, int n){
	dscvry_dfs = new int [n];
	fnsh_dfs   = new int [n];
	color_dfs  = new int [n];
	pi_dfs	   = new int [n];

	for(int i = 0; i < n; i++){
		color_dfs[i] = 0;
		pi_dfs	 [i] = -1;
	}
	time_dfs = 0;
	for(int i = 0; i < n; i++){
		if(color_dfs[i] == 0){
			DFS_visit(G, i);
		}
	}
	for(int i = 0; i < n; i++){
		cout << "Vertex: "  << i+1 <<endl;
		cout << "time of discovery of vertex "  << i+1 << ": " << dscvry_dfs[i]	<< endl;
		cout << "time of finish of vertex " 	<< i+1 << ": " << fnsh_dfs[i] 	<< endl;
		cout << "predecesor of vertex " 		<< i+1 << ": " << pi_dfs[i] 	<< endl;
		cout << "\n\n";
	}
}

int *top, t = 0;

void Top_visit(Adj_list G[], int u){
	time_dfs++;
	dscvry_dfs[u] = time_dfs;
	color_dfs[u]  = 1;
	edge* aux 	  = new edge;
	aux 		  = G[u].front;

	while(aux != NULL){
		if(color_dfs[aux->u-1] == 0){
			pi_dfs[aux->u-1] = u+1;
			Top_visit(G, aux->u-1);
			
		}
		aux = aux->next;
	}
	color_dfs[u] = 2;
	time_dfs++;
	fnsh_dfs[u] = time_dfs;
	top[t] = aux->u-1;
	t++;

}

void Top_Sort(Adj_list G[], int u, int n){
	dscvry_dfs = new int [n];
	fnsh_dfs   = new int [n];
	color_dfs  = new int [n];
	pi_dfs	   = new int [n];
	top        = new int [n];

	t = 0;

	for(int i = 0; i < n; i++){
		color_dfs[i] = 0;
		pi_dfs	 [i] = -1;
	}
	time_dfs = 0;
	for(int i = 0; i < n; i++){
		if(color_dfs[i] == 0){
			Top_visit(G, i);						
		}
	}

	cout << top[0] << " enita\n";

	for(int i = 0; i < n; i++){
		cout << top[i] << " ";
	}
	cout << endl;

	cout << "enita\n";
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


void create_digraph(const char* filename){

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
		
	}

}

