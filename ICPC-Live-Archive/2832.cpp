#include <iostream>
#include <string>
using namespace std;

struct Time {
    string nome;
    int sub[4];
    int tempo[4];
    int prob = 0;
    int pen = 0;
};

int main () {

    int n;
    cin >> n;

    Time t[n];

    for (int i=0; i<n; i++) {
        cin >> t[i].nome;
        for (int j=0; j<4; j++) {
        cin >> t[i].sub[j] >> t[i].tempo[j];
            if (t[i].tempo[j]>0) {
                t[i].prob++;
                t[i].pen += t[i].tempo[j] + (20* (t[i].sub[j]-1));
            }
        }
    }
            
    int i,j;
    Time temp;
    for (i=1; i<n; i++) {
        j=i;
        while ((j>0) && (t[j].pen < t[j-1].pen)) {
            temp = t[j];
            t[j] = t[j-1];
            t[j-1] = temp;
            j = j-1;
        }
    }
    
    for (i=1; i<n; i++) {
        j=i;
        while ((j>0) && (t[j].prob > t[j-1].prob)) {
            temp = t[j];
            t[j] = t[j-1];
            t[j-1] = temp;
            j = j-1;
        }
    }

    cout << t[0].nome << " " << t[0].prob << " " << t[0].pen << endl;

    return 0;
}