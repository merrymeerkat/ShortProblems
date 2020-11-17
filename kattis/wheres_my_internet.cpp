#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

typedef vector <int> vi;
vector <vi> AL;
vi visited;

void dfs(int u){
    visited[u] = 1;
    for (auto v : AL[u]){
        if (!visited[v])
            dfs(v);
    }
}

int main(){

    // get number of houses and cables
    int N, M; cin >> N >> M; 

    AL.assign(N, vi());
    visited.assign(N, 0);

    int u, v;
    while (M--){
        cin >> u >> v;
        AL[u-1].push_back(v-1);
        AL[v-1].push_back(u-1);
    }

    dfs(0); // house 1 already has internet

    if (accumulate(visited.begin(), visited.end(), 0) == N){
        cout << "Connected\n";
        return 0;
    }

    for (int i = 0; i < N; i++){
        if (!visited[i])
            cout << i + 1 << '\n';
    }
    return 0;
}
