#include <iostream>
using namespace std;

int main () {

   int n, d;
   cin >> n >> d;

   while (n!=0 || d!=0) {

        int lista[n];
        int alumni[n] = {0};

        bool yes = false;

        for (int i=0; i<d; i++)
            for (int j=0; j<n; j++) {
                cin >> lista[j];
                if (lista[j])
                    alumni[j]++;
            }       

        for (int i=0; i<n; i++)
            if (alumni[i]==d)
                yes = true;

        if (yes) cout << "yes" << endl;
        else cout << "no" << endl;

        cin >> n >> d;
   }

   return 0;
}