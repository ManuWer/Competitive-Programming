#include <iostream>
using namespace std;

void printTour(int G[][50], int v) {
	for(int i=0;i<50;i++) {
		if(G[v][i]) {
			G[v][i]--;
			G[i][v]--;
			printTour(G,i);
			cout << i+1 << " " << v+1 << endl;
		}
	}
}

int main() {

	int t, k=1;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		int adj[50][50] = {0};
		int grau[50] = {0};

		int a, b;

		for(int i=0;i<n;i++) {
			cin >> a >> b;
			adj[a-1][b-1]++; adj[b-1][a-1]++;
			grau[a-1]++; grau[b-1]++;
		}

		bool euler = 1;
		for(int i=0;i<50;i++)
			if(grau[i]%2!=0) euler = 0;

		cout << "Case #" << k << endl; k++;

		if(!euler) cout << "some beads may be lost\n";
		else {
			for(int i=0;i<50;i++)
				if(grau[i]!=0) {
					printTour(adj,i);
					break;
				}
		}

		if(t>0) cout << endl;
	}
	
	return 0;
}