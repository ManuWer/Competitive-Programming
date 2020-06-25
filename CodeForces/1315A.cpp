#include <iostream>
using namespace std;

int main() {

	int t;
	cin >> t;

	while(t--) {
		int a,b,x,y;
		cin >> a >> b >> x >> y;
	
		int i = a - (max(x,a-1-x));
		int j = b - (max(y,b-1-y));

		i *= b; j *= a;

		cout << a*b - min(i,j) << endl;
	}

	return 0;
}