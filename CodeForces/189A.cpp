#include <iostream>
using namespace std;	

int main() {

	int n,a,b,c;
	cin >> n >> a >> b >> c;

	int maior = 0;

	for(int i=0;i<=n/a;i++) {
		for(int j=0;j<=n/b;j++) {
			int k = (n - a*i - b*j) / c;
			if(k<0 || a*i+b*j+c*k != n) continue;
			if(i+j+k > maior) maior = i+j+k;
		}
	}
			
	cout << maior << endl;

	return 0;
}