#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int DFS(vector< vector<char> > &G, int l, int c, vector <vector<bool> > &visit) {		
    if(visit[l][c]) return 0;
    visit[l][c] = true;
	if(G[l][c]!='W') return 0;

	return 1 + DFS(G,l-1,c-1,visit) +
			   DFS(G,l,c-1,visit) +
			   DFS(G,l+1,c-1,visit) +
			   DFS(G,l-1,c,visit) +
			   DFS(G,l+1,c,visit) +
			   DFS(G,l-1,c+1,visit) +
			   DFS(G,l,c+1,visit) +
			   DFS(G,l+1,c+1,visit);
}

int main() {
	int t;
	string s;
	cin >> t;
	cin.ignore();
	getline(cin,s); 	//blank line

	while(t>0) {

		int l,c;
		vector< vector<char> > grid;
		getline(cin,s);
		vector<char> v(s.size()+2,'.');    //contorno da matriz para nao acessar pos invalida
		grid.push_back(v);

		do {
			if(isdigit(s[0])) break;
			vector<char> aux;
			aux.push_back('.');
			for(int i=0;i<s.size();i++)
				aux.push_back(s[i]);
			aux.push_back('.');
			grid.push_back(aux);
		} while(getline(cin,s));

		grid.push_back(v);
	
		do {
			stringstream ss(s);
			ss >> l;
			ss >> c;
			vector< vector<bool> > visit(grid.size(), vector<bool>(grid[0].size(),0));
			cout << DFS(grid,l,c,visit) << endl;
		} while(getline(cin,s) && !s.empty());
	
		if(t>1) cout << endl;
		t--;
		
	}
		
	return 0;
}