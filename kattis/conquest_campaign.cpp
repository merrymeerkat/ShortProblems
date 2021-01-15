#include <iostream>
#include <queue>

using namespace std;

int vis[110][110] = { 0 };

struct Node{
    int r;
    int c;
    int day;
};

int main(){
    int R, C, N;
    cin >> R >> C >> N;
    int x, y;
    queue <Node> q;
    while(N--){
        cin >> x >> y;
        if (vis[x-1][y-1]) continue;
        Node thisNode = {x - 1, y - 1, 1};  
        q.push(thisNode);
        vis[x-1][y-1] = 1;
    }
  
    int nr, nc;
    int day;
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,1,0,-1};
    while (!q.empty()){
        auto [r, c, d] = q.front(); q.pop();
        //cout << "processing " << r << " " << c << " day is " << d << endl;
        for (int i = 0; i < 4; i++){
            nr = r + dr[i];
            nc = c + dc[i];
            if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
            if (vis[nr][nc]) continue;
            vis[nr][nc] = 1;
            Node thisNode = {nr, nc, d + 1};
            q.push(thisNode);
        }
        day = d;
    }
    cout << day << endl;

}





