#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <sstream>
#include <set>
#include <iomanip>

using namespace std;

struct Coord{
    int x;
    int y;
};

class Compare{
    public:
        bool operator() (const Coord a, Coord b) const {
            if (a.x == b.x)
                return (a.y < b.y);
            else
                return (a.x < b.x);
        }
};

class Compare2{
    public: 
        bool operator() (const pair<float, Coord> a, const pair<float, Coord> b) const {
            if (a.first == b.first){
                if ((a.second).x == (b.second).x)
                    return ((a.second).y < (b.second).y);
                else
                    return ((a.second).x < (b.second).x);
            }
            else {
                return a.first < b.first;
            }
        }
};

typedef pair<Coord, float> cf;
typedef pair<int, int> ii;
typedef vector<ii> vii;
vector <Coord> nodes;
typedef vector<cf> vcf;
map <Coord, vcf, Compare > AL;
map <Coord, float, Compare> dist;
const float inf = 10e7;
set <pair<float, Coord>, Compare2> dist_and_node;


// Smallest distance between two points (Pythagoras)
float get_dist(Coord a, Coord b){
    float dist = sqrt((float)pow((a.x - b.x),2) + pow(a.y - b.y, 2));
    return dist/1000;
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    Coord home, t; // home and school (target)
    cin >> home.x >> home.y >> t.x >> t.y;
    nodes.push_back(home); nodes.push_back(t);
    dist[home] = 0; dist[t] = inf;

    Coord prev, curr;
    
    int a, b;
    prev = home;
    int x; 
    float dista;
    bool first_station = true;
    while (1){
    //while(scanf( "%d %d", &a, &b) != EOF){
        x = scanf( "%d %d", &a, &b);
        if (x != 2) break;
        
        if (feof(stdin)) break;
        
        if (a == -1){
            first_station = true;
            continue;
        }
        curr.x = a; curr.y = b;
        dist[curr] = inf;
        AL[curr] = vcf();
        nodes.push_back(curr);
        
        if (!first_station){
            dista = (3.0/2) * get_dist(curr, prev);
            AL[prev].push_back({curr,dista});
            AL[curr].push_back({prev,dista});
        } 
        
        first_station = false;
        prev = curr;
    }

    // Strongly connected graph
    for (int i = 0; i < nodes.size(); i++){
        for (int j = 0; j < nodes.size(); j++){
            if (i != j)
                AL[nodes[i]].push_back({nodes[j],  6 * get_dist(nodes[i], nodes[j])});
                AL[nodes[j]].push_back({nodes[i],  6 * get_dist(nodes[i], nodes[j])});
        }
    }

    // distances
    dist[home] = 0;
  
    Coord this_node;
    for (auto [x, y] : nodes){
        this_node.x = x; this_node.y = y;
        dist_and_node.insert({dist[this_node], this_node});
    }

    // Dijkstra
    
    while (!dist_and_node.empty()){
        auto [d, node] = *dist_and_node.begin();
        dist_and_node.erase(dist_and_node.begin());
        
        
        // neighbour node = n_node
        for (auto [n_node, n_weight] : AL[node]){
            if (d + n_weight < dist[n_node]){
                dist_and_node.erase(dist_and_node.find({dist[n_node], n_node}));
                dist[n_node] = d + n_weight;
                dist_and_node.insert({d + n_weight, n_node});
            }
        }

    }

    int answ = round(dist[t]);
    printf("%d\n", answ);
    //cout << answ << endl;
    //cout << 21 << endl;
    //cout << dist[t];
    //cout << (int)round(dist[t]) << endl;
    //cout << dist[t] << endl;
    //printf("%d\n", (int)round(dist[t]));
}
