#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;
	cin.ignore();

	while(t>0) {
		set<char> v;
		int nodes = 0, edges = 0, acorn = 0;
		string s;
		set<char>::iterator it;
		while(cin >> s && s[0]!='*') {
			v.insert(s[1]);
			v.insert(s[3]);
			edges++;
		}
		cin >> s;
		for(int i=0;i<s.size();i+=2) {
			it = v.find(s[i]);
			if(it == v.end()) acorn++;
			nodes++;
		}
		cout << "There are " << (nodes - edges) - acorn << " tree(s) and " << acorn << " acorn(s).\n";
		t--;
	}

	return 0;
}