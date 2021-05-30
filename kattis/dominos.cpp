#include <iostream>
#include <queue>

using namespace std;

void dfs(int u, vector<vector<int> > &AL, vector<int> &vis){
    vis[u] = 1;
    for (auto n : AL[u]){
        if (vis[n]) continue;
        dfs(n, AL, vis);
    }
}

int main(){

    int TC; cin >> TC;
    while(TC--){
        int V, E; cin >> V >> E;
        vector <vector<int> > AL; AL.assign(V, vector<int>());
        vector<int> incEdges; incEdges.assign(V, 0);
        vector<int> vis; vis.assign(V, 0);
        int u, v;
        while(E--){
            cin >> u >> v;
            AL[u-1].push_back(v-1);
            incEdges[v-1]++;
        }

        // Do toposort first
        vector <int> order;
        queue <int> q;
        for (int i = 0; i < V; i++){
            if (incEdges[i] == 0)
                q.push(i);
        }
        while(!q.empty()){    
            u = q.front(); q.pop();
            order.push_back(u);
            for (auto neighbour : AL[u]){
                //cout << "neighb: " << neighbour << " ";
                if (incEdges[neighbour] == 0) continue;
                --incEdges[neighbour];
                if (incEdges[neighbour] == 0){
                    //cout << "pushing back " << neighbour << endl;
                    q.push(neighbour);
                }
            }
        }

        int cc = 0;
        
        for (auto node : order){
            if (!vis[node]){
                cc++;
                dfs(node, AL, vis);
            }
        }

        // Now, visit remaining nodes (closed cycles)
        for (int node = 0; node < V; node++){
            if (!vis[node]){
                dfs(node, AL, vis);
                cc++;
            }
        }

        cout << cc << '\n';
    }
}
