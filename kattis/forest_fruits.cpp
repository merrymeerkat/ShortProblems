#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector <pair <int, int> > vp;
typedef vector <bool> vb;

vp AL;
vb is_clearance;

int V, E, C, K, M, KM;



int main(){

    cin >> V >> E >> C >> K >> M;
    KM = min(K, M);

    AL.assign(V, {0,0});
    is_clearance.assign(V, false);

    int u, v, w;
    while (E--){
        cin >> u >> v >> w;
        AL[u - 1] = {v - 1, w};
        //AL[v - 1] = {u - 1, w}; // not  needed
    }

    for (int i = 0; i < C; i++){
        cin >> u;
        is_clearance[u - 1] = true;
    }
    
    /*for (int i = 0; i < V; i++)
        cout << is_clearance[i];*/

    if (KM > C){
        cout << -1 << '\n';
        return 0;
    }
    
    int node = 0; 
    
    int clearances = 0;
    if (is_clearance[0])
        clearances++;
    
    int weight, dist; dist = 0;
    while (1){

        weight = AL[node].second;
        node = AL[node].first;
        //cout << "node is " << node + 1 << '\n';
        dist += weight;
        if (is_clearance[node]){
            //cout << "node " << node + 1 << " is cle, weight is " << weight << endl;
            //KM--;
            clearances++;
        } 
        if (clearances == KM)
            break;
    }

    cout <<  2 * dist << '\n';
    return 0;
}

// sketches
/*if (M > C){
        if (C < K){
            cout << -1 << '\n';
            return 0;
        }
    }*/


