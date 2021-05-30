#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> order;

void dfs(int u, vector<vector<int> > &AL, vector<int> &vis){
    vis[u] = 1;
    for (auto n : AL[u]){
        if (vis[n]) continue;
        dfs(n, AL, vis);
    }
}


void dfs_topo(int u, vector<vector<int> > &AL, vector<int> &vis, vector <int> &order){
    if (vis[u]) return;
    vis[u] = 1;
    for (auto n : AL[u]){
        if (vis[n]) continue;
        dfs_topo(n, AL, vis, order);
    }
    order.push_back(u);
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int TC; cin >> TC;
    while(TC--){
        int V, E; cin >> V >> E;
        order.clear();
        vector <vector<int> > AL; AL.assign(V, vector<int>());
        vector<int> incEdges; incEdges.assign(V, 0);
        vector<int> vis; vis.assign(V, 0);
        int u, v;
        while(E--){
            cin >> u >> v;
            AL[u-1].push_back(v-1);
            incEdges[v-1]++;
        }

        // Toposort using DFS
        for (int i = 0; i < V; i++){
            dfs_topo(i, AL, vis, order);
        }
        reverse(order.begin(), order.end());
        //for (auto c: order)
        //    cout << c + 1 << " ";

        
        // dfs to count connected components
        vis.assign(V,0);
        int cc = 0;
        for (auto i : order){
            if (vis[i]) continue;
            cc++;
            dfs(i, AL, vis);
        }
        cout << cc << '\n';
    }
}
