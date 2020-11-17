#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;
const ll inf = 10e12;
typedef pair <ll, int> lli;
typedef pair <int, int> ii;
typedef vector <ii> vii;
vector <vii> AL; // AL of neighbours and weights
vector <ll> dists;
vector <int> has_fruit;
vector <ll> dists_to_fruit; 
priority_queue <lli, vector<lli>, greater<lli> > pq;

int V, E, C;
ll K, M;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> V >> E >> C >> K >> M;

    ll T = min(K, M);

    AL.assign(V, vii());
    dists.assign(V, inf);
    has_fruit.assign(V, 0);

    int u, v, w;
    for (int i = 0; i < E; i++){
        cin >> u >> v >> w;
        AL[u-1].push_back({v-1,w});
        AL[v-1].push_back({u-1,w});
    }

    // get fruit clearings
    for (int i = 0; i < C; i++){
        cin >> u;
        has_fruit[u-1] = 1;
    }

    // if there are less fruit clearings than min(K, M), we die
    if (C < T){
        cout << "-1" << '\n';
        return 0;
    }

    // insert origin
    pq.push({0,0});
    dists[0] = 0;

    // Dijkstra
    while (!pq.empty()){
        auto [dist, u] = pq.top(); pq.pop();
        dist = (ll) dist;
        if (dist > dists[u]) continue;
        for (auto &[neigh, w] : AL[u]){
            w = (ll) w;
            if (dist + w < dists[neigh]){
                pq.push({dist + w, neigh});
                dists[neigh] = dist + w;
            }
        }
    }

    // get a distance vector for fruit clearings
    for (int i = 0; i < V; i++){
        if (has_fruit[i]){
            if (dists[i] < inf) // if fruit is reachable
                dists_to_fruit.push_back(dists[i]);
        }
    }

    // if there are fewer reachable clearings than min(K, M), we die
    if (dists_to_fruit.size() < T){
        cout << "-1" << '\n';
        return 0;
    }

    sort(dists_to_fruit.begin(), dists_to_fruit.end());

    // Min dist is the Tth smallest distance * 2 (round trip)
    cout << 2 * dists_to_fruit[T - 1] << '\n';
}
