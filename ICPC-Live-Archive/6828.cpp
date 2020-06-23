#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int menor (int a, int b) {
	if (a<b) return a;
	return b;
}

int main () {
	
	int n;

	while (cin >> n) {

		vector<int> p(n);
		int total1 = 0;
		int total2 = 0;
		
		for(int i=0; i<p.size(); i++)
			cin >> p[i];

		sort(p.begin(), p.end());
		
		for(int i=0; i<p.size()-1; i++)
			if (i%2==0)
				total1 += menor(abs(p[i]-p[i+1]), 24-abs(p[i]-p[i+1]));

		total2 += menor(abs(p[0]-p[n-1]), 24-abs(p[0]-p[n-1]));
			
		for(int i=1; i<p.size()-2; i++)
			if (i%2!=0)
				total2 += menor(abs(p[i]-p[i+1]), 24-abs(p[i]-p[i+1]));

		cout << menor(total1, total2) << endl;
	}
	
	return 0;		
}