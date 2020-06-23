#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int t;
	cin >> t;

	while(t>0) {
		int n;
		cin >> n;

		vector<int> tam;
		vector<int> temp;
		set<int> machine;
		pair<set<int>::iterator,bool> p;
		vector<int>::iterator it;
		int aux;
		int cont = 0;
		for (int i=0;i<n;i++) {
			cin >> aux;
			p = machine.insert(aux);
			if (p.second) {
				cont++; 
				temp.push_back(aux);
			}
			else {
				tam.push_back(cont);
				machine.clear();
				it = find(temp.begin(),temp.end(),aux);
				it++;
				for(vector<int>::iterator i=it;i!=temp.end();i++)
					machine.insert(*i);
				machine.insert(aux);
				cont = machine.size();
				temp.erase(temp.begin(),it);
				temp.push_back(aux);
			}
		}
		tam.push_back(cont);

		cout << *max_element(tam.begin(),tam.end()) << endl;
		t--;
	}

	return 0;
}