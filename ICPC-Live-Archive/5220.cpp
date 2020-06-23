#include <iostream>
#include <cstring>
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
    
    int n, t=1;

    while(cin >> n) {
        if(n==0) return 0;
        
        int graph[maxN][maxN];
		for(int i=0;i<n;i++) 
            for(int j=0;j<n;j++)
                graph[i][j]=0;

        int s,d,c;
        cin >> s >> d >> c;

        for(int i=0;i<c;i++) {
            int a,b,band;
            cin >> a >> b >> band;
            graph[a-1][b-1] += band;	// Somamos o fluxo porque pode ter arestas multiplas
            graph[b-1][a-1] += band;
        }

        cout << "Network " << t++ << "\nThe bandwidth is " << fordFulkerson(graph,n,s-1,d-1) << ".\n\n";;
    }

   return 0;
}