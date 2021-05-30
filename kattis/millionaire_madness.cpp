#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int inf = 1e9;
typedef long long ll;
typedef pair <int, int> pii;

int map[1000][1000];
int dist[1000][1000];

struct Compare{
    bool operator()(const pair<int, pii> A, const pair<int, pii> B)const{
        if (A.first == B.first)
            return (A.second.first > B.second.first);
        else
            return (A.first > B.first);
    }
};

int main(){
    
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int R, C; cin >> R >> C;
    for (int r = 0; r < R; r++){
        for (int c = 0; c < C; c++){
            cin >> map[r][c];
            dist[r][c] = inf;
        }
    }
    
    priority_queue <pair<int, pii>, vector<pair<int, pii> >, Compare > pq;

    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,1,0,-1};
    int r, c, nr, nc;

    // Insert first node
    pq.push({0,{0,0}});
    dist[0][0] = 0;
    int new_height;
    while(!pq.empty()){
        auto [d, node] = pq.top(); pq.pop();
        r = node.first;  c = node.second; 
        for (int i = 0; i < 4; i++){
            nr = r + dr[i];
            nc = c + dc[i];
            if (nr >= R || nc >= C || nc < 0 || nr < 0) continue;
            if (map[nr][nc] - map[r][c] < dist[r][c])
                new_height = 0;
            else
                new_height = map[nr][nc] - map[r][c] - dist[r][c];
            if (dist[r][c] + new_height < dist[nr][nc]){
                dist[nr][nc] = dist[r][c] + new_height;
                pq.push({dist[nr][nc], {nr, nc}});
            }
        }
    }
    
    cout << dist[R-1][C-1] << endl;
}
