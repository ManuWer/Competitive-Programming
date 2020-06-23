#include <iostream>
using namespace std;

int main () {
	
	int n;
	int peak;
	cin >> n;

	while (n!=0) {

		peak = 0;	
		int value[n];
		for (int i=0; i<n; i++)
			cin >> value[i];
		
		for (int i=0; i<n; i++) {
			if (i==0) {
				if ( (value[n-1]>value[i] && value[i+1]>value[i]) || (value[n-1]<value[i] && value[i+1]<value[i]) )
				peak++;
			}
			else if (i==n-1) {
				if ( (value[i-1]>value[i] && value[0]>value[i]) || (value[i-1]<value[i] && value[0]<value[i]) )
				peak++;
			}
			else {
			if ( (value[i-1]>value[i] && value[i+1]>value[i]) || (value[i-1]<value[i] && value[i+1]<value[i]) )
				peak++;
			}
		}

		cout << peak << endl;

		cin >> n;
	}

	return 0;
}