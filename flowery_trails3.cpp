#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <ii> vii;
const ll inf = 1e12;

vector <ll> dist;
vector <vii> AL;
vector <vii> parent;
vi num_sps;

/*int get_num_sps(int u){
    if (u == 0)
        return 1;
    if (num_sps[u]) return num_sps[u];
    int ans = 0;
    for (auto p : parent[u])
        ans+=get_num_sps(p);
    num_sps[u] = ans;
    return ans;
}*/

vi flowers;
ll get_flower(int u){
    if (u == 0) return 0;
    if (flowers[u]) return flowers[u];
    ll ans = 0;
    set <int> parents;
    for (auto [p, w] : parent[u]){
        ans += (ll)2*w;
        if (parents.find(p) == parents.end())
            ans += get_flower(p);
        parents.insert(p);
    }
    flowers[u] = ans;
    return ans;
}

int main(){

    int P, T; cin >> P >> T;
    AL.assign(P, vii());
    parent.assign(P, vii());
    dist.assign(P, inf);
    num_sps.assign(P,0);
    flowers.assign(P,0);

    int u, v, w;
    while (T--){
        cin >> u >> v >> w;
        if (u == v) continue;
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
                parent[neigh].push_back({node, length});
            }
            else if (dist[neigh] == d + length)
                parent[neigh].push_back({node, length});
        }
    }

    // bfs from P-1 on parent arr
    vi visited;
    visited.assign(P, 0);
    queue <int> q;
    q.push(P-1); visited[P-1] = 1;
    int ans = 0;
    while (!q.empty()){
        u = q.front(); q.pop();
        for (auto [p, d] : parent[u]){
            if (visited[p]) continue;
            q.push(p);
            ans += d;
            visited[p] = 1;
        }
    }
    cout << ans << endl;

    // calculate number of shortest paths from 0 to P-1
//    cout << get_num_sps(P-1) << '\n';
    cout << get_flower(P-1) << endl;
   // cout << dist[P-1] << endl;

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
