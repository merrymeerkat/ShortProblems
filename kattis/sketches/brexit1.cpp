#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

typedef vector<int> vi;
vector<vi> AL;
vi visited;

int main(){

    int C, P, X, L;
    cin >> C >> P >> X >> L;

    int u, v;
    AL.assign(C + 1, vi());
    visited.assign(C + 1, 0);
    for (int i = 0; i < P; i++){
        cin >> u >> v;
        AL[u].push_back(v);
        AL[v].push_back(u);
    }

    // L leaves
    set <int> removed;
    removed.insert(L);
    queue <int> at_risk;
    visited[L] = 1;

    for (auto it = AL[L].begin(); it != AL[L].end(); it++){
        at_risk.push(*it);
    }
   
    int current;
    float neighb, leaving_neighb;
    while (!at_risk.empty()){
        current = at_risk.front();
    
        neighb = 0; leaving_neighb = 0;
        for (auto it = AL[current].begin(); it != AL[current].end(); it++){
            if (!visited[*it])
                at_risk.push(*it);
            neighb++;
            if (removed.find(*it) != removed.end()){
                leaving_neighb++;
            visited[*it] = 1; //checkkk
            }
        }
        if (leaving_neighb >= (neighb / 2)){
            removed.insert(current);
        }
        visited[current] = 1;
        at_risk.pop();
    }


    if (removed.find(X) != removed.end()){
        cout << "leave\n";
    }
    else {
        cout << "stay\n";
    }
}
