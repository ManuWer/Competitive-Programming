#include <iostream>
using namespace std;

int main() {

	int n;
	cin >> n;
	int a, b;

	cin >> a >> b;
	int maior = b;
	int num = b;
	
	for(int i=1;i<n;i++) {
		cin >> a >> b;
		num -= a;
		num += b;
		if (num > maior) maior = num;
	}

	cout << maior << endl;			

	return 0;
}