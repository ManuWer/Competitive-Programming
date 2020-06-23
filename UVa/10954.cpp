#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n;
		
	while(cin >> n && n!=0) {
		priority_queue< int,vector<int>,greater<int> > p;
		vector<int> cost;
		int a,b;
		int soma = 0;

		for(int i=0;i<n;i++) {
			cin >> a;
			p.push(a);
		}
		
		while(p.size()>1) {
			a = p.top(); p.pop();
			b = p.top(); p.pop();
			p.push(a+b);
			cost.push_back(a+b);
		}
		
		for(int i:cost) soma+=i;
		cout << soma << endl;
	}
	
	return 0;
}