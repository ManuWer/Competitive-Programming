#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector< vector<int> > &G, int v, vector<bool> &visit, vector<int> &cor) {
	queue<int> F;
    F.push(v);
    visit[v] = true;
	cor[v] = 0;
    while(!F.empty()) {
    	v = F.front();
  		F.pop();
    	for(int i:G[v]) {
    		if(!visit[i]) {
				if(cor[i]==-1) cor[i] = 1-cor[v];
				F.push(i);
				visit[i] = true;
    		}
    	}
    }	
}

int main() {
	int n, m;
    int a, b;

    while(cin >> n && n!=0) {
		vector< vector<int> > G(n);
		cin >> m;
		
		for(int i=0;i<m;i++) {
		    cin >> a >> b;
		    G[a].push_back(b);
		    G[b].push_back(a);
		}

		vector<bool> visit(n,0);
		vector<int> cor(n,-1);
		bool ok = true;

		BFS(G,0,visit,cor);

		for(int i=0;i<n;i++)
			for(int j=0;j<G[i].size();j++) 
				if(cor[i]==cor[G[i][j]]) ok = false;

		if(ok) cout << "BICOLORABLE.\n";
		else cout << "NOT BICOLORABLE.\n";	
	}

	return 0;
}