#include <iostream>
using namespace std;

#define infinito 10E8

int grafo[100][100];
int dist[100];

//Código do algoritmo retirado da apostila
bool dijkstra(int n, int origem, int destino, bool visit[], int time[]) {
	for(int i=0;i<n;i++)
		dist[i]=infinito;

	dist[origem]=0;
	int atual;

	while(!visit[destino]) {
		int menor=infinito,menori;	
		for(int i=0;i<n;i++) {
			if(dist[i]>=time[i]) {
				dist[i] = infinito;
			}
			if(!visit[i] && dist[i]<menor) {
				menor=dist[i];
				menori=i;
			}
		}

		if(menor==infinito) return 0;
		atual=menori;
		visit[menori]=true;

		for(int i=0;i<n;i++) {
			if(dist[atual]+grafo[atual][i] < dist[i])
				dist[i]=dist[atual]+grafo[atual][i];
		}
	}

	return 1;
}

int main() {

	int n,m,s,t;
	cin >> n >> m >> s >> t;

	while(n!=0 || m!=0 || s!=0 || t!=0) {
		int time[n];
		bool visit[n] = {0};
		int x,y,d;

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				grafo[i][j]=infinito;

		for(int i=0;i<n;i++) {
			cin >> time[i];
			if(time[i]==0) time[i]=infinito;
		}
	
		for(int i=0;i<m;i++) {
			cin >> x >> y >> d;
			x--;
			y--;
			grafo[x][y]=grafo[y][x]=d;
		}

		bool ok = dijkstra(n,s-1,t-1,visit,time);
		if(ok) cout << dist[t-1] << endl;
		else cout << 0 << endl;
		cin >> n >> m >> s >> t;
	}
	
	return 0;
}