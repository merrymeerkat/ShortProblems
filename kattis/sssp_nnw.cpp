// Single source shortest path, non-negative weights
#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int inf = 1e9;
typedef pair <int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
vi dist;
set <ii> nodes;
vector <vii> AL;

int main(){


    int N, M, Q, S; cin >> N >> M >> Q >> S;
    int u, v, w, q, nd; 

    while (N != 0){

        AL.assign(N, vii());
        dist.assign(N, inf);

        while (M--){
            cin >> u >> v >> w;
            AL[u].push_back({v, w});
        }

        // Dijkstra
        dist[S] = 0;
        for (int i = 0; i < N; i++){
            nodes.insert({dist[i], i});
        }

        while (!nodes.empty()){
            auto[d, v] = *nodes.begin();
            nodes.erase(nodes.begin());

            for (auto [n, nw] : AL[v]){
                nd = dist[n];
                if ((d + nw) < nd){
                    dist[n] = d + nw;
                    nodes.erase(nodes.find({nd, n}));
                    nodes.insert({dist[n], n});
                }
            }
        }

        while (Q--){
         cin >> q;
         if (dist[q] == inf)
             cout << "Impossible\n";
         else
             cout << dist[q] << '\n';
        }

        cout << '\n';
        nodes.clear();
        cin >> N >> M >> Q >> S;
    }

    return 0;
}


