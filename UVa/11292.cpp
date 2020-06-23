#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;

	while((cin >> n >> m) && (n!=0 || m!=0)) {

		vector<int> heads(n);
		vector<int> knights(m);
		int c = 0;
		bool doomed = false;

		for(int i=0;i<n;i++)
			cin >> heads[i];
		for(int i=0;i<m;i++)
			cin >> knights[i];

		if(m<n) {
			cout << "Loowater is doomed!" << endl;
			continue;
		}

		sort(heads.begin(),heads.end());
		sort(knights.begin(),knights.end());

		vector<int>::iterator it = heads.begin();
		vector<int>::iterator kt = knights.begin();

		while(it!=heads.end()) {
			if(kt==knights.end()) {
				cout << "Loowater is doomed!" << endl;
				doomed = true;
				break;
			}
			if(*it <= *kt) {
				c+= *kt;
				it++;
				kt++;
			}
			else kt++;
		}

		if(!doomed)
			cout << c << endl;
	}

	return 0;
}