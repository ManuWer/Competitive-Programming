#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool havelHakimi(vector<int> &g) {
	int n = g.size();
	sort(g.begin(),g.end());
	if(g[n-1]>=n) return false;

	int big;
	while(true) {
		big = g[n-1];
		if(big==0) return true;
		g.pop_back();
		n--;
		for(int i=n-1;i>n-1-big;i--) {
			if(g[i]==0) return false;
			g[i] = g[i]-1;
		}
		sort(g.begin(),g.end());
	}

	return false;
}

int main() {
	
	int n;
	while(cin >> n) {
		if(n==0) return 0;
		vector<int> g(n);
		
		for(int i=0;i<n;i++)
			cin >> g[i];
		
		if(havelHakimi(g)) cout << "Possible\n";
		else cout << "Not possible\n";
	}

	return 0;
}