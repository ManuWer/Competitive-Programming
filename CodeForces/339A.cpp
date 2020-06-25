#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {

	string s;
	cin >> s;
	
	sort(s.begin(),s.end());
	
	int i=0;
	while(s[i]=='+') { i++; }
	
	while(i<s.size()-1) {
		cout << s[i] << "+";
		i++;
	}

	cout << s[i] << endl;

	return 0;
}