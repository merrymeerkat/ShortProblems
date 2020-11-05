#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef vector <int> vi;
vector <vi> AL;
vi visited;
vi previous;
queue <int> q;

int main(){

    int N, M; cin >> N >> M; // N nodes, M edges

    AL.assign(N + 1, vi());
    visited.assign(N + 1, 0);
    previous.assign(N + 1, 0);

    int u, v;
    for (int i = 0; i < M; i++){
        cin >> u >> v;
        AL[u].push_back(v);
        AL[v].push_back(u);
    }

    // Finding shortest path from 1 to N
    q.push(1);
    int vtx;
    visited[1] = 1;

    while (!q.empty()){
        vtx = q.front(); q.pop();
        //visited[vtx] = 1;

        // for all of its neighbours
        for (auto it = AL[vtx].begin(); it != AL[vtx].end(); it++){
            if (!visited[*it]){
                previous[*it] = vtx;
                q.push(*it);
                visited[*it] = 1;
            }
    /*        if (*it == N){
                while (!q.empty())
                    q.pop();
                break;
            }*/
            //q.push(*it);
        }
    }


    // Compute length of shortest path from "previous" array
    int length = 1;
    int dep = N; //departure
    /*if (previous[dep] == 0){
        auto max = max_element(previous.begin(), previous.end());
        dep = *max;
    }*/
    while (previous[dep] != 1){
        length++;
        dep = previous[dep];
    }

    /*for (int i = 0; i <= N; i++)
        cout << previous[i] << " ";
    */

    // If Alice is trying to maximise the number of colour changes that Bob has to
    // make, she will make it so that every other edge in the shortest path has a
    // different colour. That is, the number of colour changes Bob will make
    // will be at best shortest length - 1.
    cout << length - 1 << '\n';

}

