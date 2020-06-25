#include <iostream>
using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	int ld;
	for(int i=0;i<k;i++) {
		ld = n%10;
		if(ld!=0) n-=1;
		else n/=10;
	}		

	cout << n << endl;

	return 0;
}