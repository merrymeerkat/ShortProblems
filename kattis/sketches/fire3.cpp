#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

string board[1010];

typedef pair<int,int> ii;
vector <ii> fire;
map<ii, ii> parent;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int main(){

    int R, C; cin >> R >> C;

    for (int r = 0; r < R; r++){
        cin >> board[r];
    }

    // get fire and joe locations
    ii joe;
    for (int r = 0; r < R; r++){
        for (int c = 0; c < C; c++){
            parent[{r,c}] = ii(-1,-1);
            if (board[r][c] == 'J'){
                joe.first = r; joe.second = c;
            }
            else if (board[r][c] == 'F')
                fire.push_back({r, c});
        }
    }

    queue <pair <int, ii>> q; // 1 = joe, 0 = fire, ii is the position
    for (auto [r, c]: fire){
        q.push({0, {r,c}});
        board[r][c] = '#';
    }
    q.push({1, joe});

    bool reached = false;
    ii end;
    int r, c, nr, nc;
    //int last_seen = 0;
    //int counter = 0;
    while (!q.empty()){
        auto [t, p] = q.front(); q.pop();
        r = p.first; c = p.second;
        for (int i = 0; i < 4; i++){
            nr = r + dr[i];
            nc = c + dc[i];
            if (nr < 0 || nc < 0) continue;
            if (nr >= R || nc >= C) continue;
            if (board[nr][nc] == '#') continue;
            if (board[nr][nc] == 'J') continue;
            if (board[nr][nc] == 'F') continue;
      /*      if (t != last_seen){
                counter++;
            }
            last_seen = t;*/
           
            if (parent[{nr, nc}].first == r && parent[{nr, nc}].second == c) continue;
            if (t && board[r][c] == 'P') continue;
            if (t){
                board[nr][nc] = 'J';
                parent[{nr, nc}] = {r, c};
                if (nr == 0 || nc == 0 || nr == R-1 || nc == C-1){
                    //cout << counter << '\n';
                    //return 0;
                    reached = true;
                    end.first = nr; end.second = nc;
                    break;
                }
            }
            else
                board[nr][nc] = 'F';
            q.push({t, {nr, nc}});
        }
        if (t)
            board[r][c] = 'P'; // P is a past location of Joe. fire can come here, but joe can't
    }

    if (reached){
        // trace back path
        ii from = end;
        //cout << from.first << " " << from.second << endl;
        //cout << parent[from].first << " " << parent[from].second << endl;

        int counter = 1;
        while (from != joe){
            //cout << from.first << " " << from.second << endl;
            from = parent[from];
            counter++;
        }
        cout << counter << '\n';
        return 0;
    }

    cout << "IMPOSSIBLE" << '\n';

    return 0;
}
