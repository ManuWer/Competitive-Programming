#include <iostream>
using namespace std;

struct SorL {
	int x; 	//inicio
	int y; 	//fim
};

int main () {

	int t;

	cin >> t;

	while (t>0) {
		int n, b, c;
		bool win = false;

		cin >> n >> b >> c;
		
		SorL v[b];
		int player[n];
		int die[c];
		int controle = 0;		//variavel de controle para acessar a posicao do jogador que esta jogando naquela rodada

		for (int i=0; i<b; i++)
			cin >> v[i].x >> v[i].y;

		for (int i=0; i<n; i++)
			player[i] = 1;

		int i;
		bool atalho;					//variavel que garante que o jogador ainda nao usou um atalho

		for (i=0; i<c; i++) {
			if (controle==n)
				controle = 0;
			cin >> die[i];
			player[controle]+=die[i];
			if (player[controle]>100) player[controle]=100;
			atalho = false;
			for (int j=0; j<b; j++) {
				if (player[controle] == v[j].x && !atalho) {
					player[controle] = v[j].y;
					atalho = true;
				}
			}
			if (player[controle] == 100) {
				win = true;
				break;
			}
			controle++;
		}

		for (int j=0; j<n; j++)
			cout << "Position of player " << j+1 << " is " << player[j] << "." << endl;

		if (win) {
			while (i<c-1) {
				cin >> die[i];
				i++;
			}
		}

		t--;
	}

	return 0;
}

	
	