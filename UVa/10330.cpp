#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

// Ford Fulkerson Algorihtm
// Author: BedirT
// https://github.com/BedirT/Algorithms_and_DS/blob/master/Algorithms/Graph/Ford%20Fulkerson.cpp

#define maxN 210

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

    int n;
    while(cin >> n) {
        int graph[maxN][maxN];
        for(int i=0;i<2*n+2;i++) 
            for(int j=0;j<2*n+2;j++)
                graph[i][j]=0;
            
        vector<int> regCapac(n);
        for(int i=0;i<n;i++) 
            cin >> regCapac[i];     // Capacidades dos reguladores

        // Vertices no grafo:
        // 0 -> fonte
        // 1...n -> reguladores A
        // n+1 -> destino
        // n+2...2n+1 -> reguladores B

        // Cada regulador i eh representado por 2 no grafo (iA,iB), e entre eles ha uma aresta com a capacidade do regulador
        // As arestas que chegam no regulador chegam em iA, e as arestas que saem dele saem de iB
        int m;
        cin >> m;
        for(int i=0;i<m;i++) {
            int a,b,c;
            cin >> a >> b >> c;
            graph[a][n+1+a] = regCapac[a-1];        
            graph[n+1+a][b] = c;
        }

        // Fonte e destino
        int b,d;
        cin >> b >> d;

        // Reguladores conectados na fonte
        for(int i=0;i<b;i++){
            int s;
            cin >> s;
            graph[0][s] = 1000000;   
            graph[s][s+n+1] = regCapac[s-1];
        }

        // Reguladores conectados no destino
        for(int i=0;i<d;i++){
            int t;
            cin >> t;
            graph[t][t+n+1] = regCapac[t-1];
            graph[t+n+1][n+1] = 1000000;
        }

        cout << fordFulkerson(graph, 2*n+2, 0, n+1) << endl;
    }
	
	return 0;
}