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
	
	create_graph(argv[1]);

	tini = time(0);

	//generic algorithm

	tfim = time(0);
	
	return 0;
}
