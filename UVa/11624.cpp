#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

set<int> s;

void BFS(vector< vector<char> > &maze, int &i, int &j, vector< vector<bool> > &visit, int n, int m, vector< vector<int> > &ordem, const vector< vector<int> > &ordem2) {
    queue< pair<int,int> > F;
    F.push(make_pair(i,j));
    visit[i][j] = true;
    ordem[i][j] = 0;

    while(!F.empty()) {
        i = F.front().first; j = F.front().second; F.pop();
        if(i==0 || j==0 || i==n-1 || j==m-1) {
            if(ordem[i][j]<ordem2[i][j]) s.insert(ordem[i][j]);
        }
        if(i!=n-1 && !visit[i+1][j] && maze[i+1][j]!='F' && maze[i+1][j]!='#') {
            F.push(make_pair(i+1,j));
            visit[i+1][j] = true;
            ordem[i+1][j] = ordem[i][j]+1;
        }
        if(i!=0 && !visit[i-1][j] && maze[i-1][j]!='F' && maze[i-1][j]!='#') {
            F.push(make_pair(i-1,j));
            visit[i-1][j] = true;
            ordem[i-1][j] = ordem[i][j]+1;
        }
        if(j!=m-1 && !visit[i][j+1] && maze[i][j+1]!='F' && maze[i][j+1]!='#') {
            F.push(make_pair(i,j+1));
            visit[i][j+1] = true;
            ordem[i][j+1] = ordem[i][j]+1;
        }
        if(j!=0 && !visit[i][j-1] && maze[i][j-1]!='F' && maze[i][j-1]!='#') {
            F.push(make_pair(i,j-1));
            visit[i][j-1] = true;
            ordem[i][j-1] = ordem[i][j]+1;
        }
    }
}

void fire_BFS(vector< vector<char> > &maze, queue< pair<int,int> > &fire, vector< vector<bool> > &visit, int n, int m, vector< vector<int> > &ordem) {
    queue< pair<int,int> > F(fire);
    int i, j;
    while(!fire.empty()) {
        i = fire.front().first; j = fire.front().second; fire.pop();
        visit[i][j] = true;
        ordem[i][j] = 0;
    }
    while(!F.empty()) {
        i = F.front().first; j = F.front().second; F.pop();
        if(i!=n-1 && !visit[i+1][j] && maze[i+1][j]!='F' && maze[i+1][j]!='#') {
            F.push(make_pair(i+1,j));
            visit[i+1][j] = true;
            ordem[i+1][j] = ordem[i][j]+1;
        }
        if(i!=0 && !visit[i-1][j] && maze[i-1][j]!='F' && maze[i-1][j]!='#') {
            F.push(make_pair(i-1,j));
            visit[i-1][j] = true;
            ordem[i-1][j] = ordem[i][j]+1;
        }
        if(j!=m-1 && !visit[i][j+1] && maze[i][j+1]!='F' && maze[i][j+1]!='#') {
            F.push(make_pair(i,j+1));
            visit[i][j+1] = true;
            ordem[i][j+1] = ordem[i][j]+1;
        }
        if(j!=0 && !visit[i][j-1] && maze[i][j-1]!='F' && maze[i][j-1]!='#') {
            F.push(make_pair(i,j-1));
            visit[i][j-1] = true;
            ordem[i][j-1] = ordem[i][j]+1;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<char> > maze(n, vector<char> (m));
        int jx, jy;
        queue< pair<int,int> > fire;
        s.clear();

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin >> maze[i][j];
                if(maze[i][j]=='J') {
                    jx = i; jy = j;
                }
                if(maze[i][j]=='F') 
                    fire.push(make_pair(i,j));
            }
        }     

        vector< vector<int> > ordem(n, vector<int>(m,-1));
        vector< vector<int> > ordem2(n, vector<int>(m,1000));
        vector< vector<bool> > visit(n, vector<bool>(m,0));
        vector< vector<bool> > visit2(n, vector<bool>(m,0));

        fire_BFS(maze,fire,visit2,n,m,ordem2);
        BFS(maze,jx,jy,visit,n,m,ordem,ordem2);

        if(!s.empty()) cout << *(s.begin())+1 << endl;
        else cout << "IMPOSSIBLE\n";
    }

    return 0;
}