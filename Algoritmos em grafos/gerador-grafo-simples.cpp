#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <sstream>

using namespace std; 

ofstream saida;
typedef pair<int, int> arc;
double prob, u;
map<arc, double> arcs;
string filename, str1, str2, str3;
bool again = 0;
bool interval;
int n, qtde, range;
double p;

void naming(int t);

void discrete(){

	for(int t=1; t<=qtde; t++){			

		for (int i = 1; i<n; i++) {

			for (int j = i+1; j<=n; j++) {
								
					prob = ((double) rand() / (RAND_MAX));			
					if(prob<=p ){
						u = rand() % range +1;				
						arcs.insert(make_pair(make_pair(i,j),u));					
				}
			}
		}

		naming(t);
		

		saida.open(filename.c_str());
		
		saida << n << " " << arcs.size() << endl;
		
		for(map<arc, double>::iterator it = arcs.begin(); it!=arcs.end(); it++) saida << it->first.first << " " << it->first.second << " " << it->second << endl;
		
		arcs.clear();

		saida.close();

	}
}

void continous(){
	for(int t=1; t<=qtde; t++){			

		for (int i = 1; i<n; i++) {

			for (int j = i+1; j<=n; j++) {
								
					prob = ((double) rand() / (RAND_MAX));			
					if(prob<=p ){
						prob = ((double) rand() / (RAND_MAX));
						u = (rand() % range +1);
						u *= prob;
						arcs.insert(make_pair(make_pair(i,j),u));					
				}
			}
		}

		naming(t);
		

		saida.open(filename.c_str());
		
		saida << n << " " << arcs.size() << endl;
		
		for(map<arc, double>::iterator it = arcs.begin(); it!=arcs.end(); it++) saida << it->first.first << " " << it->first.second << " " << it->second << endl;
		
		arcs.clear();

		saida.close();

	}


}

void generate(){

		cout<< "Digite a quantidade de vétices:" << endl;
		cin >> n;

		cout<< "Digite a probabilidade de geração de arestas:" << endl;
		cin >> p;		

		while(p>1 || p<0){
			cout<< "Probabilidade inválida! Digite um número real entre 0 e 1:" << endl;
			cin >> p;		
		}

		cout<< "Digite o valor máximo para o intervalo de variação dos pesos das arestas:" << endl;
		cin >> range;

		cout<< "Deseja uma variação de pesos discreta ou continua?" << endl;
		cout << "0 = Discreta." << endl;
		cout << "1 = Continua." << endl;
		cin >> interval;
		
		cout<< "Quantas instâncias com essa configuração voce deseja?:" << endl;
		cin >> qtde;

		srand(time(0));

		if(interval==0){
			discrete();
		}
		else{
			continous();
		}

}

void naming(int t){

	stringstream a;
	a << n;
	str1 = a.str();

	stringstream b;
	b << p;
	str2 = b.str();
	
	stringstream c;
	c << t;
	str3 = c.str();

	filename  = "graph-" + str1 + "-" + str2 + "(" + str3 + ").txt" ;
}

int main()
{
	cout << "--==Gerador de grafo simples==--" <<endl;
	cout << endl;
	do{
		generate();

		cout << "Deseja criar mais instancias com outras configuraões?" << endl;
		cout << "1 = Sim." << endl;
		cout << "0 = Fechar programa." << endl;
		cin >> again;

	}while(again == 1);	
	
    return 0;
}
