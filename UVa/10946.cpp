#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool cmp(pair <char,int> p, pair <char,int> p1) {
	return p.second > p1.second;
}

int DFS(vector< vector<char> > &G, int l, int c, vector <vector<bool> > &visit, char c1) {		
   	if(visit[l][c]) return 0;
	if(G[l][c]!=c1) return 0;
	visit[l][c] = true;
			  						   
	return 1 + DFS(G,l,c-1,visit,c1) +
			   DFS(G,l-1,c,visit,c1) +
			   DFS(G,l+1,c,visit,c1) +
			   DFS(G,l,c+1,visit,c1);
}

int main() {
	int n,m;
	string s;
	int k = 1;

	while(cin >> n >> m && (n!=0 || m!=0)) {
		vector< vector<char> > grid(n+2, vector<char>(m+2));
		vector< vector<bool> > visit(n+2, vector<bool>(m+2,0));

		for(int i=0;i<m+2;i++) {
			grid[0][i] = '*';
			grid[n+1][i] = '*';
		}

		for(int i=0;i<n+2;i++) {
			grid[i][0] = '*';
			grid[i][m+1]  = '*';
		}

		for(int i=0;i<n;i++) {
			cin >> s;
			for(int j=0;j<m;j++)
				grid[i+1][j+1] = s[j];
		}

		char c1;
		int area;
		vector< pair<char,int> > map;

		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				if(grid[i][j]!='.' && !visit[i][j]) {
					c1 = grid[i][j];
					area = DFS(grid,i,j,visit,c1);
					map.push_back(make_pair(c1,area));
				}
			}
		}
			
		sort(map.begin(),map.end());
		stable_sort(map.begin(),map.end(),cmp);
		
		cout << "Problem " << k << ":\n";
		for(int i=0;i<map.size();i++)
			cout << map[i].first << " " << map[i].second << endl;
		k++;
	}
	
	return 0;
}