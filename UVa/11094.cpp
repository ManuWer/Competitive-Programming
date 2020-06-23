#include<iostream>
#include<vector>
using namespace std;

int DFS(vector< vector<char> > &G, int l, int c, vector <vector<bool> > &visit, char c1) {		
    if(visit[l][c]) return 0;
    visit[l][c] = true;
	if(G[l][c]!=c1) return 0;
	
	if(c==0) return 1 + DFS(G,l,G[l].size()-1,visit,c1) +
			   			DFS(G,l-1,c,visit,c1) +
			   			DFS(G,l+1,c,visit,c1) +
			   			DFS(G,l,c+1,visit,c1);
			   			
	if(c==G[l].size()-1) return 1 + DFS(G,l,c-1,visit,c1) +
			  						   DFS(G,l-1,c,visit,c1) +
			   						   DFS(G,l+1,c,visit,c1) +
			  						   DFS(G,l,0,visit,c1);
			  						   
	return 1 + DFS(G,l,c-1,visit,c1) +
			   DFS(G,l-1,c,visit,c1) +
			   DFS(G,l+1,c,visit,c1) +
			   DFS(G,l,c+1,visit,c1);
}

int main() {
	int n,m,x,y;
	string s;
	
	while(cin >> n >> m) {
		vector< vector<char> > grid(n+2, vector<char>(m));
		vector< vector<bool> > visit(n+2, vector<bool>(m,0));

		for(int i=0;i<m+2;i++) {
			grid[0][i] = '.';
			grid[n+1][i] = '.';
		}

		for(int i=0;i<n;i++) {
			cin >> s;
			for(int j=0;j<m;j++)
				grid[i+1][j] = s[j];
		}

		cin >> x >> y;
		char c1 = grid[x+1][y];
		
		DFS(grid,x+1,y,visit,c1);
		int area,max=0;
		
		for(int i=1;i<=n;i++) {
			for(int j=0;j<m;j++) {
				if(grid[i][j]==c1 && !visit[i][j]) {
					area = DFS(grid,i,j,visit,c1);
					if(area>max) max = area;
				}
			}
		}

		cout << max << endl;
	}
	
	return 0;
}