#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

//BFS adaptada para retonar se do vertice inicial conseguimos voltar nele mesmo
bool BFS(vector< vector<int> > &G, int v, vector<bool> &visit) {
	queue<int> F;
    F.push(v);
    visit[v] = true;
    int init = v;
    bool comeBack = false;
    while(!F.empty()) {
    	v = F.front(); F.pop();
    	for(int i:G[v]) {
            if(i==init) 
                comeBack = true;
    		if(!visit[i]) {
				F.push(i);
				visit[i] = true;
    		}
    	}
    }

    return comeBack;	
}

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n,m,c;
        cin >> n >> c >> m;
        cin.ignore();

        vector< vector<int> > cat(n);
        vector< vector<int> > mouse(n);
        vector<bool> visitCat(n,0);
        vector<bool> visitMouse(n,0);

        string s;
        while(getline(cin,s)) {
            stringstream ss(s);
            int a, b;
            ss >> a; ss >> b;
            if(a==-1) break;
            cat[a-1].push_back(b-1);
        }

        while(getline(cin,s)) {
            if(s.empty()) break;
            stringstream ss(s);
            int a, b;
            ss >> a; ss >> b;
            mouse[a-1].push_back(b-1);
        }

        BFS(cat,c-1,visitCat);
        BFS(mouse,m-1,visitMouse);

        vector< vector<int> > mouseSemCat(mouse);
        vector<bool> visitMSC(n,0);

        // Se o gato alcanca aquele quarto, "removemos" ele do novo grafo para verficar onde o rato consegue andar livremente
        for(int i=0;i<n;i++)
            if(visitCat[i]) mouseSemCat[i].clear();

        bool q1 = false, q2 = false;

        // Primeira pergunta..
        // Se houver um mesmo quarto no fecho transitivo do gato e do rato, entao eles conseguem se encontrar
        for(int i=0;i<n;i++)
            if(visitCat[i] && visitMouse[i]) {
                q1 = true;
                break;
            }

        // Segunda pergunta..
        // A BFS retorna se o rato consegue sair do quarto inicial e voltar
        q2 = BFS(mouseSemCat,m-1,visitMSC);

        if(q1) cout << "Y ";
        else cout << "N ";
        
        if(q2) cout << "Y\n";
        else cout << "N\n";

        if(t) cout << "\n";
    }

    return 0;
}
