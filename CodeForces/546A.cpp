#include <iostream>
using namespace std;

int main() {

	int k, n, w;
	cin >> k >> n >> w;

	int	sum = 0;

	for(int i=1;i<=w;i++)
		sum += k*i;

	if(n>=sum) cout << "0\n";
	else cout << sum-n << endl;

	return 0;
}