#include <iostream>
#include <set>
using namespace std;

int main() {

    set<int> m;
    int n, aux;
    int p = 0;
    pair< set<int>::iterator,bool > pair;

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> aux;
        pair = m.insert(aux);
        if(!pair.second) {
            p++;
            m.erase(pair.first);
        }
    }

    cout << p << endl;

    return 0;
}