#include <iostream>
#include <tuple> 
#include <vector>
#include <set>
#include <cmath>
#include <tuple>
#include <map>
#include <stack>

typedef long long ll;
const ll inf = 1e18;

using namespace std;

ll get_dist(pair<int, int> a, pair<int,int> b){

    ll dist = pow(pow((ll)a.first - b.first, 2) + pow((ll)a.second - b.second, 2),2);

    return dist;
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int num_verts; cin >> num_verts;

    ll adj_matrix[num_verts+2][num_verts+2]; // matrix of distances
    vector <pair<int, int>>  nodes; // vector to store nodes (shaded areas, dormitory, classroom)
    map <pair<int, int>, int> coord_to_idx; // maps coordinate to index (because each shaded area has an index)

    int x, y;
    // Get shaded spots
    for (int i = 0; i < num_verts; ++i){
        cin >> x >> y;
        nodes.push_back({x,y});   // store in a container that keeps insertion order 
        coord_to_idx[{x,y}] = i;
    }

    // Get dorm location
    cin >> x >> y;
    nodes.push_back({x,y});
    coord_to_idx[{x,y}] = num_verts;

    // get school
    cin >> x >> y;
    nodes.push_back({x,y});
    coord_to_idx[{x,y}] = num_verts + 1;

    // store distances
    for (int i = 0; i < num_verts + 2; ++i){
        for (int j = 0; j < num_verts + 2; ++j){
            adj_matrix[i][j] = get_dist(nodes[i], nodes[j]);
        }
    }
    
    // Dijkstra
    set <tuple<int, pair<int, int> > > dist_and_nodes; 
    map <pair<int, int>, ll>  dists; // smallest dist for each node
    vector <int> previous;
    previous.assign(num_verts + 2, -1);

    for (int i = 0; i < num_verts + 2; i++){
        dists[nodes[i]] = inf;
    }

    // Set 0 distance for dorm node
    dists[nodes[num_verts]] = 0;
    //insert dist and nodes
    for (int i = 0; i < num_verts + 2; ++i){
        dist_and_nodes.insert({dists[nodes[i]], nodes[i]});
    }

    while(!dist_and_nodes.empty()){
        auto [d, u] = *dist_and_nodes.begin();
        dist_and_nodes.erase(dist_and_nodes.begin());
        for (auto neighb : nodes){
            if (previous[coord_to_idx[neighb]] == coord_to_idx[u]) continue; 
            if (previous[coord_to_idx[u]] == coord_to_idx[neighb]) continue;
     //       if (neighb.first == nodes[num_verts].first && neighb.second == nodes[num_verts].second) continue;
        //if (neighb.first != u.first && neighb.second != u.second){
                if (d + adj_matrix[coord_to_idx[u]][coord_to_idx[neighb]] < dists[neighb]){
                    dist_and_nodes.erase({dists[neighb], neighb});
                    dists[neighb] = d + adj_matrix[coord_to_idx[u]][coord_to_idx[neighb]];
                    dist_and_nodes.insert({dists[neighb], neighb});
                    previous[coord_to_idx[neighb]] = coord_to_idx[u];
                }
          //  }
        }
    }

    // test
    
    for (auto c : previous){
        cout << c << " ";
    }
    cout << endl;
    // reconstruct path
    int from = previous[num_verts + 1];
    stack <int> shelters;
    while (from != num_verts){
        shelters.push(from);
        from = previous[from];
        //cout << from << endl; //DELTE
    }
    shelters.pop(); // pop num_verts (=dormitory/origin) from stack

    if (shelters.empty()){
        cout << "-\n";
        return 0;
    }

    int shelter;
    while (!shelters.empty()){
        shelter = shelters.top();
        cout << shelter << '\n';
        shelters.pop();
    }

    return 0;
}
    // tests
    /*for (int i = 0; i < num_verts + 2; i++){
        for (int j = 0; j < num_verts + 2; j++){
            cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }    
    for (auto [d, n]: dist_and_nodes){
        cout << n.first << " " << n.second << " :" << d << endl;
    }

    for (auto [c, i] : coord_to_idx){
        cout << c.first << " " << c.second << " :" << i << endl;
    }*/
