#include <iostream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

int main() {

	map<string,double> tree;
	string aux;
	int c;
	cin >> c;

	//le as duas primeiras linhas em branco e ignora
	getline(cin,aux);
	getline(cin,aux);

	while (c>0) {
		tree.clear();
		int cont = 0;

		while (getline(cin,aux) && !aux.empty()) {
			cont++;
			pair<map<string,double>::iterator,bool> it;
			it = tree.insert (pair<string,double> (aux,1));
			//se insert retorna falso o elemento ja esta no map
			if (!it.second)
				it.first->second++;
		}

		for (map<string,double>::iterator i = tree.begin();i!=tree.end();i++) {
			double a = i->second*100.0/cont;	
			i->second = a;
		}

		for (map<string,double>::iterator i = tree.begin();i!=tree.end();i++)
			cout << i->first << " " << fixed << setprecision(4) << i->second << endl;
		
		c--;
		if (c>0) cout << endl;
	}

	return 0;
}