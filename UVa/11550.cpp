#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {

	int t;
	cin >> t;

	while(t>0) {
		int n, m;
		cin >> n >> m;
		vector< vector<int> > incT(m, vector<int>(n));
		set < vector<int> > col;

		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin >> incT[j][i];

		bool ok = true, simple = true;
		int soma = 0;
		pair< set< vector<int> >::iterator,bool > ret;
		for(int j=0;j<m;j++) {
			for(int i=0;i<n;i++)
				soma += incT[j][i];
			if(soma!=2) ok = false;
			soma = 0;
			ret = col.insert(incT[j]);
			if (!ret.second) simple = false;
		}

		if(!ok || !simple) cout << "No\n";
		else cout << "Yes\n";

		t--;
	}

	return 0;
}