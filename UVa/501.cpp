#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
	 	
	int t, n, m;
	cin >> t;

	while (t>0) {
		cin >> m >> n;
		vector<int> A(m);
		vector<int> u(n);
		multiset<int> Aset;
		multiset<int>::iterator it;
		int i = 0;

		for (int j=0;j<m;j++)
			cin >> A[j];

		cin >> u[0];
		for (int k=0;k<u[0];k++)
				Aset.insert(A[k]);
		it = Aset.begin();
		cout << *it << endl;

		for (int j=1;j<n;j++) {
			cin >> u[j];
			for (int k=Aset.size();k<u[j];k++) {
				Aset.insert(A[k]);
				if (A[k]<(*it)) it--;
			}
			it++;
			cout << *it << endl;
		}

		t--;
		if (t>0) cout << endl;
	}

	return 0;
}