#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <sstream>
#include <set>

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
const int inf = 10e9;
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
    //prev = home; NO
    
    int a, b;
    prev = home;
    AL[prev] = vcf();
    //while (scanf("%d", &a) != EOF){    
        
      //  scanf("%d", &b);
       
    bool first_station = true;
    while (1){

        scanf( "%d %d", &a, &b);

        if (feof(stdin)) break;
       
        
        if (a == -1){
            prev = home;
            continue;
        }
        cout << prev.x << " " << prev.y << endl;
        curr.x = a; curr.y = b;
        dist[curr] = inf;
        cout << "cur " << curr.x << " " << curr.y << endl;
        AL[curr] = vcf();
        nodes.push_back(curr);
        
        //if(prev.x != home.x && prev.y != home.y){
            AL[prev].push_back({curr, 3/2 * get_dist(curr, prev)});
            AL[curr].push_back({prev, 3/2 * get_dist(curr, prev)});
        //} 
        prev = curr;
        cout << "prev :";
        cout << prev.x << " " << prev.y << endl << endl;
        //AL[curr] = vcf();

    }

    //test
    cout << "lantejoula" << endl;
    for (auto node : nodes){
        cout << node.x << " " << node.y << endl;
        for (auto [nn, dist] : AL[node]){
            cout << node.x << " " << node.y << "neighb: ";
            cout << nn.x << " " << nn.y << ", d =" << dist << endl;
        }
    } 

    // Strongly connected graph
    for (int i = 0; i < nodes.size(); i++){
        for (int j = 0; j < nodes.size(); j++){
            if (i != j)
                cout << nodes[i].x << " "<< nodes[i].y << endl;
                AL[nodes[i]].push_back({nodes[j],  6 * get_dist(nodes[i], nodes[j])});
                //AL[nodes[j]].push_back({nodes[i],  6 * get_dist(nodes[i], nodes[j])});
        }
    }

    // distances
    dist[home] = 0;
  
    cout << "oioi" << endl;
    Coord this_node;
    for (auto [x, y] : nodes){
        this_node.x = x; this_node.y = y;
        cout << x << " " << y << " " << dist[this_node] << endl;
        dist_and_node.insert({dist[this_node], this_node});
    }
    cout << "potato" << endl;

    //test
    /*while (!dist_and_node.empty()){
        auto [d, node] = *dist_and_node.begin();
        cout << "d: " << d << ", coord: " << node.x << " " << node.y;
        cout << endl;
        dist_and_node.erase(dist_and_node.begin());
    }*/

    // Dijkstra
    
    while (!dist_and_node.empty()){
        auto [d, node] = *dist_and_node.begin();
        cout << "size " << dist_and_node.size() << endl;
        cout << d << " : "  <<node.x << " "<< node.y <<endl;

        dist_and_node.erase(dist_and_node.begin());
        
        
        // neighbour node = n_node
        for (auto [n_node, n_weight] : AL[node]){
            if (d + n_weight < dist[n_node]){
                //dist_and_node.erase(dist_and_node.find({dist[n_node], n_node}));
                dist[n_node] = d + n_weight;
                dist_and_node.insert({d + n_weight, n_node});
            }
        }

    }

    this_node.x = 0; this_node.y = 200;
    cout << dist[this_node] << endl;
    cout << "ANSWER: ";
    cout << dist[t] << endl;
    cout << t.x << " " << t.y << endl;
}


// Sketches

    //int hx, hy, tx, ty;
    //cin >> hx >> hy >> tx >> ty;
    //home.x = hx; home.y = hy; t.x = tx; t.y = ty;
    //cout << typeid(prev).name() << endl << typeid(home).name() << endl << typeid(curr).name() << endl;
    //
    /*
    //
    while (getline(cin, input)){    
        if (input == 'EOF')
            break;   

        prev = home;
        
        istringstream iss(input);

        iss >> curr.x >> curr.y;
        while (curr.x != -1){
            nodes.push_back(curr);
            
            if(prev.x != home.x && prev.y != home.y){
                //AL[prev] = vci();
                AL[prev].push_back({curr, 3/2 * get_dist(curr, prev)});
                AL[curr] = vci();
                AL[curr].push_back({prev, 3/2 * get_dist(curr, prev)});
            } 
            prev = curr;
        }
    }

    for (auto [ax, ay] : AL){
        cout << ax << " " << ay << " :\n";
        for (auto [bx, by, c] : AL[ax, ay]){
            cout << bx << " " << by << " " << c << ", ";
        }
    }
    // TEST
    for (auto [x, y] : nodes){
        cout << x << " " << y << endl;
    }*/
