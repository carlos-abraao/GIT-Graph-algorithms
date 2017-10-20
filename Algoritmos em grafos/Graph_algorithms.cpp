#include <iostream>
#include "graph_lib.h"

using namespace std;

int main(int argc, char *argv[]) {
	time_t tini, tfim;

	if (argc < 2) {
		cerr << "\nError - try: " << argv[0] << " input-instance-file" << endl;
		return 2;
	}

	cout << "Welcome to my graph algorithms code for the discipline CK0111 - ALGORITMOS EM GRAFOS (2017.1 - T01) at UFC-BR\n ";
	cout << "All the algorithms here, are based on the adjacency list representation of a graph. \n";
	cout << "\n\n";

	cout << "The Graph is directed?\n";
	cout << "1 - yes\n";
	cout << "0 - no\n";

	bool g;
	cin >> g;

	if(g == 0){
		create_graph(argv[1]);
	}
	else{
		create_digraph(argv[1]);
	}	

	printGraph(Graph, n);

	tini = time(0);

	Top_Sort(Graph, 1, n);

	tfim = time(0);
	
	return 0;
}
