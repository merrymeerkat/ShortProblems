#include <iostream>
#include <queue>

using namespace std;

const int inf = 1e9;
typedef pair <int, int> ii;
int drE[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dcE[8] = {-0, 1, 1, 1, 0, -1, -1, -1};
int drF[4] = {-1, 0, 1, 0};
int dcF[4] = {0, 1, 0, -1};

int main(){
    int stepsE, stepsF, R, C;
    cin >> stepsE >> stepsF >> R >> C;

    string grid[R];
    for (int r = 0; r < R; r++)
        cin >> grid[r];

    int timeE[R][C];
    int timeF[R][C];
    
    // get start and end locations
    ii start, goal;
    for (int r = 0; r < R; r++){
        for (int c = 0; c < C; c++){
            timeE[r][c] = inf;
            timeF[r][c] = inf;
            if (grid[r][c] == 'S'){
                start.first = r; start.second = c;
            }
            else if (grid[r][c] == 'G'){
                goal.first = r; goal.second = c;
            }
        }
    }
    queue <pair<ii, int> > q;
    timeE[start.first][start.second] = 0;
    timeF[start.first][start.second] = 0;

    int r, c, nr, nc;
    // Elsa
    q.push({start, 0});
    while (!q.empty()){
        auto [u, d] = q.front(); q.pop();
        r = u.first; c = u.second;
        for (int i = 0; i < 8; i++){
            for (int l = 1; l <= stepsE; l++){
                nr = r + (drE[i] * l);
                nc = c + (dcE[i] * l);
                if (nr < 0 || nc < 0 || nr >= R || nc >= C || timeE[nr][nc] <= d + 1 || grid[nr][nc] == 'B') continue;
                timeE[nr][nc] = d + 1;
                //if (nr == goal.first && nc == goal.second)
                  //  break;
                q.push({{nr,nc}, d + 1});
            
            }
        }
    }
    
    // Father
    q.push({start, 0});
    while (!q.empty()){
        auto [u, d] = q.front(); q.pop();
        r = u.first; c = u.second;
        for (int i = 0; i < 4; i++){
            for (int l = 1; l <= stepsF; l++){
                nr = r + (drF[i] * l);
                nc = c + (dcF[i] * l);
                 if (nr < 0 || nc < 0 || nr >= R || nc >= C || grid[nr][nc] == 'B' || timeF[nr][nc] <= d + 1) continue;
                if (grid[nr][nc] == 'B') break;
                timeF[nr][nc] = d + 1;
                q.push({{nr,nc}, d + 1});
            }
        }
    }

    int e_time = timeE[goal.first][goal.second];
    int f_time = timeF[goal.first][goal.second];

    if (e_time > 1e8 && f_time > 1e8)
        cout << "NO WAY\n";
    else if (e_time == f_time)
        cout << "SUCCESS\n";
    else if (e_time > f_time)
        cout << "NO CHANCE\n";
    else if (e_time < f_time)
        cout << "GO FOR IT\n";
    //cout << e_time << " " << f_time << endl;

    return 0;
}


