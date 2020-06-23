#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void graphReverse(vector< vector<int> > &G, vector< vector<int> > &revG) {
	for(int i=0;i<G.size();i++)
		for(int v:G[i])
			revG[v].push_back(i);
}

void DFS(vector< vector<int> > &G, int v, vector<bool> &visit) {
    if(visit[v]) return;
    visit[v] = true;
    for(int i:G[v]) 
        (DFS(G,i,visit));
}

int main() {
    int n, m;
    int a, b, p;
    
	while(cin >> n >> m && (n!=0 || m!=0)) {
		vector< vector<int> > G(n);
		vector< vector<int> > revG(n);
		bool sc = true;

		for (int i=0;i<m;i++) {
		    cin >> a >> b >> p;
		    G[a-1].push_back(b-1);
		    if(p==2) G[b-1].push_back(a-1);
		}
   
    	vector<bool> visit(n,0);
    	DFS(G,0,visit);

		for(int i=0;i<visit.size();i++) {
			if(!visit[i]) sc = false;
			visit[i] = false;
		}

		graphReverse(G,revG);
		DFS(revG,0,visit);

		for(bool i:visit) 
			if(!i) sc = false;
		cout << sc << endl;
    }
   
    return 0;
}