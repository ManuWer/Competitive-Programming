#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {

	int n, m;
	while(cin >> n >> m) {
		if(n==0 && m==0) return 0;
		vector<vector<int> > G(n);
		vector<int> grauEntrada(n,0);

		for(int i=0;i<m;i++) {
			int a, b;
			cin >> a >> b;
			G[a-1].push_back(b-1);
			grauEntrada[b-1]++;
		}

		queue<int> grauZero;
		for(int i=0;i<n;i++)
			if(!grauEntrada[i]) grauZero.push(i);

		while(!grauZero.empty()) {
			int v = grauZero.front(); grauZero.pop();
			cout << v+1 << " ";
			for(int i:G[v]) {
				grauEntrada[i]--;
				if(!grauEntrada[i]) grauZero.push(i);
			}
		}

		cout << endl;
	}

	return 0;
}