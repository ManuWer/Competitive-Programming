#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	
	int n;
	cin >> n;

	for(int i=0;i<n;i++) {
		string s;
		cin >> s;
		bool ok = false;
		do {
			string st = s;
			reverse(st.begin(),st.end());
			if(s.compare(st)!=0) {
				cout << s << endl;
				ok = true;
				break;
			}
		} while (next_permutation(s.begin(),s.end()));

		if(!ok) cout << "-1\n";
	}

	return 0;
}