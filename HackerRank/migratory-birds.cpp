#include <iostream>
using namespace std;

int main () {

    int n;
    cin >> n;

    int v[n];
    int type[5] = {0};
    for (int i=0; i<n; i++)
        cin >> v[i];

    for (int i=0; i<n; i++)
        type[v[i]-1]++;

    int maior = type[0];
    int indice = 1;
        
    for (int i=1; i<5; i++) {
        if (type[i]>maior) {
            maior = type[i];
            indice = i+1;
        }
    }
    
    cout << indice << endl;
    
    return 0;
}