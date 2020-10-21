#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
vector<vi> AL;
vi visited;
int TC, u, v, n, e;

void DFS(int u){
    visited.at(u) = 1;
    for (auto i : AL[u]){
        if (!visited[i])
            DFS(i);
    }
}

int main(){
    cin >> TC;
    while (TC--){
        cin >> n >> e;
        AL.assign(n, vi());
        visited.assign(n, 0);
        for (int i = 0; i < e; i++){
            cin >> u >> v;
            AL[u].push_back(v);
            AL[v].push_back(u);
        }

        // Number of connected components
        int CC = 0;
        for (int i = 0; i < n; i++){
            if (!visited[i]){
                DFS(i);
                CC++;
            }
        }
        cout << CC - 1 << '\n';
    }
}
