#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;

int main() {
    
    string temp;
    string a;
    vector<string> p;

    while(getline(cin,temp) && temp!="*") {
        p.clear();
        bool tautograma = true;
        replace(temp.begin(),temp.end(),' ','\n');
        stringstream ss(temp);
        while(getline(ss,a))
            p.push_back(a);
    
        for (int i=0;i<p.size();i++)
            transform(p[i].begin(), p[i].end(), p[i].begin(), [](unsigned char c) -> unsigned char { return toupper(c); });
        
        for (int i=0;i<p.size()-1;i++)
            if (p[i][0]!=p[i+1][0]) tautograma = false;
        
        if (tautograma) cout << "Y" << endl;
        else cout << "N" << endl;

    }

    return 0;
}