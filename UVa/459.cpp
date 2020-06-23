#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

void DFS(vector< set<int> > &G, int v, vector<bool> &visit) {
    if(visit[v]) return;
    visit[v] = true;
    for(int i:G[v]) 
        (DFS(G,i,visit));
}

int main() {
	int t;
	char c;
	string s;
	map<char,int> p;

    p['A'] = 1;
    p['B'] = 2;
    p['C'] = 3;
    p['D'] = 4;
    p['E'] = 5;
    p['F'] = 6;
    p['G'] = 7;
    p['H'] = 8;
    p['I'] = 9;
    p['J'] = 10;
    p['K'] = 11;
    p['L'] = 12;
    p['M'] = 13;
    p['N'] = 14;
    p['O'] = 15;
    p['P'] = 16;
    p['Q'] = 17;
    p['R'] = 18;
    p['S'] = 19;
    p['T'] = 20;
    p['U'] = 21;
    p['V'] = 22;
    p['W'] = 23;
    p['X'] = 24;
    p['Y'] = 25;
    p['Z'] = 26;
	
	cin >> t;

	while(t>0) {
		cin >> c;
		cin.ignore();
		vector< set<int> > G(p[c]);
		vector<bool> visit(p[c],0);

		while(getline(cin,s) && !s.empty()) { 
		    G[p[s[0]]-1].insert(p[s[1]]-1);
		    G[p[s[1]]-1].insert(p[s[0]]-1);
		}

		DFS(G,0,visit);
		int max = 1;
		bool all = 0;
	 
		while(!all) {
			all = 1;	
			for(int i=0;i<visit.size();i++) {
				if(!visit[i]) {
					all = 0;
					DFS(G,i,visit);
					max++;
					break;
				}
			}
		}

		cout << max << endl;
		if(t>1) cout << endl;
		t--;
	}

    return 0;
}