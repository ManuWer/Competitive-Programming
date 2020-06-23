#include <iostream>
#include <cstring>
#include <map>
using namespace std;

// Ford Fulkerson Algorihtm
// Author: BedirT
// https://github.com/BedirT/Algorithms_and_DS/blob/master/Algorithms/Graph/Ford%20Fulkerson.cpp

#define maxN 100

// DFS version that returns true if there's a path from source to sink
bool DFS(int rGraph[maxN][maxN], int *parent, bool *visited, int n, int x, int t){
	if(x==t) return true;
	visited[x] = true;

	for(int i=0;i<n;i++) {
		if(rGraph[x][i]>0 && !visited[i]) {
			parent[i] = x;
			if(DFS(rGraph, parent, visited, n, i, t)) 
                return true;
		}
	}

	return false;
}

int fordFulkerson(int graph[maxN][maxN], int n, int s, int t) {
	int rGraph[maxN][maxN];
	int parent[maxN];
	bool visited[maxN];

	// Replicate the graph for residual one
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			rGraph[i][j] = graph[i][j];

	for(int i=0;i<n;i++)
		visited[i] = false;

	int max_flow = 0;

	while(DFS(rGraph, parent, visited, n, s, t)) { 
		memset(visited, false, sizeof(visited));
		int path_flow = 0xfffffff; // Current flow to add on the max flow later
         
		for(int v=t;v!=s;v=parent[v]){
			int u = parent[v];
			path_flow = min(path_flow, rGraph[u][v]);
		}

		for(int v=t;v!=s;v=parent[v]){
			int u = parent[v];
			rGraph[u][v] -= path_flow;
			rGraph[v][u] += path_flow;
		}

		max_flow += path_flow;
	}

	return max_flow;
}

int main() {

	// Mapeia cada tamanho de camisa em um vertice
	map<string,int> size;
	size["XS"] = 1;
	size["S"] = 2;
	size["M"] = 3;
	size["L"] = 4;
	size["XL"] = 5;
	size["XXL"] = 6;

	int t;
	cin >> t;

	while(t--) {

		int n, m;
		cin >> n >> m;
		cin.ignore();

		int k = n/6;

		// Tamanho do grafo: 1 fonte + 6 camisas + m pessoas + 1 sorvedouro = m+8
		int graph[maxN][maxN];
		for(int i=0;i<m+8;i++) 
            for(int j=0;j<m+8;j++)
                graph[i][j]=0;

		// O vertice 0 recebe fluxo de todos os tamanhos de camisa
		// O fluxo deve "escoar" ate ele
		graph[1][0] = graph[2][0] = graph[3][0] = graph[4][0] = graph[5][0] = graph[6][0] = k;

		for(int i=0;i<m;i++) {
			string s, p;
			cin >> s >> p;
			graph[m+7][i+7] = 1;      // O último vértice do grafo envia fluxo para as pessoas
			graph[i+7][size[s]] = 1;	// Cada pessoa so pode ser ligada a uma camisa 
			graph[i+7][size[p]] = 1;
		}

		int max = fordFulkerson(graph,m+8,m+7,0);

		// Se o fluxo maximo for igual a quantidade de pessoas...
		if(max==m) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}