#include <iostream>
using namespace std;

int main() {

	int n;
	cin >> n;

	for(int i=0;i<n;i++) {
		long long int k; cin >> k;
		bool ok = false;

		for(int i=15;i<21;i++) {
			long long int aux = k-i;
			if(aux%14==0 && aux>-1) 
				ok = true;
		}

		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}