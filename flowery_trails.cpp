#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <ii> vii;
const int inf = 1e9;

vi dist;
vector <vii> AL;
vector <vi> parent;
vi num_sps;

int get_num_sps(int u){
    if (u == 0)
        return 1;
    if (num_sps[u]) return num_sps[u];
    int ans = 0;
    for (auto p : parent[u])
        ans+=get_num_sps(p);
    num_sps[u] = ans;
    return ans;
}

/*vi flowers;
int get_flower(int u){
    if (u == 0) return 0;
    if (flowers[u]) return floers[u];
    int ans = 0;
    for (auto p : parent[u])
        ans+= (get_flower(p) + dist)
}*/

int main(){

    int P, T; cin >> P >> T;
    AL.assign(P, vii());
    parent.assign(P, vi());
    dist.assign(P, inf);
    num_sps.assign(P,0);
    flowers.assign(P,0);

    int u, v, w;
    while (T--){
        cin >> u >> v >> w;
        AL[u].push_back({v,w});
        AL[v].push_back({u, w});
    }

    dist[0] = 0;
    priority_queue <ii> pq;
    pq.push({0, 0});

    while(!pq.empty()){
        auto [d, node] = pq.top(); pq.pop();
        for (auto [neigh, length] : AL[node]){
            if (dist[neigh] > d + length){
                dist[neigh] = d + length;
                pq.push({d+length, neigh});
                parent[neigh].clear();
                parent[neigh].push_back(node);
            }
            else if (dist[neigh] == d + length)
                parent[neigh].push_back(node);
            
        }
    }

    // calculate number of shortest paths from 0 to P-1
    cout << get_num_sps(P-1) << '\n';
    cout << dist[P-1] << endl;

/*    for (auto vec: parent){
        for (auto p: vec)
            cout << p << ' ';
        cout << endl;
    }

    cout << dist[P-1] << endl;
    for (auto c: parent[P-1]){
        cout << c << endl;
    }*/
}
