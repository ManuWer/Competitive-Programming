#include <iostream>
using namespace std;

int main () {

	int n;
	cin >> n;

	while (n!=0) {

		int l, c;
		int aux = 0;
		int i = 1;
		int line = 0;
		int num;

		while (n>aux) {
			aux+=i;
			i+=2;
			line++;
		}
		
		num = (line-1)*(line-1) + 1;

		if (line%2==0) {
			l = line;
			c = 1;
			while (num!=n) {
				if (c<line)
					c++;
				else l--;
				num++;
			}
		}
		if (line%2!=0) {
			l = 1;
			c = line;
			while (num!=n) {
				if (l<line)
					l++;
				else c--;
				num++;
			}
		}

		cout << c << " " << l << endl;

		cin >> n;
	}

	return 0;
}