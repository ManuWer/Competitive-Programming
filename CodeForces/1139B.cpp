#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int n;
	cin >> n;
	vector<int> v(n);

	for(int i=0;i<n;i++)
		cin >> v[i];

	long long tot = v[n-1];
	int a = v[n-1];

	for(int i=n-2;i>=0;i--) {
		a = min(v[i],a-1);
		if(a<0) break;
		tot += a;
	}

	cout << tot << endl;

	return 0;
}