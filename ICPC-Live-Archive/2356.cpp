#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>
using namespace std;

int main () {

    int t;
    string cmd;
    string temp;

    cin >> t;
    cin.ignore();

    while(t>0) {
    
        string url = "http://www.acm.org/";
        stack<string> back;
        stack<string> next;
        stack<string> now;
        now.push(url);
        getline(cin,temp); //le as linhas em branco

        while (getline(cin,temp) && temp!="QUIT") {
            bool ignore = false;
            replace(temp.begin(),temp.end(),' ','\n');
            stringstream ss(temp);
            getline(ss,cmd);

            if (cmd.compare("BACK")==0) {
                if (!back.empty()) {
                    next.push(now.top());
                    now.push(back.top());
                    back.pop();
                }
                else ignore = true;
            }
            if (cmd.compare("FORWARD")==0) {
                if (!next.empty()) {
                    back.push(now.top());
                    now.push(next.top());
                    next.pop();
                }
                else ignore = true;
            }
            if (cmd.compare("VISIT")==0) {
                getline(ss,url);
                back.push(now.top());
                now.push(url);
                while(!next.empty())
                    next.pop();
            }

            if (ignore) cout << "Ignored" << endl;
            else cout << now.top() << endl;
        }
        
        t--;
        if(t>0) cout << endl;
    }

    return 0;
}