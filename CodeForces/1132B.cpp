#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int main() {

	int n, c;
	cin >> n;

	vector<int> bars(n);
	long long int cost = 0;

	for(int i=0;i<n;i++) { 
		cin >> bars[i];
		cost += bars[i];
	}

	sort(bars.begin(),bars.end(),greater <>());

	cin >> c;
 	int coupon;

	for(int i=0;i<c;i++) {
		cin >> coupon;
		cout << cost - bars[coupon-1] << endl;
	}

	return 0;
}