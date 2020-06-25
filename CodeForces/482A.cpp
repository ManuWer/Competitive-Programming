#include <iostream>
using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	int init = n-k;
	int i=2, j=0;

	cout << "1";

	while(init>=i) {
		cout << " " << i;
		i++;
	}

	bool change = 0;
	for(int c=i;c<=n;c++) {
		if(!change) {
			cout << " " << n-j;
			change = 1;
			j++;
		} else {
			cout << " " << i;
			change = 0;
			i++;
		}
	}
	
	cout << endl;
	
	return 0;
}