#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

void DFS(vector< list<int> > &G, int v, vector<bool> &visit) {
	if(visit[v]) return;
	visit[v] = true;
	for(int i:G[v])
		DFS(G,i,visit);
}

int main() {

	int n;
	while(cin >> n) {
		if(n==0) break;
		vector< list<int> > G(n);
		int v,w;
		string s;
		cin.ignore();
		while(getline(cin,s)) {
			stringstream ss(s);
			ss >> v;
			if(v==0) break;
			for(int i=1;i<s.size()/2+1;i++) {
				ss >> w;
				G[v-1].push_back(w-1);
				G[w-1].push_back(v-1);
			}
		}
	
		vector< list<int> > aux(G);
		int critical = 0;	

		for(int v=0;v<n;v++) {
			vector<bool> visit(n,0);
			visit[v] = 1;
			int a = (v==0)?1:0;
			aux[v].clear();
			DFS(aux,a,visit);
			for(int i=0;i<n;i++)
				if(!visit[i]) {
					critical++;
					break;
				}
			aux[v] = G[v];
		}

		cout << critical << endl;		
	}

	return 0;
}