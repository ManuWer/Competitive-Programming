#include <iostream>
using namespace std;

int main () {

    int t;
    cin >> t;

    while (t>0) {

        int v[20];
        int ficam[20];
        
        for (int i=0; i<20; i++) 
            cin >> v[i];
                
        for (int i=19; i>0; i--) {
            if (v[i]%2==0) {
                v[i-1]+=(v[i]/2);
                ficam[i] = 0;
            }
            else {
                v[i-1]+=((v[i]-1)/2);
                ficam[i] = 1;
            }
        }

        cout << v[0] << " ";
        cout << ficam[1];
        
        for (int i=2; i<20; i++)
            cout << " " << ficam[i];

        cout << endl;

        t--;
    }

    return 0;
}