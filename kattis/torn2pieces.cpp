#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <sstream>
#include <stack>

using namespace std;

typedef vector <int> vi;
vector <vi> AL; // adjacency list
map <string, int> name_to_id; // maps station name to an int ID (useful so that we can store neighbours in a normal vector of vector ints (instead of having to create a map <string, vector <string>>, which would be harder to iterate through))
map <int, string> id_to_name; // maps ID back to station name
vi visited; // 0 = unvisited, 1 = visited
vi previous; // to store route

int main(){

    int N; cin >> N;
    AL.assign(100, vi()); //tricky: although there are N pieces of paper, there could be more than N stations
    // that is, some stations appear in the pieces of paper of other stations, but do not have a paper of their own
    visited.assign(100, 0);
    previous.assign(100, -1);
    
    string from, to;
    string line;
    int ID = 0; int from_ID, to_ID;
    cin.ignore();

    // read stations and their connections
    for (int i = 0; i < N; i++){
        getline(cin, line);
        istringstream wordstream(line);
        wordstream >> from;
        if (name_to_id.find(from) == name_to_id.end()){
            name_to_id[from] = ID;
            id_to_name[ID] = from;
            ID++;
        }
        from_ID = name_to_id[from];

        
        while(wordstream >> to){
            if (name_to_id.find(to) == name_to_id.end()){
                name_to_id[to] = ID;
                id_to_name[ID] = to;
                ID++;
            }
            to_ID = name_to_id[to];
            AL[from_ID].push_back(to_ID);
            AL[to_ID].push_back(from_ID);
        }
    }

    // read source and destination
    string source, dest;
    cin >> source >> dest;
    int source_id = name_to_id[source]; int dest_id = name_to_id[dest];
    
    queue <int> nodes;
    nodes.push(source_id);
    visited[source_id] = 1;
    
    // BFS
    int u;
    while (!nodes.empty()){
        u = nodes.front(); nodes.pop();
        for (auto neighb : AL[u]){
            if (visited[neighb]) continue;
            visited[neighb] = 1;
            previous[neighb] = u;
            nodes.push(neighb);
        }
    }

    if (previous[dest_id] == -1){
        cout << "no route found\n";
        return 0;
    }

    stack <int> route;
    route.push(dest_id);
    int node = previous[dest_id];
    while (node != source_id){
        route.push(node);
        node = previous[node];
    }
    route.push(source_id);

    // Print route
    string station;
    while (!route.empty()){
        station = id_to_name[route.top()]; route.pop();
        cout << station << " ";
    }
    cout << '\n';

    return 0;
}
