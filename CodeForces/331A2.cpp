#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

vector<long long> sub(300010);

void pdSub(const vector<long long> &v, int n) {

	sub[0] = 0;

	for(int i=1;i<n+1;i++)
		sub[i] = max(sub[i-1]+v[i-1], sub[i-1]);

	return;
}

int main() {
		
	int n;
	cin >> n;

	vector<long long> v(n);
	map<int,vector<int> > m;
	vector<int> remove;

	long long maior = -10e17, soma;
	int x,y;
	sub[0] = 0;
	for(int i=0;i<n;i++) {
		cin >> v[i];
		m[v[i]].push_back(i+1); // indice + 1 pois sub eh preenchido a partir de 1
	}

	pdSub(v,n);

	for(auto i=m.begin();i!=m.end();i++) {
		int s = i->second.size();
		int appeal = i->first;
		if(s>1) {
			soma = sub[i->second[s-1]] - sub[i->second[0]-1];	
			if(appeal<0) // se for neg a pd nao vai ter somado
				soma += appeal*2;
			if(soma > maior) {
				maior = soma;
				x = i->second[0]-1;
				y = i->second[s-1]-1;
			}
		}
	}
	
	for(int i=0;i<x;i++)
		remove.push_back(i);

	for(int i=x+1;i<y;i++)
		if(v[i]<0) remove.push_back(i);

	for(int i=y+1;i<n;i++)
		remove.push_back(i);

	cout << maior << " " << remove.size() << endl;

	for(int i=0;i<remove.size();i++)
		cout << remove[i]+1 << " ";

	cout << endl;

	return 0;
}