#include <iostream>
#include <string>
using namespace std;

int main () {
	
	string comp;
	cin >> comp;

	double duration = 0;
	int nrights = 0;

	while (comp[0]!='*') {
		nrights = 0;

		for (int i=0; i<comp.length(); i++) {

			if (comp[i]=='/') {
				if (duration==1) 
					nrights++;
				duration = 0;
			}
			else {
				if (comp[i]=='W')
					duration++;
				if (comp[i]=='H')
					duration+=0.5;
				if (comp[i]=='Q')
					duration+=0.25;
				if (comp[i]=='E')
					duration+=0.125;
				if (comp[i]=='S')
					duration+=0.0625;
				if (comp[i]=='T')
					duration+=0.03125;
				if (comp[i]=='X')
					duration+=0.015625;
			}
		}

		cout << nrights << endl;

		cin >> comp;
	}

	return 0;
}