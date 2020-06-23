#include <iostream>
#include <iomanip>
using namespace std;

int v[11] = {1,2,4,10,20,40,100,200,400,1000,2000};

long long int troco(int n, long long int tab[]) {
	for(int i=0;i<11;i++)
		for(int j=v[i];j<30000;j++)
			tab[j]+=tab[j-v[i]];
	return tab[n];
}
	
int main() {
	double n;

	while(cin >> n && n!=0.00) {
		long long int tab[30000] = {1};
		cout << setw(6) << setfill(' ') << fixed << setprecision(2) << n;
		cout << setw(17) << setfill(' ') << troco(n*20.0+0.5,tab) << endl;
	}

	return 0;
}