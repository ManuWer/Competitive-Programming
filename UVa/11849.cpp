#include <iostream>
#include <vector>
using namespace std;

int main () {
		
	int n, m;

	while ((cin >> n >> m) && (m!=0 || n!=0)) {
		
		vector<int> jack(n);
		vector<int> jill(m);

		for (int i=0;i<n;i++)
			cin >> jack[i];
		
		for (int i=0;i<m;i++)
			cin >> jill[i];
		
		vector<int>::iterator i = jack.begin();
		vector<int>::iterator j = jill.begin();
		int cd = 0;

		while (i!=jack.end() && j!=jill.end()) {		
			if (*i==*j) {
				cd++;
				i++;
				j++;
			}
			else if (*i<*j)	i++;
			else j++;
		}

		cout << cd << endl;
	}

	return 0;
}
