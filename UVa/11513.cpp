#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

// mapeia uma string de estado do jogo em uma sequencia de
// movimentos de como chegar neste estado
unordered_map<string,string> m;

// os movimentos verticais sao feitos para baixo...
string V1(const string &p) {
    string s(p);
    int s0 = s[0], s3 = s[3];
    s[0] = s[6];
    s[3] = s0;
    s[6] = s3;
    return s;
}

string V2(const string &p) {
    string s(p);
    int s1 = s[1], s4 = s[4];
    s[1] = s[7];
    s[4] = s1;
    s[7] = s4;
    return s;
}

string V3(const string &p) {
    string s(p);
    int s2 = s[2], s5 = s[5];
    s[2] = s[8];
    s[5] = s2;
    s[8] = s5;
    return s;
}

// os movimentos horizontais sao feitos para a esquerda...
string H1(const string &p) {
    string s(p);
    int s0 = s[0], s1 = s[1];
    s[0] = s1;
    s[1] = s[2];
    s[2] = s0;
    return s;
}

string H2(const string &p) {
    string s(p);
    int s3 = s[3], s4 = s[4];
    s[3] = s4;
    s[4] = s[5];
    s[5] = s3;
    return s;
}

string H3(const string &p) {
    string s(p);
    int s6 = s[6], s7 = s[7];
    s[6] = s7;
    s[7] = s[8];
    s[8] = s6;
    return s;
}

// coloca no mapa todos os estados que sao possiveis de alcancar a partir
// do estado consistente do jogo, fazendo os movimentos contrarios
void criaMapa() {
    queue<pair<string,string> > F;
    F.push({"123456789",""});
    string s, p;
    while(!F.empty()) {
        s = F.front().first; p = F.front().second; F.pop();   
        auto it = m.find(s);
        if(it==m.end()) { 
            m[s] = p;
            F.push({H1(s),p+"1H"});
            F.push({H2(s),p+"2H"});
            F.push({H3(s),p+"3H"});
            F.push({V1(s),p+"1V"});
            F.push({V2(s),p+"2V"});
            F.push({V3(s),p+"3V"});
        }
    }
}

int main() {
    
    string s, puzzle;
    criaMapa();   
    
    while(1) {
        for(int i=0;i<3;i++) {
            getline(cin,s);
            if(s[0]=='0') return 0;
            puzzle += s[0]; puzzle += s[2]; puzzle += s[4];
        }

        // se o estado de entrada nao esta no mapa, nao tem solucao
        if(m.find(puzzle)==m.end()) cout << "Not solvable\n";
        // se estiver, imprime o numero de movimentos e a ordem ao contrario
        else {
            s = m[puzzle];
            reverse(s.begin(),s.end());
            cout << s.size()/2 << " " << s << endl;
        }
        
        puzzle.clear();
        s.clear();
    }

    return 0;
}