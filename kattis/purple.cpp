#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
const int inf = 1e9;

vector <vi> AL;
vi dist;
set <ii> nodes;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N, M; cin >> N >> M;

    AL.assign(N + 1, vi());
    dist.assign(N + 1, inf);

    int u, v;
    while (M--){
        cin >> u >> v;
        AL[u].push_back(v);
        AL[v].push_back(u);
    }

    nodes.insert({0, 1});
    dist[1] = 0;
    /*for (int i = 1; i <= N; i++){
        nodes.insert({dist[i], i});
    }*/
    int n_dis;
    while (!nodes.empty()){
        auto [dis, vtx] = *nodes.begin();
        nodes.erase(nodes.begin());

        /*cout << "nodes in set: ";
        for (auto [d, v] : nodes){
            cout << v << ": " << d << endl;
        }*/
        for (auto n : AL[vtx]){
            n_dis = dist[n];
            if (dis+1 < n_dis){ 
                dist[n] = dis+1;
                //nodes.erase(nodes.find({n_dis, n}));
                nodes.insert({dis+1, n});
            }
        }
    }

    if (dist[N] == inf)
        cout << 0 <<'\n';
    else
        cout << dist[N] - 1 << '\n';

    return 0;
}
