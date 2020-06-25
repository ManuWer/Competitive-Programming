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

	int c;

	if(v[0]!=0) {
		c = n-v[0];
		for(int i=0;i<c;i++) {
			for(int j=0;j<n;j++) {
				if(j%2==0) {
					if(v[j]==n-1) v[j] = 0;
					else v[j]++;
				}
				else {
					if(v[j]==0) v[j] = n-1;
					else v[j]--;
				}
			}
		}
	}

	bool ok = true;

	for(int i=0;i<n;i++)
		if(v[i]!=i) ok = false;

	if(!ok) cout << "No\n";
	else cout << "Yes\n";

	return 0;
}