#include <iostream>
#include <cmath>
using namespace std;

int main () {

	int n;

	cin >> n;
	
	while (n!=0){

		int m[n];
		int j[n];

		int odd = 0;
		int even = 0;

		for (int i=0; i<n; i++) {
			cin >> m[i];
			if (m[i]%2==0) 
				even++;
		}
		
		for (int i=0; i<n; i++) {
			cin >> j[i];
			if (j[i]%2!=0)
				odd++;
		}
		
		cout << abs(even-odd) << endl;
	
		cin >> n;
	}

	return 0;
}