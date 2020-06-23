#include <iostream>
using namespace std;

int main () {

	int n;
	int c, k;

	cin >> n >> c >> k;

	while (n!=0 || c!=0 || k!=0) {

		int game[n][c];
		int prob[k] = {0};

		for (int i=0; i<n; i++) {
			for (int j=0; j<c; j++) {
				cin >> game[i][j];
				prob[(game[i][j] - 1)]++;
			}
		}

		int menor = n*c;
		int pos = 0;

		for (int i=0; i<k; i++)
			if (prob[i]<menor) {
				menor = prob[i];
				pos = i;
			}

		//Agora que sabemos qual a menor quantidade x que um ou mais numeros aparecerem podemos imprimir todos que aparecem x vezes
		
		cout << pos+1;
		
		for (int i=pos+1; i<k; i++) {
			if (prob[i]==menor)
				cout << " " << i+1;
		}
		
		cout << endl;
		cin >> n >> c >> k;
	}

	return 0;
}
	
		
	
	
			
	