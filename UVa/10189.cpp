#include <iostream>
using namespace std;

int main () {

	int n, m;			//n linhas e m colunas
	int field = 0;
	
	cin >> n >> m;

	while (n!=0 || m!=0) {
		if (field!=0) cout << endl;
		field++;

		char in[n+2][m+2];
		char game[n+2][m+2];
		int cont = 0;

		for (int i=0; i<n+2; i++)
			for (int j=0; j<m+2; j++)
				game[i][j] = '.';
		
		for (int i=1; i<n+1; i++) 
			for (int j=1; j<m+1; j++)
				cin >> game[i][j];

		for (int i=1; i<n+1; i++) {
			for (int j=1; j<m+1; j++) {
				cont = 0;
				if (game[i][j] != '*') {
			
					if (game[i-1][j-1] == '*')
						cont++;
					if (game[i-1][j] == '*')
						cont++;
					if (game[i-1][j+1] == '*')
						cont++;
					if (game[i][j-1] == '*')
						cont++;
					if (game[i][j+1] == '*')
						cont++;
					if (game[i+1][j-1] == '*')
						cont++;
					if (game[i+1][j] == '*')
						cont++;
					if (game[i+1][j+1] == '*')
						cont++;

					if (cont==0) game[i][j] = '0';
					if (cont==1) game[i][j] = '1';
					if (cont==2) game[i][j] = '2';
					if (cont==3) game[i][j] = '3';
					if (cont==4) game[i][j] = '4';
					if (cont==5) game[i][j] = '5';
					if (cont==6) game[i][j] = '6';
					if (cont==7) game[i][j] = '7';
					if (cont==8) game[i][j] = '8';
				}
			}
		}

		cout << "Field #" << field << ":";

		for (int i=1; i<n+1; i++) {
			cout << endl;
			for (int j=1; j<m+1; j++)
				cout << game[i][j];
		}
		
		cout << endl;
		
		cin >> n >> m;

	}

	return 0;
}

		
	