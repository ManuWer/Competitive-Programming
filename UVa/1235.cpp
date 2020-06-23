#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

typedef pair<int,int> PII;

int prim(const vector< vector<PII> > &adj, vector<bool> &visit, int v) {
    priority_queue<PII, vector<PII>, greater<PII> > F;
    int ans = 0;
    PII p;
    F.push(make_pair(0,v));
    while(!F.empty()) {
        // Seleciona e tira da fila a aresta de peso minimo
        p = F.top(); F.pop();
        v = p.second;
        // Se ainda nao alcancamos o vertice v...
        if(!visit[v]) {
            ans += p.first;
            visit[v] = true;
            for(PII pair:adj[v]) {
                int w = pair.second;
                if(!visit[w]) F.push(pair);
            }
        }
    }

    return ans;
}

// Calcula a "distancia" entre duas chaves de 4 digitos 
int rolls(const string &s, const string &p) {
    int rolls = 0;
    for(int i=0;i<4;i++) {
        int a = s[i]-'0';
        int b = p[i]-'0';
        if((abs(a-b))>5) rolls += 10-(abs(a-b));
        else rolls += abs(a-b);
    }
    return rolls;
}

int main() {
	int t;
	cin >> t;

	while(t--) {
		int n;
		cin >> n; cin.ignore();
        vector<string> locks(n);
        vector< vector<PII> > adj(n);   // Armazena pra cada vertice uma lista que contem pares (vizinho,distancia)
        vector<bool> visit(n,0);
        int min = 20; 

		for(int i=0;i<n;i++) 
            cin >> locks[i];

		for(int i=0;i<n;i++) {
            int s = rolls(locks[i],"0000");
            if(s<min) min = s;       // Guarda a chave mais perto da inicial, e soma essa constante no custo depois
			for(int j=i+1;j<n;j++) {
                int p = rolls(locks[i],locks[j]);
                adj[i].push_back(make_pair(p,j));
				adj[j].push_back(make_pair(p,i));
            }
        }

        cout << prim(adj,visit,0) + min << endl;
	}

	return 0;
}