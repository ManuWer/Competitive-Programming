#include <iostream>
#include <string>
using namespace std;

int main () {

    int t;
    cin >> t;
    int ct = 1;

    while (t>0) {

        string x;
        int n;
        
        cin >> n;
        cin >> x;

        cout << ct << " ";

        for (int i=0; i<x.size(); i++)
            if (i!=n-1) cout << x[i];
        
        cout << endl;

        ct++;
        t--;
    }

    return 0;
}
