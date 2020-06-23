#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

void insertion(string s[], int n) {
    int i,j;
    string temp;
    for (i=1; i<n; i++) {
        j=i;
        while ((j>0) && (s[j].size() < s[j-1].size())) {
            temp = s[j];
            s[j] = s[j-1];
            s[j-1] = temp;
            j = j-1;
        }
    }
}

int main () {

    int n;
    int k;
    int ct = 1;
    
    cin >> n;
    cin >> k;
    
    while (n!=0 && k!=0) {

        string p[n];
        double media = 0.0;
        bool possible = true;

        for (int i=0; i<n; i++)
            cin >> p[i];
        
        insertion(p, n);

        for (int i=0; i<n; i+=k) {
            media = 0;
            for (int j=0; j<k; j++)
                media+=p[i+j].size();
            media/=k;
            for (int j=0; j<k; j++)
                if ((p[i+j].size() - media) > 2)
                    possible = false;
        }
        
        if (ct==1) {
            cout << "Case " << ct << ": ";
            if (possible) cout << "yes" << endl;
            else cout << "no" << endl;
        }
        else {
            cout << endl;
            cout << "Case " << ct << ": ";
            if (possible) cout << "yes" << endl;
            else cout << "no" << endl;
        }
        
        ct++;
        cin >> n;
        cin >> k;

    }

    return 0;
}