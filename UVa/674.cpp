#include <iostream>
using namespace std;

int v[5] = {1,5,10,25,50};

int troco(int n, int tab[]) {
	for(int i=0;i<5;i++)
		for(int j=v[i];j<7500;j++)
			tab[j]+=tab[j-v[i]];
	return tab[n];
}
	
int main() {
	int n;
	while(cin >> n) {
		int tab[7500] = {1};
		cout << troco(n,tab) << endl;
	}
	return 0;
}