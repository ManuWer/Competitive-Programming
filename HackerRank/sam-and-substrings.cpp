#include <iostream>
#include <string>

using namespace std;

long long int sumSub(string st) {
	long long int ans=0, num=1;
	for(int i=st.size()-1;i>=0;i--) {
		ans += (num*(i+1)*(st[i]-'0'))%1000000007;
		num = (10*num)%1000000007 +1;
	}
	return ans;
}

int main() {
	string st;
	cin >> st;
	cout << sumSub(st)%1000000007 << endl;
	return 0;
}