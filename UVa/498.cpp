#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	string cs, xs;
	vector<int> c;
	vector<int> x;
	int aux;

 	while(getline(cin,cs) && cs.size()!=0) {
		c.clear();
		x.clear();
		replace(cs.begin(), cs.end(), ' ', '\n');
		stringstream ss(cs);
		while(ss >> aux)
			c.push_back(aux);
		getline(cin,xs);
		replace(xs.begin(), xs.end(), '\"', '\n');
		stringstream sst(xs);
		while(sst >> aux)
			x.push_back(aux);
		//fim de input
		int sum = 0;
		int j = 0;
		
		for(int i=0;i<x.size();i++) {
			sum = 0;
			j = 0;
			for(int k=c.size()-1;k>=0;k--) {
				sum += c[k]*pow(x[i],j);
				j++;
			}
			if(i==0) cout << sum;
			else cout << " " << sum;
		}
		cout << endl;
	}

	return 0;
}