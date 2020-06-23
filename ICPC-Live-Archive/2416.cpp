#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
	string str, aux;
	string a, b;
	string::iterator it, jt;
	long long int menor, dif, score = 0;
	long long int aInt, bInt;
	long long int X,Y;
	vector<int> v(6);

	while(getline(cin,str)) {
		
		if(str.empty()) {	
			cout << "score: " << score << endl; 
			score = 0;
			a.clear();
			b.clear();
			aux.clear();
			continue;
		}

		for(int i=0;i<6;i++)
			v[i] = i;

		if (str.size()!=6) { 
			aux += str;
			str = aux;
			aux.clear();
		}
		
		menor = 101;

		do {
			a = str[v[0]];
			a += str[v[1]];
			aInt = atoi(a.c_str());
			b = str[v[2]];
			b += str[v[3]];
			bInt = atoi(b.c_str());
			dif = abs(100 - (aInt+bInt));

			if(dif < menor) {
				menor = dif;
				X = aInt;
				Y = bInt;
				it = str.begin() + v[4];
				jt = str.begin() + v[5];
			}
				
		} while(next_permutation(v.begin(),v.end()));
		aux += *it;
		aux += *jt;

		cout << setfill('0') << setw(2) << X << "+" << setfill('0') << setw(2) << Y << "=" << X+Y << endl; 
		score+=menor;
			
	}

	cout << "score: " << score << endl; 

	
	return 0;
}