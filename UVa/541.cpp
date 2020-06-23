#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	
	while(cin >> n && n!=0) {
		int m[n][n];
		int soma = 0;
		vector<int> lin, col;

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin >> m[i][j];

		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++)
				soma+=m[i][j];
			if(soma%2!=0) lin.push_back(i);
			soma=0;
		}

		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++)
				soma+=m[j][i];
			if(soma%2!=0) col.push_back(i);
			soma=0;
		}

		if(lin.empty() && col.empty()) cout << "OK\n";
		else if(lin.size()==1 && col.size()==1)
				cout << "Change bit (" << lin[0]+1 << "," << col[0]+1 << ")\n";
		else cout << "Corrupt\n";
	}

	return 0;
}