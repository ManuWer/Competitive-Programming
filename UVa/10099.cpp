#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n,r,t = 1;
    while(cin >> n >> r) {
        if(n==0 && r==0) return 0;

        vector< vector<int> > adj(n,vector<int>(n,0));  // Matriz de adjacencias contendo o peso das arestas
        for(int i=0;i<r;i++) {
            int a,b,c;
            cin >> a >> b >> c;
            adj[a-1][b-1] = c;
            adj[b-1][a-1] = c;
        }

        int s,d,tourist;
        cin >> s >> d >> tourist;

        // Algoritmo de floyd-warshall
        // Encontra o caminho que contem a aresta de peso minimo com o maior peso possivel
        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    adj[i][j] = max(adj[i][j], min(adj[i][k],adj[k][j]));

        int max = adj[s-1][d-1] - 1;   // O maximo de turistas que pode passar pelo melhor caminho -1 (pois o guia sempre vai junto)
        int trips = 0;

        // Incrementa o numero de viagens enquanto ainda houver turistas pra serem levados
        while(tourist>0) {
            trips++;
            tourist -= max;
        }

        cout << "Scenario #" << t++ << "\n";
        cout << "Minimum Number of Trips = " << trips << "\n\n";
    }
	
	return 0;
}