#include <iostream>
#include <vector>
#include <array>

using namespace std;

// Algoritmo de Bellmand-Ford para detectar ciclos negativos
// Se houver ciclo negativo, a funcao retorna true
bool bellmanFord(const vector< array<int,3> > &edges, vector<int> &pai, vector<int> &custo, int nv, int e) {
    custo[0] = 0;
    pai[0] = 0;

    for(int i=0;i<nv-1;i++) {
        for(int j=0;j<e;j++) {
            int u = edges[j][0], v = edges[j][1], dist = edges[j][2];
            if(custo[u] + dist < custo[v]) {
                custo[v] = custo[u] + dist;
                pai[v] = u;
            }
        }
    }

    for(int j=0;j<e;j++) {
        int u = edges[j][0], v = edges[j][1], dist = edges[j][2];
        if(custo[u] + dist < custo[v]) return true;
    }

    // Retorna falso se nao ha ciclo negativo
    return false;
}

int main() {

    int t;
    cin >> t;

    while(t--) {
        int v,e;
        cin >> v >> e;

        vector< array<int,3> > edges(e);       // Lista de arestas na forma (u,v,peso)
        for(int i=0;i<e;i++) {
            int a,b,c;
            cin >> a >> b >> c;
            edges[i][0] = a;
            edges[i][1] = b;
            edges[i][2] = c;
        }

        vector<int> pai(v,-1);
        vector<int> custo(v,10000000);

        if(bellmanFord(edges,pai,custo,v,e)) cout << "possible\n";
        else cout << "not possible\n";
    }

    return 0;
}
