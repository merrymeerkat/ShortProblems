#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;

unordered_map <string, int> visited;
unordered_map <string, vs> AL;
bool cycle;

void DFS(string u){
    if (cycle) return;
    visited[u] = 1;
    for (auto s: AL[u]){
        if (!visited[s]){
            DFS(s);
        }
        else if (visited[s] == 1){ // explored
            cycle = true;
            break;
        }
    }
    visited[u] = 2; // fully visited
}


int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;

    string u, v;
    int i = 0;
    while (n--){
        cin >> u >> v;        
        AL[u].push_back(v);
    }

    // for each city asked for
    while (cin >> u, !cin.eof()){
       
        // Mark every city as completely unvisited
        for (auto c: AL){
            visited[c.first] = 0;
        }

        cycle = false;
        DFS(u);
        if (cycle)
            cout << u << " safe\n";
        else
            cout << u << " trapped\n";

    }
}
