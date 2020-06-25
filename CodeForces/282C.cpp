#include <iostream>
#include <string>
using namespace std;

int main() {

	string s,p;
	cin >> s >> p;

	if(s.size()!=p.size()) 
		cout << "NO\n";
	else {
		bool oneS = false, oneP = false;
			
		for(int i=0;i<s.size();i++) {
			if(s[i]=='1') oneS = true;
			if(p[i]=='1') oneP = true;
		}

		if(oneS ^ oneP) cout << "NO\n";
		else cout << "YES\n";
	}

	return 0;
}