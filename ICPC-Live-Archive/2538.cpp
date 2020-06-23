#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main () {

	int n;
	cin >> n;
	
	while(n!=0) {
	
		char aux;
		string p;
		string::iterator it;
		int left = 0;

		cin >> p;

		for (int i=0; i<p.size(); i++) {
			it = find(p.begin(),p.begin()+i,p[i]);
			if (it==p.begin()+i) {
				if (n==0) {
					p[i] = '0';
					left++;
				}
				else n--;
			}
			else n++;
		}

		if (left==0)
			cout << "All customers tanned successfully." << endl;
		else cout << left/2 << " customer(s) walked away." << endl;

		cin >> n;
	}

	return 0;
}