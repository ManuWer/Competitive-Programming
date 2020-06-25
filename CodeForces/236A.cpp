#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
		
	string s;
	cin >> s;
	
	set<char> a;
	int c = 0;

	for(int i=0;i<s.size();i++) {
		auto it = a.find(s[i]);
		if(it==a.end()) {
			c++;
			a.insert(s[i]);
		}
	}

	if(c%2==0) cout << "CHAT WITH HER!\n";
	else cout << "IGNORE HIM!\n";

	return 0;
}