#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	double n, p, q;
	cin >> n >> p >> q;

	double d = (n*p)/(p+q);

	cout << d << endl; 

	return 0;
}