#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	int n;
	cin >> n;
	vector<int> v;
	vector<int> b;

	for(int i=0;i<n;i++) {
		int k; cin >> k;
		if(k>500000)
			b.push_back(k);
		else v.push_back(k);
	}

	int t1 = 0;
	int t2 = 0;

	if(!v.empty()) {
		auto maior = max_element(v.begin(),v.end());
		t1 = *maior - 1;
	}

	if(!b.empty()) {
		auto menor = min_element(b.begin(),b.end());
		t2 = 1000000 - *menor;
	}

	cout << max(t1,t2) << endl;

	return 0;
}
