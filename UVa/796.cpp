#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>

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
		vector< list<int> > G(n);
		int ind, grau, t;
		char c;
		
		for(int i=0;i<n;i++) {
			cin >> ind >> c >> grau >> c;
			for(int j=0;j<grau;j++) {
				cin >> t;
				G[ind].push_back(t);
			}
		}

		vector< list<int> > aux(G);
		vector< pair<int,int> > bridges;

		for(int v=0;v<n;v++) {
			for(int w:G[v]) {
				if(w<v) continue;
				vector<bool> visit(n,0);
				aux[v].remove(w);
				DFS(aux,v,visit);
				if(!visit[w]) bridges.push_back(make_pair(v,w));
				aux[v].push_back(w);
			}
		}

		sort(bridges.begin(),bridges.end());

		cout << bridges.size() << " critical links\n";
		for(auto b:bridges)
			cout << b.first << " - " << b.second << endl;
		cout << endl;
	}
	
	return 0;
}