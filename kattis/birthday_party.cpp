#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

enum { UNVISITED = -1 };

typedef vector <int> vi;
vi dfs_num, dfs_low,  previous;
vector <vi> AL;
int counter;
bool bridge;

void find_articulation(int u){
    dfs_num[u] = dfs_low[u] = counter++;
    for (auto &v : AL[u]){
        if (dfs_num[v] == UNVISITED){
            previous[v] = u;

            find_articulation(v);

            if (dfs_low[v] > dfs_num[u]){
                bridge = true;
                break;
            }

             dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if (v != previous[u]){
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }

}

int main(){
    
    int p, c; cin >> p >> c;
    while (p != 0 && c != 0){
        AL.assign(p, vi());
        dfs_num.assign(p, UNVISITED); 
        dfs_low.assign(p, 0);
        previous.assign(p, -1);
        counter = 0;
        
        int u, v;
        while (c--){
            cin >> u >> v;
            AL[u].push_back(v);
            AL[v].push_back(u);
        }

        bridge = false;
        for (int u = 0; u < p; ++u){
            if (dfs_num[u] == UNVISITED){ // i.e. if unvisited
                find_articulation(u);
            }
        }

        if (bridge)
            cout << "Yes\n";
        else
            cout << "No\n";

        cin >> p >> c;
    }
    return 0;
}
