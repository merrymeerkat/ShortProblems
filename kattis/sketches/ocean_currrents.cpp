#include <iostream>
#include <vector>
#include <deque>
#include <map>

using namespace std;

typedef pair<int,int> ii;
map <ii, int> parent;
map <ii, int> dist;
string grid[1010];

int R, C;
int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(){

    cin >> R >> C;
    for (int r = 0; r < R; r++)
        cin >> grid[r];

    int Q; cin >> Q;
    int sr, sc, tr, tc;
    deque <pair<ii, int> > deq;
    while (Q--){
        cin >> sr >> sc >> tr >> tc;
        ii source = ii(sr - 1, sc - 1);
        ii target = ii(tr - 1, tc - 1);

        dist.clear();
        dist[source] = 0;
        deq.push_back({source, 0});
        //cout << "THIS" << endl;
        int r, c, nr, nc, num;
        ii n;
        while (!deq.empty()){
            auto [u, d] = deq.front(); deq.pop_front();
            r = u.first; c = u.second;
            for (int i = 0; i < 8; i++){
                //cout << i << endl;
                nr = r + dr[i]; nc = c + dc[i];
                //cout << "nr is " << nr << " and nc is " << nc;
                //cout << "dist " << dist[{nr, nc}] << endl;
                if (dist.find({nr, nc}) != dist.end())  continue;  // has already been visited
                if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
                num = grid[r][c] - '0';
                //cout << "num " << num << endl;
                if (i == num){
                  //  cout << 'Y' << endl;
                    dist[{nr, nc}] = d;
                    deq.push_front({{nr, nc}, d});
                }
                else{
                    dist[{nr, nc}] = d + 1;
                    deq.push_back({{nr, nc}, d + 1});
                }
            }
        }

        cout << dist[target] << '\n';
    }
}
