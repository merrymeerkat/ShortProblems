#include <iostream>
#include <queue>
#include <vector>

using namespace std;

string board[1010];

typedef pair<int,int> ii;
vector <ii> fire;
//const int inf = 1e9;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int R, C;

queue <pair <ii, int> > fire_q;
int grid[1010][1010];

bool is_valid(int r, int c){
    if (r >= R || c >= C || r < 0 || c < 0) return false;
    if (board[r][c] == '#') return false;
    return true;
}

// Run multiple-source BFS to get the earliest time 
// at which fire will reach each location in the board
void pre_process_board(){
    for (auto f : fire)
        fire_q.push({f, 0}); // time 0

    pair<ii,int> curr_f;
    int r, c, nr, nc, time;
    while (!fire_q.empty()){
        curr_f = fire_q.front(); fire_q.pop(); 
        r = curr_f.first.first; c = curr_f.first.second;
        time = curr_f.second;
        for (int i = 0; i < 4; i++){
            nr = r + dr[i];
            nc = c + dc[i];
            if (!is_valid(nr, nc)) continue;
            if (grid[nr][nc] != -1) continue;
            fire_q.push({{nr, nc}, time + 1});
            grid[nr][nc] = time + 1;
        }
    }
}


int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;

    for (int r = 0; r < R; r++){
        cin >> board[r];
    }

    // get fire and joe locations
    ii joe;
    for (int r = 0; r < R; r++){
        for (int c = 0; c < C; c++){
            grid[r][c] = -1;
            if (board[r][c] == 'J'){
                joe.first = r; joe.second = c;
                if (r == 0 || r == R- 1 || c == 0 || c == C -1){
                    cout << 1 << '\n';
                    return 0;
                }
            }
            else if (board[r][c] == 'F'){
                grid[r][c] = 0;
                fire.push_back({r,c});
            }
        }
    }
    
    if (!fire.empty()) pre_process_board();

    queue <pair<ii, int>> joe_q;
    joe_q.push({joe, 0});
    pair<ii,int> curr_joe; int r, c, nr, nc, time;
    while (!joe_q.empty()){
        curr_joe = joe_q.front(); joe_q.pop();
        r = curr_joe.first.first; c = curr_joe.first.second;
        time = curr_joe.second;
        for (int i = 0; i < 4; i++){
            nr = r + dr[i]; nc = c + dc[i];
            if (!is_valid(nr, nc)) continue; // if neighbour is '#' (wall) or out of bounds, continue
            if (grid[nr][nc] != -1 && time + 1 >= grid[nr][nc]) continue; // if fire has already reached that location, continue
            if (board[nr][nc] == 'J') continue;
            if (nr == R -1 || nc == C-1 || nr == 0 || nc == 0){
                cout << time + 2 << '\n';
                return 0;
            }
            board[nr][nc] = 'J';
            joe_q.push({{nr, nc}, time + 1});
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}

