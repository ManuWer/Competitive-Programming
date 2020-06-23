#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool sortbySec(const pair<int,int> &a, const pair<int,int> &b) { 
    return (a.second > b.second); 
} 

int DFS(vector< vector<char> > &G, int l, int c, vector <vector<bool> > &visit, char x) {		
    	if(visit[l][c]) return 0;
	if(G[l][c]!=x) return 0;
    	visit[l][c] = true;

	return 1 + DFS(G,l,c+1,visit,x) +
			   DFS(G,l,c-1,visit,x) +
			   DFS(G,l+1,c,visit,x) +
			   DFS(G,l-1,c,visit,x);
}

int main() {
	
	int t, k=1;
	cin >> t;

	while(t>0) {
		int n, m;
		cin >> n >> m;
		cin.ignore();
		map<char,int> temp;
		map<char,int>::iterator it;
		vector< vector<char> > graph(n+2, vector<char> (m+2,'.'));
		vector< vector<bool> > visit(n+2, vector<bool>(m+2,0));

		for(int i=1;i<n+1;i++)
			for(int j=1;j<m+1;j++)
				cin >> graph[i][j];
		
		int l, p=0;
		for(int i=1;i<n+1;i++) {
			for(int j=1;j<m+1;j++) {
				if(!visit[i][j]) { 
					char x = graph[i][j];
					l = DFS(graph,i,j,visit,x);
					it = temp.find(x);
					if(it!=temp.end()) (it->second)++;
					else temp[x] = 1;
				}
			}
		}
		
		vector< pair<char,int> > lang;
		for(auto i = temp.begin();i!=temp.end();i++)
    			lang.push_back(*i);
	
		stable_sort(lang.begin(), lang.end(), sortbySec);

		cout << "World #" << k << endl;
		for(int i=0;i<lang.size();i++)
			cout << lang[i].first << ": " << lang[i].second << endl;

		k++;
		t--;
	}

	return 0;
}