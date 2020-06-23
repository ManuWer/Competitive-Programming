#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main () {

	int n;
	cin >> n;

	while (n!=0) {
		while (1) {

			stack<int> s;
			vector<int> v(n);
			int j = 1;
			bool end = false;

			for (int i=0; i<n; i++) {
				cin >> v[i];
				if (v[i]==0) {
					end = true;
					break;
				}	
				if (s.empty())	{
					s.push(j);
					j++;
				}
				while (s.top()!=v[i] && j<=n) {
					s.push(j);
					j++;
				}
				if (s.top()==v[i]) s.pop();
			}
			
			if (end) break;

			if (s.empty()) cout << "Yes" << endl;	
			else cout << "No" << endl;
		}

		cout << endl;
		cin >> n;
	}

	return 0;
}