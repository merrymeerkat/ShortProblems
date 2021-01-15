#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int R, C, N;

int board[110][110];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0,1,0,-1};

queue <pair <int, int> > q; // queue of nodes to bfs

int x, y;
int nr, nc;
queue <pair<int, int> >  bfs(){

    pair <int, int> pa;
    queue <pair<int, int> > new_queue; // for the next level (next day)
    while (!q.empty()){
        pa = q.front(); q.pop();
        x = pa.first; y = pa.second;
        for (int i = 0; i < 4; i++){
            nr = x + dr[i];
            nc = y + dc[i];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if (!board[nr][nc]){
                board[nr][nc] = 1;
                new_queue.push({nr, nc});
            }
        }
    }
    return new_queue;
}


int main(){

    cin >> R >> C >> N;


    for (int r = 0; r < R; r++){
        for (int c = 0; c < C; c++){
            board[r][c] = 0;
        }
    }

    int counter = 0;

    int x, y;
    for (int i = 0; i < N; i++){
        cin >> x >> y;
        board[x-1][y-1] = 1;
        q.push({x-1,y-1});
    }

    pair <int, int> this_pair;
    while (!q.empty()){
        q = bfs();
        counter++;
    }

    cout << counter << '\n';
}
