#include <iostream>
#include <cmath>
using namespace std;

int main () {

	int n;
	
	while (cin >> n) {
	
		int v[n];
		bool values[n-1] = {false};
		bool jolly = true;
		int cont;

		for (int i=0; i<n; i++)
			cin >> v[i];

		for (int i=0; i<n-1; i++) {
			cont = abs (v[i]-v[i+1]);
			if (cont>0 && cont<n)
				values[cont-1] = true;
		}

		for (int i=0; i<n-1; i++)
			if (!values[i]) jolly = false; 
		
		if (n==1 || jolly)
			cout << "Jolly" << endl;
		else cout << "Not jolly" << endl;
	}

	return 0;
}