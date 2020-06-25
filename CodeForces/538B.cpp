#include <iostream>
#include <vector>
using namespace std;	

int main() {

	int n;
	cin >> n;
		
	vector<int> v;
	int d;
	int maior = 0;

	while(n>0) {
		d = n%10; n/=10;
		if(d>maior) maior = d;
		v.push_back(d);
	}

	vector<long long> res(maior,0);
	d = 1;
	
	for(int i=0;i<v.size();i++) {
		for(int j=0;j<v[i];j++)
			res[j] += d;
		d *= 10;
	}
			
	cout << maior << endl;
	for(int i=0;i<maior;i++)
		cout << res[i] << " ";

	cout << endl;

	return 0;
}