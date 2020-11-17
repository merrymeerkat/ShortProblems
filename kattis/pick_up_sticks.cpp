#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

vector <vi> AL;
vi visited; // 0 = unvisited, 1 = explored, 2 = fully visited
vi topo; // to store topological sort

bool cycle = false;
void topo_sort(int u){
    visited[u] = 1; // explored
    for (auto v : AL[u]){
        if (visited[v] == 1){
            cycle = true;
            return;
        }
        else if (!visited[v]){
            topo_sort(v);
        }
    }
    topo.push_back(u);
    visited[u] = 2;
}

int main(){

    int n, m; cin >> n >> m;

    AL.assign(n, vi());
    visited.assign(n, 0);

    int u, v;
    while(m--){
        cin >> u >> v;
        AL[u-1].push_back(v-1);
    }

    for (int node = 0; node < n; ++node){
        if (!visited[node])
            topo_sort(node);
    }

    if (cycle){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    reverse(topo.begin(), topo.end());
    
    for (auto u: topo)
        cout << u + 1 << '\n';
    
    return 0;
}
