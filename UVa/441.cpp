#include <iostream>
#include <algorithm>
using namespace std;

int vec[13];
int aux[6];
int n;

void fun(int i, int j) {
	if(i==6) {
		for(int k=0; k<5; k++) cout << aux[k] << " ";
		cout << aux[5] << endl;
	} else {
		for (int k = j; k <= n - (6 - i); k++) {
            aux[i] = vec[k];
            fun(i + 1, k + 1);
        }
	}
}

int main () {
	cin >> n;
	bool notFirst = false;
	
	while (n!=0) {
		if(notFirst)
			cout << endl;
		notFirst = true;
		for(int i=0; i<n; i++) cin >> vec[i];
		sort(vec,vec+n);
		fun(0, 0);
		cin >> n;
		
	}
	
	return 0;
}