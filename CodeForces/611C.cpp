#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<long long> > s(510, vector<long long>(510,0));

void tabela(const vector<vector<char> > &grid, int h, int w) {
	for(int i=1;i<=h;i++) {
		for(int j=1;j<=w;j++) {
			s[i][j] = s[i][j-1] + s[i-1][j] - s[i-1][j-1];
			s[i][j] += grid[i][j-1]=='.' && grid[i][j]=='.';
			s[i][j] += grid[i-1][j]=='.' && grid[i][j]=='.';
		}
	}
}

int main() {

	int h,w;
	cin >> h >> w;
	cin.ignore();

	vector<vector<char> > grid(h+1,vector<char>(w+1,'#'));

	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++) 
			cin >> grid[i][j];

	tabela(grid,h,w);
		
	int q;
	cin >> q;

	int r1,c1,r2,c2;
	for(int i=0;i<q;i++) {
		cin >> r1 >> c1 >> r2 >> c2;
		int res = s[r2][c2];
		int l = r1-1;
		int c = c1-1;
		res -= s[l][c2];
		res -= s[r2][c];
		res += s[l][c];

		for(int j=c1;j<=c2;j++)
			if(grid[l][j]=='.' && grid[l+1][j]=='.')
				res--;
		for(int j=r1;j<=r2;j++) 
			if(grid[j][c]=='.' && grid[j][c+1]=='.')
				res--;

		cout << res << endl;
	}

	return 0;
}
		